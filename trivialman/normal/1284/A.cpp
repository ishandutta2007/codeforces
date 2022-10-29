#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 25;
mt19937 rng(time(0));

int n,m,q,x;
string a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,m) cin>>b[i];
	cin>>q;
	rep(i,1,q){
		cin>>x;
		cout<<a[(x-1)%n+1]<<b[(x-1)%m+1]<<endl;
	}
	return 0;
}