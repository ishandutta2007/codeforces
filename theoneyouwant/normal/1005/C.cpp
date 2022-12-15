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
   set <long long int> s;
   map<int,int> m;
   for(int i=0;i<n;i++)
   {
       int a;
       cin>>a;
       s.insert(a);
   //    cout<<a<<endl;
       m[a]++;
   }
    long long int a[32]={0};
    a[1]=1;
    for(int i=2;i<=31;i++)
    {
        a[i]=a[i-1]*2;
    }
   // cout<<a[30]<<endl;
    ll del=0;
    for(set<long long int>::iterator it=s.begin();it!=s.end();it++)
    {
        bool k=0;
        for(int i=1;i<=31;i++)
        {
            if((a[i]>*it) && (s.count(a[i]-*it)!=0) && (a[i]!=2*(*it)|| m[*it]>1))
            {
// cout<<(*it)<<endl<<m[*it]<<endl;
                k=1;
            }
        }
        if(k==0)
        {
  //  cout<<a[30]<<endl;
  //  cout<<*it<<endl;
            del+=m[*it];
        }
    }
    cout<<del;
     return 0;
}