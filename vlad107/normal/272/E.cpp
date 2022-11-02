#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>
#include <iostream>

#define mp make_pair
#define pb push_back
#define N 500500

using namespace std;

set<pair<int,int> >s;
int n,m,x,y,u[N],a[N];
vector<int>g[N];

void mod(int x,int val){
    s.erase(mp(u[x],x));
    u[x]=val;
    s.insert(mp(u[x],x));
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){scanf("%d%d",&x,&y);--x;--y;g[x].pb(y);g[y].pb(x);u[x]++;u[y]++;}
    for (int i=0;i<n;i++)s.insert(mp(u[i],i));
    memset(a,0,sizeof(a));
    while (1){
        set<pair<int,int> >::iterator it=s.end();--it;
        int x=it->second;
        if (u[x]<=1)break;
        mod(x,g[x].size()-u[x]);
        for (int i=0;i<g[x].size();i++)mod(g[x][i],u[g[x][i]]+(a[x]==a[g[x][i]]?-1:1));
        a[x]=1-a[x];
    }
    for (int i=0;i<n;i++)cout<<a[i];
}