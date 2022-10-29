#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 505;
mt19937 rng(time(0));

int T;
LL a, b;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>a>>b;
		b++;
		LL x=-1;
		while(b){
			b/=10, x++;
		}
		cout<<a*x<<endl;
	}
	return 0;
}