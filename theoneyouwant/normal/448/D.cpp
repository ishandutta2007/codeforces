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
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

long long int res(ll n,ll m,ll x)
{
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=min(m,(x-1)/i);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,k;
    cin>>n>>m>>k;
    ll l=1,r=n*m+1,x;
    while(true)
    {
         x= (l+r)/2;
        if(res(n,m,x)>=k && res(n,m,x-1)<k)
        {
            break;
        }
        else if(res(n,m,x)>=k)
        {
            r=x-1;
        }
        else if(res(n,m,x)<k)
        {
            l=x+1;
        }
    }
    cout<<x-1<<endl;
    
     return 0;
}