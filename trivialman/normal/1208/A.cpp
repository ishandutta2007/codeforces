#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int INF = 0x3fffffff;
const int N = 1005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int T, a, b, n;

int main(){
	//freopen("test.in","r",stdin);
	cin>>T;
	while(T--){
		cin>>a>>b>>n;
		if(n%3==0)cout<<a<<endl;
		if(n%3==1)cout<<b<<endl;
		if(n%3==2)cout<<(a^b)<<endl;
	}
	return 0;
}