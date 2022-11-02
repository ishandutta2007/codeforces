/*
Date: 2014/10/15 09:47:32 Wednesday
Author: xllend3
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=1111,M=111111;
int l,m,n,t,C,a[N][N];
void work(int n){
	rep(i,1,2*n)rep(j,1,2*n)a[i][j]='.';
	rep(i,1,n)if(!(i&1))a[1][i]='<';
	rep(i,1,n)a[1][i+n]='<';
	rep(i,1,n-1)a[2][i*2]='>';
	rep(i,1,n)a[2*n-1][i*2-1]='>',a[2*n-1][i*2]='^';
	a[1][1]='v';
	rep(i,2,2*n-2)if(i<n+2||(i-n)%2==(n&1))rep(j,1,n)a[i][j*2-1]='v',a[2*n+2-i][j*2]='^';
	rep(i,1,2*n)a[2*n][i]=a[2*n-1][i],a[2*n-1][i]=a[2*n-3][i];
	//rep(i,2,n)a[i][2*n]=a[i+1][2*n];
	rep(i,1,2*n){rep(j,1,2*n)printf("%c",a[i][j]);puts("");}
}
int main()
{
	//ios::sync_with_stdio(false);
	//freopen("CF329D.in","r",stdin);
	//freopen("CF329D.out","w",stdout);
#ifdef ONLINE_JUDGE
	scanf("%d%*d",&n);
	if(n==3){
		puts(">.v");
		puts(">..");
		puts("^.<");
	}else if(n==5){
		puts(">.v.<");
		puts(".....");
		puts("v.<.^");
		puts(".....");
		puts(">.>.^");
	}else work(50);
	puts("1 1");
	return 0;
#endif
	scanf("%d%*d",&n);work(n);
	return 0;
}