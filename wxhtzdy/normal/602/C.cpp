#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=450;
int con[N][N];
int main(){
    int n,m;scanf("%i%i",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;scanf("%i%i",&u,&v);
        con[u][v]=1,con[v][u]=1;
    }
    int dist1[N];
    for(int i=1;i<=n;i++)dist1[i]=N;
    deque<int> q;
    q.pb(1),dist1[1]=0;
    while(!q.empty()){
        int x=q[0];
        q.pop_front();
        for(int i=1;i<=n;i++){
            if(con[x][i]){
                if(dist1[i]==N)q.pb(i);
                dist1[i]=min(dist1[i],dist1[x]+1);
            }
        }
    }
    int dist2[N];
    for(int i=1;i<=n;i++)dist2[i]=N;
    q.pb(1),dist2[1]=0;
    while(!q.empty()){
        int x=q[0];
        q.pop_front();
        for(int i=1;i<=n;i++){
            if(!con[x][i]){
                if(dist2[i]==N)q.pb(i);
                dist2[i]=min(dist2[i],dist2[x]+1);
            }
        }
    }
    int ans=max(dist1[n],dist2[n]);
    printf("%i",(ans==N?-1:ans));
    return 0;
}