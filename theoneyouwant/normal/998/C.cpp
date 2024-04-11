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
    
    long long int n,x,y;
    cin>>n>>x>>y;
    char a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int num=0,zero[n]={0};
    if(a[0]=='0')
    {
        num++;
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]=='0' && a[i-1]=='1')
        {
            num++;
        }
    }
    if(num==0)
    {
        cout<<"0";
    }
    else
    {
        if(x<y)
    {
        cout<<(num-1)*x+y;
    }
    else
    {
        cout<<num*y;
    }
    }
     return 0;
}