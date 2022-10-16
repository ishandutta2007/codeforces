#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
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
int main()
{	
	long long t;
	cin>>t;
	while(t--)
	{
	   long long n,a1=0,b1=0,possible=1;
       cin>>n;
       int a[n],b[n];
       for(long long i=0;i<n;i++)
       {
        cin>>a[i];
       }
       for(long long i=0;i<n;i++)
       {
        cin>>b[i];
       }   
       for(long long i=0;i<n;i++)
       {
            if(a[i]==1&&(b[i]==1||(a[i]>b[i]&&b1==1))) a1=1;
             if(a[i]==-1&&(b[i]==-1||(a[i]<b[i]&&a1==1))) b1=1;
             if(a[i]>b[i]&&b1==0) possible=0;
             if(a[i]<b[i]&&a1==0) possible =0;
             

       }
       if(possible) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
	}	
}