#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
char s[505];
int dp[505][505],n;
int dfs(int l,int r){
	if(dp[l][r]!=-1)	return dp[l][r];
	if(l==r)		return dp[l][r]=1;
	if(l>r)			return dp[l][r]=0;
	dp[l][r]=1+dfs(l+1,r);
	for(int i=l+1;i<=r;i++)
		if(s[l]==s[i])
			dp[l][r]=min(dp[l][r],dfs(l+1,i-1)+dfs(i,r));
	return dp[l][r];
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%s",&n,s+1);
	printf("%d\n",dfs(1,n));
	return 0;
}