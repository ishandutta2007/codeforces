/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

ll mini(ll a,ll b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,c;
   ll sum=0;
   multiset <int> m;
   cin>>n>>c;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       if(i<n && i<c)
       {
           sum+=a[i];
       }
   }
    if(c==1)
    {
        cout<<0;
    }
    else if(c>n)
    {
        cout<<sum;
    }
    else
    {
        ll dp[n]={0};
        dp[0]=a[0];
        m.insert(a[0]);
        for(int i=1;i<c-1;i++)
        {
            dp[i]=dp[i-1]+a[i];
            m.insert(a[i]);
        }
       m.insert(a[c-1]);
        multiset<int>::iterator it=m.begin();
        dp[c-1]=mini(dp[c-2]+a[c-1],sum-*it);
        auto itr = m.find(a[0]);
if(itr!=m.end()){
    m.erase(itr);
}
        for(int i=c;i<n;i++)
        {
            sum-=a[i-c];
            sum+=a[i];
            m.insert(a[i]);
            multiset<int>::iterator it=m.begin();
            dp[i]=mini(dp[i-1]+a[i],dp[i-c]+sum-*it);
auto itr = m.find(a[i-c+1]);
if(itr!=m.end()){
    m.erase(itr);
}
        }
        cout<<dp[n-1];
        
    }
     return 0;
}