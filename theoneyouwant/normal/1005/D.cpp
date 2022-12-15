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
    
   string s;
   cin>>s;
   int total=0;
   int current=0,curbef=0;
   for(int i=0;i<s.length();i++)
   {
       if(s[i]%3==0)
       {
           total++;
           current=0;
           curbef=0;
       }
       else
       {
           if(current==0)
           {
               current=s[i]%3;
           }
           else
           {
               if((current+(s[i]%3))%3==0)
               {
                   total+=1;
                   current=0;
                   curbef=0;
               }
               else
               {
                   if((current-curbef+(s[i]%3)+3)%3==0)
                   {
                       total+=1;
                       current=0;
                       curbef=0;
                   }
                   else
                   {
                       curbef=current;
                       current = (current+(s[i]%3))%3;
                   }
               }
           }
       }
   }
   cout<<total<<endl;
    
     return 0;
}