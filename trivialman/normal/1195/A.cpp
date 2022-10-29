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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,x,a[1010];

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>k;
	rep(i,1,n){
		cin>>x;
		a[x]++;
	}
	int cnt = 0;
	rep(i,1,k){
		if(a[i]%2)++cnt;
	}
	cout<<n-cnt/2<<endl;
	return 0;
}