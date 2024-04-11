#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
vector<int>q[N];
int cnt[N];
void solve(int x,int y){
    if(x>n)return;
    if(y>m){
        solve(x+1,y-1);
        return;
    }
    if(cnt[x+y]<0){
        solve(x+1,y+1);
        return;
    }
    int nx=q[x+y][cnt[x+y]];
    int ny=x+y-nx;
    if(nx<x){
        solve(x+1,y+1);
        return;
    }
    for(;cnt[x+y]>=0;cnt[x+y]--){
        if(q[x+y][cnt[x+y]]<x)break;
    }
    solve(nx+1,ny+1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                int x;
                scanf("%1d",&x);
                if(x)q[i+o].push_back(i);
            }
        }
        for(int i=2;i<=n+m;i++)cnt[i]=(int)q[i].size()-1;
        int ans=0;
        for(int i=1;i<=m;i++){
            if(cnt[i+1]!=-1)solve(1,i),ans++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i+m]!=-1)solve(i,m),ans++;
        }
        printf("%d\n",ans);
        for(int i=2;i<=n+m;i++)q[i].clear();
    }
    return  0;
}