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
   int a[4][3]={0};
   REP(i,n)
   {
       string x;
       cin>>x;
       int j=0;
       while(x[j]=='X')
       {
           j++;
       }
       if(x[j]=='S' || x[j]=='M' || x[j]=='L')
       {
           if(x[j]=='S')
           {
               a[j][0]++;
           }
           else if(x[j]=='M')
           {
               a[j][1]++;
           }
           else
           {
               a[j][2]++;
           }
       }
   }
   REP(i,n)
   {
       string x;
       cin>>x;
       int j=0;
       while(x[j]=='X')
       {
           j++;
       }
       if(x[j]=='S' || x[j]=='M' || x[j]=='L')
       {
           if(x[j]=='S')
           {
               a[j][0]--;
           }
           else if(x[j]=='M')
           {
               a[j][1]--;
           }
           else
           {
               a[j][2]--;
           }
       }
   }
   ll r=0;
   REP(i,4)
   {
       REP(j,3)
       {
           r+=abs(a[i][j]);
       }
   }
    cout<<r/2;
     return 0;
}