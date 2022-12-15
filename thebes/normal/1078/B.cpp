#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int cnt[MN*MN][MN]={1}, N, i, j, x;
map<int,int> mp;

int main(){
    for(scanf("%d",&N),i=1;i<=N;i++){
        scanf("%d",&x); mp[x]++;
    }
    for(auto v : mp){
        for(int i=MN*MN-1;i>=0;i--){
            for(int j=1;j<=v.second&&i-j*v.first>=0;j++){
                for(int k=0;k<=N-j;k++)
                    cnt[i][k+j]+=cnt[i-j*v.first][k];
            }
        }
    }
    int ans = 0; bool fl=0;
    for(auto v : mp){
        for(int i=1;i<=v.second;i++){
            if(cnt[i*v.first][i]==1){
                ans = max(ans, i);
                if(i==v.second) fl=1;
            }
        }
    }
    if(mp.size()==2&&fl) printf("%d\n",N);
    else printf("%d\n",ans);
    return 0;
}