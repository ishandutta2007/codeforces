#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 500010;

int n,a[20],x,y;
string ss[7]={"","RGB","RBG","GBR","GRB","BGR","BRG"};
string s;

int calc(string s1,string s){
	int ans=0;
	rep(i,0,n-1)
		ans += (s1[i%3]!=s[i]);
	return ans;
}
string change(string s1,string s){
	rep(i,0,n-1)s[i]=s1[i%3];
	return s;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	cin>>s;
	rep(i,1,6)a[i]=calc(ss[i],s);
	int ans = 1e9,ansi;
	rep(i,1,6) if(a[i]<ans) ans=a[i], ansi=i;
	cout<<ans<<endl;
	cout<<change(ss[ansi],s)<<endl;
	return 0;
}