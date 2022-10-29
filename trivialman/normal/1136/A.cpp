#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define MP make_pair
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,l[200],r[200];

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	rep(i,1,n)cin>>l[i]>>r[i];
	cin>>k;
	int ans = 1;
	for(;ans<=n&&r[ans]<k;ans++);
	ans = n + 1 - ans;
	cout<<ans<<endl;
	return 0;
}