#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const int INF = 0x3fffffff;
const int N = 1e5+5;
mt19937 rng(time(0));

int n, a, b;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n){
		cin>>a>>b;
		cout<<(a%b==0 ? 0 : b-a%b)<<endl;
	}
	return 0;
}