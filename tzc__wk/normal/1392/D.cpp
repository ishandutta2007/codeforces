/*
Contest: Codeforces Global Round 10
Problem: Codeforces 1392D
Author: tzc_wk
Time: 2020.8.16
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
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,deg[200005];char s[200005],t[200005];
inline int pre(int x){return (x==1)?n:x-1;}
inline int nxt(int x){return (x==n)?1:x+1;}
int dp[200005];
inline int calc(char* s){
	fillbig(dp);dp[0]=0;
	fz(i,0,n){
		if(i+2<=n){
			dp[i+2]=min(dp[i+2],dp[i]+(s[i+1]=='L')+(s[i+2]=='R'));
		}
		if(i+3<=n){
			dp[i+3]=min(dp[i+3],dp[i]+(s[i+1]=='L')+(s[i+3]=='R'));
		}
		if(i+4<=n){
			dp[i+4]=min(dp[i+4],dp[i]+(s[i+1]=='L')+(s[i+2]=='L')+(s[i+3]=='R')+(s[i+4]=='R'));
		}
	}
	return dp[n];
}
inline void solve(){
	n=read();cin>>s+1;fill0(deg);
	fz(i,1,n){
		if(s[i]=='L') deg[pre(i)]++;
		else deg[nxt(i)]++;
	}
	int ans=0x3f3f3f3f;
	fz(_,0,3){
		fz(i,n-_+1,n) t[i-(n-_)]=s[i];
		fz(i,1,n-_) t[_+i]=s[i];
//		cout<<t+1<<endl;
		ans=min(ans,calc(t));
	}
	printf("%d\n",ans);
}
int main(){
	int T=read();while(T--) solve();
	return 0;
}