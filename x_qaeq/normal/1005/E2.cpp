//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,K,a[200005],T[400005];
inline void add(int x) {for(;x<=400003;x+=x&(-x)) T[x]++;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline ll solve(int e)
{
	const int N=200001;ll rs=0;memset(T,0,sizeof(T)),add(N);
	for(int i=1,w=N;i<=n;i++) w+=((a[i]<=e)<<1)-1,rs+=qry(w),add(w);
	return rs;
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	return printf("%lld\n",solve(K)-solve(K-1)),0;
}