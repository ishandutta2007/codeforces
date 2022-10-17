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

int n,a,b,sum,kol,k,x,y;
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

   cin>>n;
   x=20000;
   y=0;
   for (int i=1;i<=n;i++)
   {
       cin>>a>>s;
       if (x-a<0 && s=="South")
       {
           cout<<"NO";
           exit(0);
       }
       if (x+a>20000 && s=="North")
       {
           cout<<"NO";
           exit(0);
       }
       if (x==20000 && s!="South")
       {
           cout<<"NO";
           exit(0);
       }

       if (x==0 && s!="North")
       {
           cout<<"NO";
           exit(0);
       }

       if (s=="South")
       {
           x-=a;
       }
       if (s=="North")
       {
           x+=a;
       }
       if (s=="West")
       {
           y-=a;
       }
       if (s=="East")
       {
           y+=a;
       }
   }

   if (x!=20000)
   {
       cout<<"NO";
   }
   else cout<<"YES";

   return 0;
}