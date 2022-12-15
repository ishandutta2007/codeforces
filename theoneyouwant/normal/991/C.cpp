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

long long int veat(long long int n, long long int k)
{
    if(n<=10 || n<=k)
    {
        return n;
    }
    long long int a = (n-k)/10;
    return k+veat(n-k-a,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n;
    cin>>n;
    long long int l = 1,r=n; 
    long long int x=(n+1)/2;

    if(n<10)
    {
        cout<<"1";
    }
    else
    {
        long long int m=0;
    while (true)
    {
        m = l + (r-l)/2;
 
        // Check if x is present at mid
        if (veat(n,m)>=x && (m==1 || veat(n,m-1)<x))
           break;
        // If x greater, ignore left half
        if (veat(n,m) < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
        if(veat(n,m)>=x && veat(n,m-1)>=x)
            r = m - 1;
    }
    cout<<m;
    }
     return 0;
}