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


int find(int x, int *link) 
{
    while(x!=link[x])
    {
        x=link[x];
    }
    return x;
}

bool same(int a, int b, int *link) {
return find(a, link) == find(b, link);
}

void unite(int a, int b, int* link,int *size){
a = find(a,link);
b = find(b,link);
if(a==b)
{
    
}
else
{
if (size[a] < size[b]) swap(a,b);
size[a] += size[b];
link[b] = a;
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   int n,m,q;
   cin>>n>>m>>q;
   int link[n+m+1]={0};
   int size[n+m+1]={0};
   for (int i = 0; i <= n+m; i++) link[i] = i;
   for (int i = 0; i <= n+m; i++) size[i] = 1;
   REP(i,q)
   {
       int x,y;
       cin>>x>>y;
       unite(x,y+n,link,size);
   }
   set<int>s;
   for (int i = 1; i <= n+m; i++)
   {
       s.insert(find(i,link));
   }
   cout<<s.size()-1;
     return 0;
}