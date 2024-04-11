#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
string ans;
int cnt[MN], w, n, m, i, j, x;

int main(){
    scanf("%d%d",&n,&m); w=n;
    for(i=1;i<=m;i++){
        scanf("%d",&x);
        cnt[x]++;
        if(cnt[x]==1) w--;
        if(w==0){
            for(j=1;j<=n;j++){
                cnt[j]--;
                if(cnt[j]==0) w++;
            }
            ans += '1';
        }
        else ans += '0';
    }
    printf("%s\n",ans.c_str());
    return 0;
}