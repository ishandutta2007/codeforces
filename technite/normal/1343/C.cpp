#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
void printvector(vector<int>& v)
{
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n),sum;
        long long ans=0;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n;)
        {
        	int b=-1e10;
        	if(v[i]>0)
        	{
        		b=v[i];
        		i++;
        		while(v[i]>0&&i<n)
        		{
        			b=max(v[i],b);
        			i++;
        		}
        		sum.push_back(b);
        		
        	}
        	else
        	{
        		b=v[i];
        		i++;
        		while(v[i]<0&&i<n)
        		{
        			b=max(b,v[i]);
        			i++;
        		}
        		sum.push_back(b);
        	}
        }
        for(auto x:sum)
        {
             
        	ans+=x;
        }	
        cout<<ans<<"\n";
    }
}