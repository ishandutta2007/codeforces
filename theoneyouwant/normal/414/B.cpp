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
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k;
    cin>>n>>k;
    
    long long int a[n+1][k]={0};
    for(int i=1;i<n+1;i++)
    {
        a[i][0]=1;
    }
    for(int i=0;i<k;i++)
    {
        a[1][i]=1;
    }
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%j!=0)
            {
        //        cout<<i<<" "<<j<<endl;
            }
            else if(j*j==i)
            {
                for(int r=1;r<k;r++)
                {
                    a[i][r]=(a[i][r]+a[j][r-1])%mod;
             //       cout<<i<<" "<<j<<" "<<r<<" "<<a[4][2]<<endl;
                }
            }
            else 
            {
              //  cout<<"i is "<<i<<" j is "<<j<<endl;
                for(int r=1;r<k;r++)
                {
                    a[i][r]=(a[i][r]+a[j][r-1])%mod;
                   // cout<<i<<" "<<j<<" "<<r<<" "<<a[4][2]<<a[4][1]<<a[1][1]<<endl;
                   // cout<<a[6][3]<<endl;
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<n+1;j++)
        {
        //    cout<<a[j][i]<<" ";
        }
     //   cout<<endl;
    }
    long long int sum=0;
    for(int i=1;i<n+1;i++)
    {
        sum=(sum+a[i][k-1])%mod;
    }
    cout<<sum%mod;
     return 0;
}