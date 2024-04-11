#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
const int M=20*N;
int n,h[N],b[N],root,tsz,ls[M],rs[M];
ll dp[N],st[M];
void Set(int&c,int ss,int se,int qi,ll x){
	if(!c)c=++tsz;
	if(ss==se){st[c]=x;return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	st[c]=max(st[ls[c]],st[rs[c]]);
}
ll Get(int c,int ss,int se,int qs,int qe){
	if(ss>qe||se<qs)return (ll)-1e18;
	if(qs<=ss&&se<=qe)return st[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&h[i]);
	for(int i=1;i<=n;i++)scanf("%i",&b[i]);
	stack<int> stk;
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&h[stk.top()]>h[i])stk.pop();
		int pos=stk.empty()?0:stk.top();
		dp[i]=Get(root,0,n,pos,i-1)+b[i];
		if(pos!=0)dp[i]=max(dp[i],dp[pos]);
		Set(root,0,n,i,dp[i]);
		stk.push(i);
	}
	//for(int i=1;i<=n;i++)printf("%lld ",dp[i]);
	printf("%lld",dp[n]);
	return 0;
}