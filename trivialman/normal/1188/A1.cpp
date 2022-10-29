#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 100010;

int n,x,y,deg[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n-1)cin>>x>>y,deg[x]++,deg[y]++;
	bool flag = true;
	rep(i,1,n)if(deg[i]==2)flag = false;
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}