#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 200010;

LL w1,h1,w2,h2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>w1>>h1>>w2>>h2;
	cout<<(w1+h1+h2+2)*2<<endl;
	return 0;
}