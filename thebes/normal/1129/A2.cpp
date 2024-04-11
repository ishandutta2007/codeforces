#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
vector<int> pos[MN];
int n, m, i, x, y, ans, j;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y); x--; y--;
        pos[x].push_back(y);
    }
    for(i=0;i<n;i++){
        ans = 0;
        for(j=0;j<n;j++){
            int p = (i+j)%n;
            int mn = 1<<30;
            for(auto v : pos[p]){
                int t = v-p;
                if(t<0) t += n;
                mn = min(mn, t);
            }
            if(pos[p].size()){
                ans = max(ans, j+((int)pos[p].size()-1)*n+mn);
            }
        }
        printf("%d ",ans);
    }
    printf("\n");
    return 0;
}