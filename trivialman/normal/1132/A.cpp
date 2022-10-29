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

int a,b,c,d;

int main(){
	//freopen("test.in","r",stdin);
	cin>>a>>b>>c>>d;
	bool flag = true;
	if(a!=d) flag = false;
	if(a==0 && c>0) flag = false;
	if(d==0 && c>0) flag = false;
	cout<<(flag?1:0)<<endl;
	return 0;
}