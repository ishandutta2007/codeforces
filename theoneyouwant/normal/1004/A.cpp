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
    long long int n,d;
    cin>>n>>d;
    long long int x;
    cin>>x;
    long long int y,sum=0;
    for(int i=0;i<n-1;i++)
    {
        cin>>y;
        if(y-x-2*d==0)
{
sum++;
}
else if (y-x-2*d>0)
{
sum=sum+2;
}

        x=y;
    }
   cout<<sum+2;
    
     return 0;
}