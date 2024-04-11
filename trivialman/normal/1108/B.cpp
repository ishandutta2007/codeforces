#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

int n,a[200],x,y;

vector<int> divs(int x){
	vector<int> ans;
	rep(i,1,x)if(x%i==0)ans.push_back(i);
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	x = a[n];
	vector<int> b = divs(x);
	rep(i,1,n-1){
		y = a[i];
		vector<int> c = divs(y);
		for(auto z:b)c.push_back(z);
		sort(c.begin(),c.end());
		if(c.size()==n){
			bool flag = true;
			rep(i,1,n)if(c[i-1]!=a[i])flag = false;
			if(flag){
				cout<<x<<" "<<y<<endl;
				break;
			}
		}
	}
	return 0;
}