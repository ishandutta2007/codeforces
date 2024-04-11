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

ll cost(int n, int *a)
{
    ll j=1,total=0;
    while(n*j<101)
    {
        total+=a[n*j];
        j++;
    }
//cout<<n<<" "<<total<<endl;
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,k;
   cin>>n>>k;
   map<int,int> food;
   int a[102]={0};
   a[0]=0;
   REP(i,k)
   {
       int x;
       cin>>x;
       food[x]++;
       a[food[x]]++;
   }
   int l=0,r=100,m;
   int b[102];
   b[0]=10000;
   for(int i=1;i<102;i++)
   {
       b[i]=cost(i,a);
   }
   while(l<=r)
   {

       m=l+ ((r-l)/2);
       if(b[m]>=n && b[m+1]<n)
       {
           break;
       }
       else if(b[m]>=n)
       {
           l=m+1;
       }
       else if(b[m]<n)
       {
           r=m-1;
       }
   }
   cout<<m<<endl;
    
     return 0;
}