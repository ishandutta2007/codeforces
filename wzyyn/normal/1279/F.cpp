    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long long LL;
    typedef long double lb;
    #define ri register int
    const lb PI=3.141592653589793238462643383279;
    const ll inf=1000000000000000000ll;
    const int N=1000005,M=998244353;
    int n,i,k,p,j,l,r,ans;
    int s[N],t[N];
    long long dp[N];
    char c[N];
    int check(int y,bool type,bool f)
    {
    	int i;
    	for(i=1;i<=n;++i)
    	{
    		if(c[i]>='A'&&c[i]<='Z')
    			s[i]=type;
    		else
    			s[i]=type^1;
    		s[i]+=s[i-1];
    	}
    	for(i=1;i<=n;++i)
    	{
    		dp[i]=max(dp[i-1],(i-p<0?0:dp[i-p]-s[i-p])+s[i]-y);
    		if(dp[i-1]>(i-p<0?0:dp[i-p]-s[i-p])+s[i]-y)
    			t[i]=t[i-1];
    		else
    			if(dp[i-1]<(i-p<0?0:dp[i-p]-s[i-p])+s[i]-y)
    				t[i]=t[i-p]+1;
    			else
    				t[i]=min(t[i-1],t[i-p]+1);
    	}
    	if(f)
    	{
    		// cout<<s[n]<<endl;
    		// cout<<y<<endl;
    		// for(int i=1;i<=n-1;i++)cout<<dp[i]<<" ";
    		// cout<<dp[n]<<endl;
    		ans=min(1ll*ans,s[n]-dp[n]-k*y);
    	}
    	return t[n];
    }
    int main()
    {
    	scanf("%d %d %d",&n,&k,&p);
    	scanf("%s",c+1);
    	l=0,r=p;
    	ans=n;
    	while(l<r)
    	{
    		int mid=l+r>>1;
    		if(check(mid,0,0)<=k)
    			r=mid;
    		else
    			l=mid+1;
    	}
    	check(l,0,1);
    	l=0,r=n;
    	while(l<r)
    	{
    		int mid=l+r>>1;
    		if(check(mid,1,0)<=k)
    			r=mid;
    		else
    			l=mid+1;
    	}
    	check(l,1,1);
    	cout<<ans;
    }
    /*
    
    */