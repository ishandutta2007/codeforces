#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 3e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	int ans = 3*n;
	ans += min(k-1,n-k);
	cout<<ans<<endl;
	return 0;
}