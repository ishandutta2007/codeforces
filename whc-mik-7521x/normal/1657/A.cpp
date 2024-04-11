#include<bits/stdc++.h>
using namespace std;
const int N=55;
int ans[N][N];
bool check(int x,int y){
    int now=sqrt(x*x+y*y);
    if(x*x+y*y==now*now)return 1;
    return 0;
}
int main(){
    memset(ans,-1,sizeof ans);
    queue<pair<int,int>>q;
    ans[0][0]=0;
    q.push({0,0});
    while(q.size()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<N;i++){
            for(int o=0;o<N;o++){
                if(ans[i][o]==-1&&check(x-i,y-o))ans[i][o]=ans[x][y]+1,q.push({i,o});
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[x][y]);
    }
    return  0;
}