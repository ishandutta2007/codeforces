#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

string s;
int r1=0, r2=0;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>s;
	for(auto x:s){
		if(x=='0'){
			cout<<r1*2+1<<" "<<1<<endl;
			r1 = 1 - r1;
		}else{
			cout<<r2+1<<" "<<3<<endl;
			r2 = (r2 + 1) % 4;
		}
	}
	return 0;
}