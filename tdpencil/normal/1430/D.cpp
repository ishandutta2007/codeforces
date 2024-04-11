#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF=LLONG_MAX/2;
const ll N=2e5+1;
using  namespace std;
int main()
{
    fast;
   ll t=1;
   std::cin >> t;
   while(t--)
{
       ll n,i,j=0;
       std::cin >> n;
       string s;
       cin>>s;
       ll a[n]={0},x=0;
       fr(i,1,n)
       {
           if(s[i]==s[i-1])
           {
               a[x]++;
           }
           else
           {
               x++;
           }
       }
       fr(i,0,x+1)
       {
           a[i]++;
       }
       ll ans=0,r=x;
       fr(i,0,x+1)
       {
           if(a[i]==0)
           break;
           if(a[i]>1)
           {
               a[i]=0;
               ans++;
           }
           else
           {
               if(j==0)
               {
                   ll y=0,z=0;
                   fr(j,i,x+1)
                   {
                       if(a[j]>1)
                       {
                           y=1;
                           r=j;
                           a[j]--;
                           break;
                       }
                       
                   }
                   if(y==0)
                   {
                       a[x]--;
                       x--;
                       r=x;
                   }
               j=1;
               if(!z)
               ans++;
               }
               else
               {
                   ll y=0,z=0;
                   fr(j,r,x+1)
                   {
                       if(a[j]>1)
                       {
                           r=j;
                           a[j]--;
                           y=1;
                           break;
                       }
                   }
                   if(y==0)
                   {
                       r=x-1;
                       x--;
                       a[x+1]--;
                   }
                   if(!z)
                   ans++;
               }
           }
       }
       cout<<ans<<"\n";
}
}