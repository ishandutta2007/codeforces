#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),q=read();
char s[505][505];
char col[515][515][515];
int c[515][515];
inline int id(char c){
	if(c=='R')	return 1;
	if(c=='G')	return 2;
	if(c=='Y')	return 3;
	return 4;
}
int st[515][515][11][11];
inline int query(int x1,int y1,int x2,int y2){
	if(x1<=0||y1<=0)	return 0; 
	if(x2>=n||y2>=m)	return 0;
	if(x1>x2||y1>y2)	return 0;
	int k1=log2(x2-x1+1),k2=log2(y2-y1+1);
//	cout<<st[x1][y1][k1][k2]<<" "<<st[x1][y2-(1<<k2)+1][k1][k2]<<" "<<st[x2-(1<<k1)+1][y1][k1][k2]<<" "<<st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]<<endl;
	return max(max(st[x1][y1][k1][k2],st[x1][y2-(1<<k2)+1][k1][k2]),max(st[x2-(1<<k1)+1][y1][k1][k2],st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]));
}
signed main(){
	fz(i,1,n)	cin>>s[i]+1;
	fz(i,1,n){
		fd(l,m,1)	fz(r,l,m){
			if(l==r)	col[i][l][r]=id(s[i][l]);
			else{
				int mid=(l+r)>>1;
				if(col[i][l][mid]&&col[i][mid+1][r]&&col[i][l][mid]==col[i][mid+1][r])	col[i][l][r]=col[i][l][mid];
//				cout<<i<<" "<<l<<" "<<r<<" "<<col[i][l][r]<<endl;
			}
		}
	}
	fz(i,1,n-1)	fz(j,1,m-1){
		int l=0,r=max(n,m);
		while(l<=r){
			int mid=(l+r)>>1;
			if(i-mid+1<=0||j-mid+1<=0||i+mid>n||j+mid>m){
				r=mid-1;continue;
			}
			bool flag=1;
			for(int k=i-mid+1;k<=i;k++){
				if(col[k][j-mid+1][j]!=1)	flag=0;
			}
			for(int k=i-mid+1;k<=i;k++){
				if(col[k][j+1][j+mid]!=2)	flag=0;
			}
			for(int k=i+1;k<=i+mid;k++){
				if(col[k][j-mid+1][j]!=3)	flag=0;
			}
			for(int k=i+1;k<=i+mid;k++){
				if(col[k][j+1][j+mid]!=4)	flag=0;
			}
			if(flag)	c[i][j]=mid,l=mid+1;
			else		r=mid-1;
		}
		st[i][j][0][0]=c[i][j];
//		cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
	}
	for(int y=1;y<=8;y++){
		for(int i=1;i<n;i++){
			for(int j=1;(j+(1<<y)-1)<m;j++){
				st[i][j][0][y]=max(st[i][j][0][y-1],st[i][j+(1<<(y-1))][0][y-1]);
			}
		}
	}
	for(int x=1;x<=8;x++){
		for(int y=0;y<=8;y++){
			for(int i=1;(i+(1<<x)-1)<n;i++){
				for(int j=1;(j+(1<<y)-1)<m;j++){
					st[i][j][x][y]=max(st[i][j][x-1][y],st[i+(1<<(x-1))][j][x-1][y]);
				}
			}
		}
	}
//	cout<<st[2][1][0][2]<<endl;
//	cout<<query(1,1,2,5)<<endl;
	while(q--){
		int x1=read(),y1=read(),x2=read(),y2=read();
		int l=1,r=max(n,m),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
//			if(mid==1)	cout<<query(x1+mid-1,y1+mid-1,x2-mid,y2-mid)<<endl;
			if(query(x1+mid-1,y1+mid-1,x2-mid,y2-mid)>=mid)	ans=mid,l=mid+1;
			else											r=mid-1;
		}
		printf("%d\n",4*ans*ans);
	}
	return 0;
}
/*
4 4 1
RRRR
RRRR
RRRG
RRYB
3 3 4 4

10 10 1
RRRGGGRRGG
RRRGGGRRGG
RRRGGGYYBB
YYYBBBYYBB
YYYBBBRGRG
YYYBBBYBYB
RRGGRRRGGG
RRGGRRRGGG
YYBBYYYBBB
YYBBYYYBBB
1 1 3 6
*/