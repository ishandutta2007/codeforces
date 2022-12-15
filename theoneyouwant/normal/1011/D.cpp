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
    
   int m,n;
   int a;
   cin>>m>>n;
   int p[n]={0};
   REP(i,n)
   {
       cout<<1<<endl;
       cout<<flush;
       cin>>a;
       if(a==0)
       {
           return 0;
       }
       if(a==-2)
       {
           return 0;
       }
       if(a==1)
       {
           p[i]=1;
       }
       else if(a==-1)
       {
           p[i]=-1;
       }
   }
   int j=0;
   int l=1,r=m;
   int mid=0;
   mid = l +(r-l)/2;
   while(true)
   {
       cout<<mid<<endl<<flush;
       cin>>a;
       if(a==0 || a==-2)
       {
           break;
       }
       else
       {
           if((p[j]==1 && a==1) ||(p[j]==-1 && a==-1))
           {
               l=mid+1;
           }
           else
           {
               r=mid-1;
           }
           mid = l +(r-l)/2;
       }
       j=(j+1)%n;
   }
     return 0;
}