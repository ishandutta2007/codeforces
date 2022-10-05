/*
Contest:
Problem:
Author: tzc_wk
Time:
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
char s[100005],t[100005];
int n,x;
inline void solve(){
	cin>>s+1;n=strlen(s+1);x=read();
	fz(i,1,n) t[i]='1';
	fz(i,1,n){
		if(s[i]=='0'){
			if(i>x) t[i-x]='0';
			if(i+x<=n) t[i+x]='0';
		}
	}
	fz(i,1,n){
		if(s[i]=='1'){
			bool flag=0;
			if(i>x&&t[i-x]=='1') flag=1;
			if(i+x<=n&&t[i+x]=='1') flag=1;
			if(!flag){puts("-1");return;}
		}
	}
	fz(i,1,n) cout<<t[i];puts("");
}
signed main(){
	int T=read();
	while(T--){
		solve();
	}
	return 0;
}