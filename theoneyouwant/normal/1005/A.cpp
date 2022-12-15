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
    
   int n,number=0,a=0,b=1;
   cin>>n;
   vector<int> v;
   for(int i=0;i<n;i++)
   {
       cin>>a;
       if(a==1)
       {
           number++;
           if(i!=0)
           {
           v.PB(b);
           }
       }
       b=a;
   }
    v.PB(b);
    cout<<number<<endl;
    for(vector<int>::iterator it = v.begin();it!= v.end();it++)
    {
        cout<<*it<<" ";
    }
     return 0;
}