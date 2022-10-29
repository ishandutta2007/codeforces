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

int q,l,r,d;

int main(){
	//freopen("test.in","r",stdin);
	cin>>q;
	while(q--){
		cin>>l>>r>>d;
		if(d<l) cout<<d<<endl;
		else cout<<(r/d+1)*d<<endl;
	}
	return 0;
}