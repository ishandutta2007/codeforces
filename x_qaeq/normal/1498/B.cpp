#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,W;
inline void solve()
{
	read(n),read(W);multiset<int>s;int res=0;
	for(int i=1,x;i<=n;i++) read(x),s.insert(x);
	while(!s.empty())
	{
		int rst=W;res++;
		while(!s.empty()&&*s.begin()<=rst)
		{
			multiset<int>::iterator it=s.upper_bound(rst);--it;
			rst-=*it,s.erase(it);
		}
	}
	printf("%d\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}