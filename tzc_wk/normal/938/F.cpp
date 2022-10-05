/*
Contest: -
Problem: Codeforces 938F
Author: tzc_wk
Time: 2020.10.17
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
char s[5005];int n,m;bool dp[5005][5005];
int main(){
	scanf("%s",s+1);n=strlen(s+1);m=log2(n);
	for(int j=0;j<(1<<m);j++) dp[0][j]=1; 
	for(int i=1;i<=n-(1<<m)+1;i++){
		int mn=26;
		for(int j=0;j<(1<<m);j++) dp[i][j]=dp[i-1][j];
		for(int j=0;j<(1<<m);j++) if(dp[i][j]) mn=min(mn,s[i+j]-'a'+1);
		for(int j=0;j<(1<<m);j++) dp[i][j]&=((s[i+j]-'a'+1)==mn);
		for(int j=0;j<(1<<m);j++) for(int k=0;k<m;k++) if(j>>k&1) dp[i][j]|=dp[i][j^(1<<k)];
		putchar(mn+'a'-1);
	}
	return 0;
}