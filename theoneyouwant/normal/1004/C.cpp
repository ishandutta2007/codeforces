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
    
   int n;
   cin>>n;
   map <int,int> m,r;
   long long int total=0,unique=0,db=0,size=0;
   int a[n];
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       m[x]++;
       a[i]=x;
   }
   size=m.size();
   
    for(int i=0;i<n;i++)
    {
        if(r[a[i]]!=0)
        {
            r[a[i]]++;
            m[a[i]]--;
            if(m[a[i]]==0)
            {
                size--;
            }
            continue;
        }
        else
        {
            r[a[i]]++;
            m[a[i]]--;
            if(m[a[i]]==0)
            {
                size--;
            }
            total+=size;
        }
        
    }
    cout<<total;
     return 0;
}