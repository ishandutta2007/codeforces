#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n,x;
stack<int>stk;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		x&=1;
		(!stk.empty()&&x==stk.top())?stk.pop():stk.push(x);
	}
	cout<<(stk.size()<2?"YES":"NO")<<endl;
	return 0;
}