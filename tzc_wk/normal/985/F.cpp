//Coded by tzc_wk
/*




D P 




 l l
*/
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
#define int long long
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
const int MOD=993244853;
const int HSB=479;
int n=read(),m=read();
char s[200005];
int hs[200005][26],P[200005];
inline void calc(int x){
	fz(i,1,n){
		hs[i][x]=(hs[i-1][x]*HSB+(s[i]-'a'==x))%MOD;
	}
}
int a[26],b[26];
inline int gethash(int l,int r,int x){
	return (hs[r][x]-hs[l-1][x]*P[r-l+1]%MOD+MOD)%MOD;
}
inline void solve(int l,int r,int len){
	fz(i,0,25)	a[i]=gethash(l,l+len-1,i);
	fz(i,0,25)	b[i]=gethash(r,r+len-1,i);
	sort(a,a+26);sort(b,b+26);
	fz(i,0,25)	if(a[i]!=b[i]){
		puts("NO");
		return;
	}
	puts("YES");
}
signed main(){
	cin>>s+1;
	P[0]=1;
	fz(i,1,n)	P[i]=P[i-1]*HSB%MOD;
	fz(i,0,25)	calc(i);
	while(m--){
		int l=read(),r=read(),len=read();
		solve(l,r,len);
	}
	return 0;
}