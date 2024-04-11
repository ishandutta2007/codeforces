#include<bits/stdc++.h>
using namespace std;
long long answer(long long x,long long y,long long z)
{
	return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
    	int r,g,B;
    	cin>>r>>g>>B;
    	vector<long long> a(r),b(g),c(B);
    	for(int i=0;i<r;i++) cin>>a[i];
    	for(int i=0;i<g;i++) cin>>b[i];
    	for(int i=0;i<B;i++) cin>>c[i];
 		long long ans=4*1e18;
 		sort(a.begin(),a.end());
 		sort(b.begin(),b.end());
 		sort(c.begin(),c.end());
    	for(auto x:a)
    	{
    		auto i=lower_bound(b.begin(), b.end(),x);
    		auto j=lower_bound(c.begin(), c.end(),x);
    		if(i==b.end()||(i!=b.begin())&&(abs(*i-x)>abs(*(i-1)-x))) i--;
    		if(j==c.end()||(j!=c.begin())&&(abs(*j-x)>abs(*(j-1)-x))) j--;
    		ans=min(ans,answer(x,*i,*j));
    		
    	}	
    	for(auto x:b)
    	{
    		auto i=lower_bound(a.begin(), a.end(),x);
    		auto j=lower_bound(c.begin(), c.end(),x);
    		if(i==a.end()||(i!=b.begin())&&(abs(*i-x)>abs(*(i-1)-x))) i--;
    		if(j==c.end()||(j!=c.begin())&&(abs(*j-x)>abs(*(j-1)-x))) j--;
    		ans=min(ans,answer(*i,x,*j));
    	}
    	for(auto x:c)
    	{
			auto i=lower_bound(b.begin(), b.end(),x);
    		auto j=lower_bound(a.begin(), a.end(),x);
    		if(i==b.end()||(i!=b.begin())&&(abs(*i-x)>abs(*(i-1)-x))) i--;
    		if(j==a.end()||(j!=a.begin())&&(abs(*j-x)>abs(*(j-1)-x))) j--;
    		ans=min(ans,answer(*j,*i,x));
    	}
    	cout<<ans<<endl;
    }
}