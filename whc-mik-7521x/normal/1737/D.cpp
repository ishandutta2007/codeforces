#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int t,n,m,dis[N][N];
long long ans;
struct edge{
    int x,y,w;
};
vector<edge>v;
void init(){
    ans=1e18;
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            dis[i][o]=1e9;
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
	while(t--){
        cin>>n>>m;
        v.resize(m);
        init();
        for(auto &[x,y,w]:v)cin>>x>>y>>w,dis[x][y]=dis[y][x]=1;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int o=1;o<=n;o++){
                    dis[i][o]=min(dis[i][k]+dis[k][o],dis[i][o]);
                }
            }
        }
        for(auto [x,y,w]:v){
            for(int i=1;i<=n;i++){
                ans=min(ans,1ll*w*(min(dis[x][i],dis[y][i])+dis[i][1]+dis[i][n]+2));
            }
        }
        for(auto [x,y,w]:v){
            ans=min(ans,1ll*w*(1+min(dis[x][1]+dis[y][n],dis[x][n]+dis[y][1])));
        }
        cout<<ans<<endl;
    }
	return 0;
}