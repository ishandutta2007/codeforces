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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int t,k,a,b;
    int n=pow(10,5);
    cin>>t>>k;
    long long int c[n+1];
    for(int i=0;i<k;i++)
    {
        c[i]=1;
    }
    for(int i=k;i<n+1;i++)
    {
        c[i]=(c[i-1]+c[i-k])%mod;
    }
    long long int sum[n+1];
    sum[0]=1;
    for(int i=1;i<n+1;i++)
    {
        sum[i]=(sum[i-1]+c[i])%mod;
    }
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        cout<<(sum[b]-sum[a-1]+mod)%mod<<endl;
    }
    
     return 0;
}