#pragma GCC optimize("O3","Ofast")
#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int pr[maxn];
int t[4*maxn];
/*void build(int node,int tl,int tr)
{
	if((tr-tl)==1)
	{
		t[node]={pr[tl]};
		return;
	}
	int tm=(tl+tr)/2;
	build(2*node+1,tl,tm);build(2*node+2,tm,tr);
	t[node]=t[2*node+1];
	for(auto h:t[2*node+2]) t[node].push_back(h);
    sort(t[node].begin(),t[node].end());
}*/
int get(int node,int tl,int tr,int l,int r,int k)
{
    if(tl>=l && tr<=r)
    {
    	return t[node];
    }
    if(tl>=r || tr<=l) return 0;
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r,k)+get(2*node+2,tm,tr,l,r,k);
}
void pl(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return;
    t[node]++;
    if((tr-tl)==1) return;
    int tm=(tl+tr)/2;
    pl(2*node+1,tl,tm,pos);pl(2*node+2,tm,tr,pos);
}
int hs(int x)
{
	for(int i=2;i*i<=x;++i)
	{
		if(x%(i*i)==0)
		{
			return hs(x/(i*i));
		}
	}
	return x;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;++i) {cin>>a[i];a[i]=hs(a[i]);}
		map <int,int> u1;
		int nxt[n];
        for(int i=0;i<n;++i)
        {
            nxt[i]=(-1);
        	pr[i]=(-1);
        	if(u1.count(a[i])) {pr[i]=u1[a[i]];nxt[pr[i]]=i;}
        	u1[a[i]]=i;
        }
        //build(0,0,n);
        for(int i=0;i<=(4*n+4);++i) t[i]=0;
        int dp[n+1][k+1];
        for(int i=0;i<=k;++i) dp[n][i]=0;
        for(int i=(n-1);i>=0;i--)
        {
            if(nxt[i]!=(-1))
            pl(0,0,n,nxt[i]);
        	for(int z=0;z<=k;++z) dp[i][z]=1e9;
        	for(int j=k;j>=0;--j)
        	{
        	    if(t[0]<=j)
                {
                    int low=n;
                    for(int z=j;z<=k;++z)
        		    {
        			dp[i][z]=min(dp[i][z],dp[low][z-j]+1);
        		    }
        		    continue;
                }
        		int low=0;int up=n;int node=0;int curr=0;
        		while(true)
        		{
        			if((up-low)==1)
        			{
        				break;
        			}
        			int mid=(low+up)/2;
        			int ans1=t[2*node+1];
        			if((curr+ans1)>j) {up=mid;node*=2;++node;}
        			else {curr+=ans1;low=mid;node*=2;node+=2;}
        		}
        		for(int z=j;z<=k;++z)
        		{
        			dp[i][z]=min(dp[i][z],dp[low][z-j]+1);
        		}
        	}
        }
        cout<<dp[0][k]<<endl;
	}
	return 0;
}