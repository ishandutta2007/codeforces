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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(10);
    int n,r;
    cin>>n>>r;
    long long int x[n];
    long double y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    y[0]=r;
    for(int i=1;i<n;i++)
    {
        long double z=r;
        for(int j=0;j<i;j++)
        {
            if(abs(x[i]-x[j])<=2*r)
            {
                z=max(z,y[j]+sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
            }
        }
        y[i]=z;
    }
    for(int i=0;i<n;i++)
    {
        cout<<y[i]<<" ";
    }
     return 0;
}