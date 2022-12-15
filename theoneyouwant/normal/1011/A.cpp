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
    
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   int a[27]={0};
   ll weight=0;
   REP(i,s.length())
   {
       a[s[i]-96]++;
   }
    int j=1,counter=0;
    while(j<=26 && counter<k)
    {
        if(a[j]!=0)
        {
            weight+=j;
            j=j+2;
            counter++;
        }
        else
        {
            j++;
        }
    }
    if(counter<k)
    {
        cout<<-1;
    }
    else
    {
        cout<<weight;
    }
     return 0;
}