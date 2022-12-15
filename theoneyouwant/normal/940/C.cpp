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
   set <char> myset;
   for(int i=0;i<n;i++)
   {
       myset.insert(s[i]);
   }
    char answer[k];
    if(k>n)
    {
        for(int i=0;i<n;i++)
        {
            answer[i]=s[i];
        }
        set<char>::iterator it=myset.begin();
        for(int i=n;i<k;i++)
        {
            answer[i]=*it;
        }
    }
    else
    {
    for(int i=0;i<k;i++)
    {
        answer[i]=s[i];
    }
    set<char>::iterator it=myset.begin();
    set<char>::iterator it2=myset.begin();
    while(*it!=answer[k-1])
    {
        it++;
    }
    it++;
    if(it!=myset.end())
    {
        answer[k-1]=*it;
    }
    else
    {
        if(it==myset.end())
        {
         //   cout<<"This happened"<<endl;
            it--;
        }
      //  cout<<"it2 is "<<*it2<<" it is "<<*it<<endl;
        int i=k-1;
        while(i>=0 && answer[i]==(*it))
        {
            answer[i]=*it2;
            i--;
        }
        while(*it2!=answer[i])
    {
        it2++;
    }
    it2++;
    answer[i]=*it2;
    }
    }
    for(int i=0;i<k;i++)
    {
        cout<<answer[i];
    }
     return 0;
}