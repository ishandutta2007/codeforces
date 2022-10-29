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

int T;
LL a, k;

LL mindig(LL x){
	LL res = 10;
	for(;x;x/=10) res = min(res, x%10);
	return res;
}

LL maxdig(LL x){
	LL res = 0;
	for(;x;x/=10) res = max(res, x%10);
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>T;
	while(T--){
		cin>>a>>k; k--;
		while(k--){
			if(mindig(a) == 0) break;
			a += mindig(a) * maxdig(a);
		}
		cout<<a<<endl;
	}
	return 0;
}