/*




D P 




 l l
*/
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
int x[25],y[25],n,dp[(1<<24)+15],pre[(1<<24)+15];
inline int dist(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
vector<int> ans;
inline void dump(int x){
	if(x==0)	return;
	int add=x^pre[x];
	dump(pre[x]);
	ans.push_back(log2(add&(-add))+1);
	add-=(add&(-add));
	if(add)	ans.push_back(log2(add&(-add))+1);
	ans.push_back(0);
}
int main(){
	ans.push_back(0);
	x[0]=read();y[0]=read();n=read();
	fz(i,1,n)	x[i]=read(),y[i]=read();
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<(1<<n);i++){
		int i0=log2(i&(-i))+1;
		fz(j,1,n){
			if(i>>(j-1)&1==0)	continue;
			int prev;
			if(i0==j)	prev=i^(1<<(j-1));
			else		prev=i^(1<<(j-1))^(1<<(i0-1));
			if(dp[i]>dp[prev]+dist(0,i0)+dist(i0,j)+dist(j,0))
				dp[i]=dp[prev]+dist(0,i0)+dist(i0,j)+dist(j,0),
				pre[i]=prev;
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	dump((1<<n)-1);
	for(int i=0;i<ans.size();i++)	cout<<ans[i]<<" ";
	return 0;
}