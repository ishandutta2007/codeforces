#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 100010;

struct dat{
	LL a,c,id;
};

int a,b,c,x,y,z;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	cout<<(x<=a && x+y<=a+b && x+y+z<=a+b+c ? "YES" : "NO")<<endl;
	return 0;
}