#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
map<pair<int,int>,int> id;
int n, i, j, u[MN], x, y;
pair<int,int> pos[MN], a[MN];

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++)
        scanf("%d%d",&pos[i].first,&pos[i].second),id[pos[i]]=i;
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    for(i=1;i<=n;i++){
        bool fnd = 0;
        memset(u,0,sizeof(u));
        x=pos[1].first+a[i].first,y=pos[1].second+a[i].second;
        u[1]=1;
        for(j=1;j<=n;j++){
            if(i==j) continue;
            if(!id.count({x-a[j].first,y-a[j].second})){
                fnd = 1;
                break;
            }
            int idx = id[{x-a[j].first,y-a[j].second}];
            if(u[idx]){fnd=1; break;}
            else u[idx]=1;
        }
        if(!fnd){
            printf("%d %d\n",x,y);
            return 0;
        }
    }
}