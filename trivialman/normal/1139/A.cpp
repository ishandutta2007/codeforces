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
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
char s[N]; 

int main(){
	//freopen("test.in","r",stdin);
	cin>>n;
	scanf("%s",s+1);
	LL ans = 0;
	rep(i,1,n){
		int x = s[i] - 48;
		if(x%2==0) ans += 1ll * i;
	}
	cout<<ans<<endl;
	return 0;
}