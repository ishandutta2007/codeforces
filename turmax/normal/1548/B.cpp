#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5; 
int t[maxn][20];
int b[maxn];
int d[maxn];
void build(int n)
{
	for(int i=0;i<n;++i) t[i][0]=b[i];
	for(int j=1;j<20;++j) 
	{
		for(int i=0;i<n-(1<<j)+1;++i) 
		{
			t[i][j]=__gcd(t[i][j-1],t[i+(1<<(j-1))][j-1]);
		}
	}
}
int get(int l,int r)
{
	if(l==r) return 0;
	if((r-l)==1) return b[l];
	int sz=d[r-l];
	return __gcd(t[l][sz],t[r-(1<<sz)][sz]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    d[0]=0;d[1]=0;
    for(int i=2;i<maxn;++i) 
    {
    	int sz=1;
    	while((1<<sz)<=i) ++sz;
    	d[i]=sz-1;
    }
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;++i) cin>>a[i];
    	for(int i=0;i<n-1;++i) b[i]=abs(a[i+1]-a[i]); 
    	build(n-1);
    	int ans=0;
    	for(int i=0;i<n-1;++i) 
    	{
    		int low=i;int up=n;
    		while(true)
    		{
    			if((up-low)==1) {ans=max(ans,low-i);break;}
    			int mid=(low+up)/2;
    			int o=get(i,mid);
    			if(o!=1) 
    			{
    				low=mid;
    			}
    			else 
    			{
    				up=mid;
    			}
    		} 
    	}
    	cout<<ans+1<<endl;
    }
    return 0;
}