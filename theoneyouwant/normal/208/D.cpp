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
    
    int n;
    cin>>n;
    long long int p[n];
    long long int num[5]={0};
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    long long int c[5];
    for(int i=0;i<5;i++)
    {
        cin>>c[i];
    }
    long long int sum[n]={0};
    sum[0]=p[0];
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            sum[i]=sum[i-1]+p[i];
        }
        for(int j=4;j>=0;j--)
        {
            num[j]+=sum[i]/c[j];
            sum[i]=sum[i]%c[j];
        }
    }
    for(int i=0;i<5;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
    cout<<sum[n-1];
     return 0;
}