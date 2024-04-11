#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 110;

string s1,s2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s1>>s2;
	if(s1.size()!=s2.size()){
		cout<<"No\n";return 0;
	}
	set<char> st={'a','e','i','o','u'};
	rep(i,0,s1.size()-1){
		bool t1 = (st.find(s1[i])!=st.end());
		bool t2 = (st.find(s2[i])!=st.end());
		if(t1!=t2){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}