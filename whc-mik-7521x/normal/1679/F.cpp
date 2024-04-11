#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,mod=998244353;
int n,m,mp[10][10],dp[2][1<<10],trans[1<<10][10];
vector<pair<int,int>>v;
void init(){
    set<pair<int,int>>st;
    for(int i=0;i<1<<10;i++){
        for(int o=0;o<10;o++){
            int msk=1<<o;
            for(int k=0;k<10;++k){
                if(((1<<k)&i)&&mp[k][o])msk|=1<<k;
            }
            if((1<<(o+1))<msk)trans[i][o]=-1;
            else trans[i][o]=msk,st.insert({i,o});
        }
    }
    for(auto it:st)v.push_back(it);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<10;i++)mp[i][i]=1;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=mp[y][x]=1;
    }
    init();
    for(int o=1;o<1<<10;o<<=1)dp[1][o]=1;
    for(int i=1;i<n;i++){
        for(int o=0;o<1<<10;o++){
            dp[(i+1)&1][o]=dp[i&1][o];
        }
        for(auto [o,k]:v){
            if(!(o&(1<<k))&&trans[o][k]!=-1)(dp[(i+1)&1][trans[o][k]]+=dp[i&1][o])%=mod;
        }
    }
    int ans=0;
    for(int i=0;i<1<<10;i++) {
        ans=(ans+dp[n&1][i])%mod;
    }
    printf("%d",ans);
    return 0;
}