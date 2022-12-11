#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e5+10;

int n;
vector <int> v[N];
struct BIT{
    int b[N];
    void add(int x,int val){
        while (x<=n){
            b[x]+=val;
            x+=x&-x;
        }
    }
    int get(int x){
        int ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
}mbit;
ll p[N],d[N];
int w[N],ans[N];

queue <int> q;
void BFS(){
    q.push(1);
    while (!q.empty()){
        int x=q.front();q.pop();
        for(auto y:v[x]){
            d[y]+=d[x];
            q.push(y);
        }
    }
}
void DFS(int x){
    int idx=upper_bound(p+1,p+n+1,d[x])-p-1;
    ans[x]-=mbit.get(idx);
    mbit.add(lower_bound(p+1,p+n+1,d[x]-w[x])-p,1);
    for(auto y:v[x]) DFS(y);
    ans[x]+=mbit.get(idx);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",w+i);
    for(int y=2;y<=n;y++){
        int x,val;
        scanf("%d%d",&x,&val);
        d[y]=val;
        v[x].push_back(y);
    }
    BFS();
//    for(int i=1;i<=n;i++) cout<<d[i]<<" \n"[i==n];
//    for(int i=1;i<=n;i++) cout<<d[i]-w[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) p[i]=d[i]-w[i];
    sort(p+1,p+n+1);
    DFS(1);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]-1);
}