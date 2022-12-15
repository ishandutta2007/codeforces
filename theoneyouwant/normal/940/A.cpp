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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,d;
   cin>>n>>d;
   if(n==1)
   {
       cout<<0;
   }
   else
   {
   int x[n];
   for(int i=0;i<n;i++)
   {
       cin>>x[i];
   }
    sort(x,x+n);
    int num[201]={0};
    for(int i=0;i<n;i++)
    {
        num[x[i]]++;
    }
    int sum[201]={0};
    for(int i=1;i<=200;i++)
    {
        sum[i]=sum[i-1]+num[i];
    }
    int most=0;
    for(int i=0;i<n;i++)
    {
        most = max(most,sum[d+1+x[i]]-sum[x[i]]);
        if(x[i]>d)
        {
            most=max(most,sum[x[i]]-sum[x[i]-d-1]);
        }
        if(x[i]==d)
        {
            most=max(most,sum[x[i]]);
        }
    }
    if(x[n-1]<=d)
    {
        most=n;
    }
    cout<<n-most;
   }
     return 0;
}