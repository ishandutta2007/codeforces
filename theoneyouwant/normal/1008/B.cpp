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
    
   int n;
   cin>>n;
   int w,h;
   cin>>w>>h;
   int prev=max(w,h);
   int j=0;
   for(int i=0;i<n-1;i++)
   {
       cin>>w>>h;
       if(max(w,h)<=prev)
       {
           prev=max(w,h);
       }
       else if(min(w,h)<=prev)
       {
           prev=min(w,h);
       }
       else
       {
           j=1;
       }
   }
   if(j==0)
   {
       cout<<"YES";
   }
   else
   {
       cout<<"NO";
   }
    
     return 0;
}