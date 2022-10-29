#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

int n;
LL k,num=0,ans=0; 
string s,t;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	cin>>s;
	cin>>t;
	rep(i,0,n-1){
		int x=s[i]-'a',y=t[i]-'a';
		num = (num<<1)+y-x;
		if(num>k)num=k;
		ans = ans + min(num+1,k);
	}
	cout<<ans<<endl;
	return 0;
}