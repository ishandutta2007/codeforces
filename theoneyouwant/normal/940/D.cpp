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
   char b[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int l=-pow(10,9),r=pow(10,9);
    for(int i=4;i<n;i++)
    {
        if(b[i-1]=='1' && b[i-2]=='1' && b[i-3]=='1' && b[i-4]=='1' && b[i]=='0')
        {
            if(min(a[i],min(a[i-1],min(a[i-2],min(a[i-3],a[i-4]))))-1<r)
            {
                r=min(a[i],min(a[i-1],min(a[i-2],min(a[i-3],a[i-4]))))-1;
            }
        }
        if(b[i-1]=='0' && b[i-2]=='0' && b[i-3]=='0' && b[i-4]=='0' && b[i]=='1')
        {
            if(max(a[i],max(a[i-1],max(a[i-2],max(a[i-3],a[i-4]))))+1>l)
            {
                l=max(a[i],max(a[i-1],max(a[i-2],max(a[i-3],a[i-4]))))+1;
            }
        }
    }
    cout<<l<<" "<<r;
     return 0;
}