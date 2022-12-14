#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=3e5+10;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
    	int b,p,f,h,c;
        cin>>b>>p>>f>>h>>c;
    	int ans=0;
    	if(h<=c)
        {
			if(b>=2*f)
			{
				ans+=c*f;
				b-=2*f;
				if(b>=2*p)ans+=p*h;
				else ans+=b/2*h;
			}
			else
			ans+=b/2*c;
		}
		else
		{
    		if(b>=2*p)
    		{
    			ans+=h*p;
    			b-=2*p;
    			if(b>=2*f)ans+=c*f;
				else ans+=b/2*c;
			}
			else ans+=b/2*h;
		}
		cout<<ans<<endl;
	}

}