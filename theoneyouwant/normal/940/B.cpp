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
    
   long long int n,k,a,b;
   cin>>n>>k>>a>>b;
   long long int total = 0;
    if(k==1)
    {
        total+=(n-1)*a;
        cout<<total;
    }
    else
    {
        while(n>1)
        {
            if(n<k)
            {
                total+=(n-1)*a;
                break;
            }
            total+=(n%k)*a;
            n=n-(n%k);
            total+=min(b,(n-n/k)*a);
            n=n/k;
        }
        cout<<total;
    }
     return 0;
}