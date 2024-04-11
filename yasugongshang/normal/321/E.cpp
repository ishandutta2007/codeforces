#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=4005;
int n,k,q[N],dp[N],jc[N],sum[N][N];
#define cal(a,b) dp[a]+sum[b][b]-sum[a][b]-sum[b][a]+sum[a][a]
inline int better(int x,int y){
	int l=y-1,r=n;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(cal(x,mid)<cal(y,mid))l=mid; else r=mid-1;
	}
	return l;
}
PI check(int x){
	int l=1,r=1; q[1]=0;
	for(int i=1;i<=n;i++){
		while(l<r&&cal(q[l],i)>=cal(q[l+1],i))l++;
		dp[i]=cal(q[l],i)+x; jc[i]=jc[q[l]]+1;
		while(l<r&&better(q[r-1],q[r])>better(q[r],i))r--;
		q[++r]=i;
	}
	return mp(dp[n],jc[n]);
}
signed main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sum[i][j]=read()+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	//cout<<check(5).first<<" "<<check(5).second<<endl; return 0;
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r+1)>>1; 
		if(check(mid).second>=k)l=mid; else r=mid-1;
	}
	//cout<<check(l).first<<" "<<check(l).second<<" "<<l<<endl;
	PI t=check(l);
	cout<<(t.first-k*l)/2<<endl;
}