#include<bits/stdc++.h>
using namespace std;
#define pi pair<int ,int >
#define mcp(x,y) make_pair(x,y)
const int N = 1e5+9;
int n,a[N],sum[N],lst[N],cnt[2],prs[N];
struct pp{int pre,val,id;}p[N];
int Min(int x,int y){if(y==-1) return x;if(x==-1) return y;return x>y?y:x;}
map<int ,int >mp[2];
vector<pi >vec[2];
int main(){
    memset(sum,0,sizeof(sum));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
    int ans=-1;
    for(int t=30;t>=0;t--){
        mp[0].clear();mp[1].clear();
        for(int i=1;i<=n;i++){
            p[i].val=(sum[i]>>t)&1;
            p[i].pre=(sum[i]>>(t+1));
        }
        int area=-1;cnt[0]=-1,cnt[1]=-1;mp[0][0]=1;
        vec[0].clear();vec[1].clear();vec[0].push_back(mcp(0,1));
        for(int i=1;i<=n;i++){
            int t=mp[p[i].val^1][p[i].pre];
            if(t&&t<=cnt[p[i].val]) 
                area=Min(area,i-t-1);
            if(p[i].val) cnt[1]=i;
            else cnt[0]=i;
            for(int j=0;j<vec[p[i].val^1].size();j++){
                pi tmp=vec[p[i].val^1][j];
                mp[p[i].val^1][tmp.first]=tmp.second;
            }
            vec[p[i].val^1].clear();
            vec[p[i].val].push_back(mcp(p[i].pre,i+1));
        }
        ans=Min(ans,area);
    }
    printf("%d\n",ans);
    return 0;
}