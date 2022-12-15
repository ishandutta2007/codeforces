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
    
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(c<=a && c<=b && a+b-c<n)
    {
        cout<<n-(a+b-c);
    }
    else
    {
        cout<<"-1";
    }
    
     return 0;
}