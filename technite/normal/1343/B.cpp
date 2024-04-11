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
        int n,b,c,ans=0,coun=0;
        cin>>n;
        int a[n]={0};
        int t=1;
        if(n%4==2)
        {
        	cout<<"NO"<<"\n";
        }
        else
        {
        	for(int i=0;i<n/2;i++)
        	{
        		a[i+n/2]=3+4*(i);
        	}
        	for(int i=0;i<n/2;i++)
        	{
        		a[i]=a[i+n/2]+1*t;
        		t=-t;
        	}
        	cout<<"YES"<<endl;
        	for(int i=0;i<n;i++)
        	{
        		cout<<a[i]<<" ";
        	}
        	cout<<"\n";
        }
        
    }
}