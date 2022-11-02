#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=2505;
int n,m,k,f[7],g[7],sum[N][N];
ll ans;
char ch[N];
inline int Sum(int lx,int ly,int rx,int ry){
	lx--; ly--;
	return sum[rx][ry]-sum[lx][ry]-sum[rx][ly]+sum[lx][ly];
}
void solve(int lx,int ly,int rx,int ry){
	if(lx==rx&&ly==ry){
		if(Sum(lx,ly,rx,ry)==k)ans++; return;
	}
	//cout<<lx<<" "<<ly<<" "<<rx<<" "<<ry<<endl;
	if(ly-lx>=ry-rx){
		int mid=(lx+rx)>>1;
		for(int i=ly;i<=ry;i++){
			for(int j=0;j<=k;j++)f[j]=lx;
			for(int j=0;j<=k;j++)g[j]=rx;
			for(int j=i;j<=ry;j++){
				for(int l=0;l<=k;l++){
					while(Sum(f[l],i,mid,j)>l)f[l]++;
					while(Sum(mid+1,i,g[l],j)>l)g[l]--;
					//cout<<l<<" "<<f[l]<<" "<<g[l]<<endl;
				}
				for(int l=0;l<=k;l++){
					ans+=(l?f[l-1]-f[l]:mid-f[l]+1)*(l<k?g[k-l]-g[k-l-1]:g[k-l]-mid);
				}
			}
		}
		solve(lx,ly,mid,ry); solve(mid+1,ly,rx,ry);
	}else{
		//cout<<ans<<endl;
		int mid=(ly+ry)>>1;
		for(int i=lx;i<=rx;i++){
			for(int j=0;j<=k;j++)f[j]=ly;
			for(int j=0;j<=k;j++)g[j]=ry;
			for(int j=i;j<=rx;j++){
				for(int l=0;l<=k;l++){
					while(Sum(i,f[l],j,mid)>l)f[l]++;
					while(Sum(i,mid+1,j,g[l])>l)g[l]--;
				}
				for(int l=0;l<=k;l++){
					ans+=(l?f[l-1]-f[l]:mid-f[l]+1)*(l<k?g[k-l]-g[k-l-1]:g[k-l]-mid);
				}
			}
		}
		//cout<<ans<<endl;
		solve(lx,ly,rx,mid); solve(lx,mid+1,rx,ry);
	}
}
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ch[j]-'0';
	}
	solve(1,1,n,m);
	cout<<ans<<endl;
}