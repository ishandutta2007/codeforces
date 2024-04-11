#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;  
#define pb push_back
#define F first
#define S second
#define ppp pair<ll,pair<ll,ll>>
#define pp pair<ll,ll>
#define all(x) (x).begin(),(x).end()
#define pi 3.14159265358
#define MOD 1000000007
 
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    freopen("error.txt", "w", stderr); 
    #endif
    
   ll t;
 
   cin>>t;
 
   while(t--)
   {
      string s;
      ll n;
      cin>>n;
      cin>>s;
 
     string ans="";
     int i;
     for(i=0;i<s.size();i+=2)
     {
         ans+=s[i];
     }
     cout<<ans<<endl;
   }
 
 
 
}