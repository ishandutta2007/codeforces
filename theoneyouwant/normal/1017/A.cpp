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
   int a,b,c,d;
   int total[n];
   int total1=0;
   for(int i=0;i<n;i++)
   {
       cin>>a>>b>>c>>d;
       if(i==0)
       {
           total1+=a+b+c+d;
       }
       total[i]=a+b+c+d;
   }
   sort(total,total+n);
   int rank=1;
   for(int i=n-1;i>=0;i--)
   {
       if(total[i]<=total1)
       {
           break;
       }
       rank++;
   }
   cout<<rank<<endl;
    
     return 0;
}