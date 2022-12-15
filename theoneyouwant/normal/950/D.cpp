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
    
    long long int n,q,x;
    cin>>n>>q;
    for(long long int i=0;i<q;i++)
    {
        cin>>x;
        if(x%2==1)
        {
            cout<<(x+1)/2<<endl;
        }
        else
        {
            x=x/2;
            x=n-1-x;
            while(x%2!=0)
            {
                x=x/2;
            }
            cout<<n-x/2<<endl;
        }
    }
    
     return 0;
}