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
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   sort(a,a+n);
   int prev=0,current=0,currnum=0,total=0;
   currnum=a[0];
   current++;
   for(int i=1;i<n;i++)
   {
       if(a[i]>currnum)
       {
           currnum=a[i];
           prev+=current;
           current=1;
           if(prev>0)
           {
               prev--;
               total++;
           }
       }
       else
       {
           if(prev>0)
           {
               prev--;
               total++;
           }
           current++;
       }
   }
    cout<<total;
     return 0;
}