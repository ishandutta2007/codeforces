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
    
   long double n,m;
   cin>>n>>m;
   long double a[(int)n],b[(int)n];
   cin>>a[(int)n-1];
   REP(i,n-1)
   {
       cin>>a[i];
   }
   cin>>b[(int)n-1];
   REP(i,n-1)
   {
       cin>>b[i];
   }
   long double weight=0;
   bool no=0;
   cout<<setprecision(8);
   REP(i,n)
   {
       long double p;
       if(b[i]>1)
       {
       p= (weight+m)/(b[i]-1);
       weight+=p;
       }
       else 
       {
           no=1;
       }
       if(a[i]>1)
       {
           p= (weight+m)/(a[i]-1);
       weight+=p;
       }
       else 
       {
           no=1;
       }
   }
    if(no==0)
{
cout<<weight;
}
else
{
cout<<-1;
}
     return 0;
}