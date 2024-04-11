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
    
   string s,t;
   cin>>s>>t;
   string r;
   if(s.length()<t.length())
   {
       r=s;
       s=t;
       t=r;
   }
   int a=s.length();
   int b=t.length();
   ll common=0;
   ll answer=a+b;
   int j=b-1;
   for(int i=a-1;i>=0;i--)
   {
       if(j<0)
       {
           break;
       }
       if(s[i]==t[j])
       {
           common++;
           j--;
       }
       else
       {
           break;
       }
   }
 //  cout<<answer<<endl<<common<<endl;
    answer-=2*common;
    cout<<answer;
     return 0;
}