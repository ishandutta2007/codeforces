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
    long long int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
    	long long int x,y;
    	cin>>x>>y;
    	if((x+y)%2==0)
    	{
    		cout<<(n)*(x-1)/2 + (n%2)*((x-1)%2)+(y+1)/2<<endl;
    	}
    	else
    	{
    		cout<<(n*n+1)/2+(n)*(x-1)/2 +(y+1)/2<<endl;
    	}
    }

   
    
     return 0;
}