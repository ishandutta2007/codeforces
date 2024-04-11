#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sc second

struct graph
{
    int x,y;
};

int n,a,b,sum,kol,k;
vector <int> Vec;
set <int> st;
set<int>::iterator it;
string s;
stringstream str;
bool t;
char ch;
queue <int> q;


int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

   cin>>n>>k;
   sum=240-k;
   for (int i=1;i<=n;i++)
   {
       if (sum-5*i>=0)
       {
           sum-=5*i;
           kol++;
       }
   }

   cout<<kol;

   return 0;
}