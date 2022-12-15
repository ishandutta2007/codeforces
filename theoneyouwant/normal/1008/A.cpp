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
   int j=0;
   for(int i=0;i<s.length();i++)
   {
       if(i==s.length()-1)
       {
           if(s[i]!='a' && s[i]!='e' &&s[i]!='i' &&s[i]!='o' &&s[i]!='u' && s[i]!='n')
           {
               j=1;
           }
       }
       else if (s[i]!='a' && s[i]!='e' &&s[i]!='i' &&s[i]!='o' &&s[i]!='u' &&s[i]!='n')
       {
           if(s[i+1]!='a' && s[i+1]!='e' &&s[i+1]!='i' &&s[i+1]!='o' &&s[i+1]!='u')
           {
               j=1;
           }
       }
       else
       {
           
       }
   }
    if(j==1)
    {
        cout<<"NO";
    }
    else 
    {
        cout<<"YES";
    }
     return 0;
}