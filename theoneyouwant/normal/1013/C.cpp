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
    ll minx=mod,miny=mod,maxx=0,maxy=0;
    ll a[2*n];
    REP(i,2*n)
    {
        cin>>a[i];
    }
   sort(a,a+2*n);
   REP(i,n)
   {
       minx=min(minx,a[i]);
       maxx=max(maxx,a[i]);
   }
    for(int i=n;i<2*n;i++)
    {
        miny=min(miny,a[i]);
        maxy=max(maxy,a[i]);
    }
    ll mindiff=a[n-1]-a[0];
    int z1=0,z2=n-1;
    REP(i,n)
    {
        z1++;
        z2++;
        mindiff = min(mindiff,a[z2]-a[z1]);
    }
    cout<<min((maxx-minx)*(maxy-miny),(a[2*n-1]-a[0])*mindiff);
     return 0;
}