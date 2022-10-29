#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

string s;
int cnt=0;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>s;
	stack<char> stk;
	for(auto x:s){
		if(!stk.empty()&&x==stk.top()){
			stk.pop();
			++cnt;
		}else{
			stk.push(x);
		}
	}
	cout<<(cnt%2?"Yes":"No")<<endl;
	return 0;
}