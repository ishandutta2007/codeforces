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
    
   int n,x;
   cin>>n>>x;
   map<int,int> m;
   int j=0,counter=0;
   int z[n];
   REP(i,n)
   {
       int a;
       cin>>a;
       if(m[a]!=0)
       {
           j=1;
       }
       else
       {
           m[a]++;
       }
       z[i]=a;
   }
   if(j==0)
   {
       map<int,int> m2;
       REP(i,n)
       {
       int r=z[i]&x;
       if(m[r]!=0 && r!=z[i])
       {
           j=1;
           counter=1;
           break;
       }
       if(m[r]>1)
       {
           j=1;
           counter=1;
           break;
       }
       else
       {
           m2[r]++;
       }
       }
       if(j==0)
       {
       REP(i,n)
       {
           int r=z[i]&x;
           if(m2[r]>=2)
           {
               j=1;
               counter=2;
               break;
           }
       }
       }
   }
   if(j==0)
   {
       cout<<-1;
   }
   else
   {
       cout<<counter;
   }
    
     return 0;
}