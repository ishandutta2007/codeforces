#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int INF = 0x3fffffff;
const int N = 300010;

int n,cnt=0;
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d\n",&n);
	rep(i,1,n)scanf("%c",s+i);
	//rep(i,1,n)cout<<s[i];cout<<endl;
	rep(i,1,n)if(s[i]==')')++cnt;
	cnt = n/2-cnt;
	for(int i=n;i;--i)if(s[i]=='?'){
		if(cnt>0)s[i]=')',--cnt;
		else s[i]='(';
	}
	cnt=0;
	bool flag=true;
	rep(i,1,n){
		if(s[i]=='(')++cnt;else --cnt;
		if(i<n&&cnt<=0)flag=false;
	}
	if(cnt!=0)flag=false;
	//rep(i,1,n)cout<<s[i];cout<<endl;
	if(flag)rep(i,1,n)cout<<s[i];
	else cout<<":("<<endl;
	return 0;
}