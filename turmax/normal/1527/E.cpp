#include <bits/stdc++.h> 

using namespace std;
#define int long long 
const int maxn=35005;
int t[4*maxn]; 
int u[maxn];
int delay[4*maxn];
void build(int node,int tl,int tr)
{
	delay[node]=0;
    if((tr-tl)==1) 
    {
    	t[node]=u[tl];
    	return;
    }
    int tm=(tl+tr)/2;
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
void push(int node)
{
	int x=delay[node];
	delay[node]=0;
	delay[2*node+1]+=x;
	t[2*node+1]+=x;
	delay[2*node+2]+=x;
	t[2*node+2]+=x;
}
void pl(int node,int tl,int tr,int l,int r,int val)
{
	if(tl>=l && tr<=r)
	{
		t[node]+=val;
		delay[node]+=val;
		return;
	}
	if(tl>=r || tr<=l) return;
	push(node); 
	int tm=(tl+tr)/2;
	pl(2*node+1,tl,tm,l,r,val);pl(2*node+2,tm,tr,l,r,val);
    t[node]=min(t[2*node+1],t[2*node+2]);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int a[n];
	int pr[n+1];
	map <int,int> u1;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		a[i]--;
		if(u1.count(a[i])) pr[i]=u1[a[i]];
		else pr[i]=(-1);
		u1[a[i]]=i;
	}
	int dp[n+1];
	int dp1[n+1];
	for(int i=0;i<=n;++i) dp[i]=1e18;
	dp[0]=0;
    for(int i=0;i<k;++i)
    {
    	for(int j=0;j<=n;++j) {u[j]=dp[j];}
        build(0,0,n+1);
        for(int j=0;j<=n;++j)
        {
        	dp1[j]=t[0];
        	if(pr[j]!=(-1) && j!=n)
        	{
        		pl(0,0,n+1,0,pr[j]+1,j-pr[j]);
        	}
        }
        for(int i=0;i<=n;++i) dp[i]=dp1[i];
    }
    cout<<dp[n];
	return 0;
}