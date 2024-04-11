#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,t,mp[N][N],a[N][N],tot;
void cl(int x,int y){
    tot^=a[x][y];
    mp[x][y-1]^=1;
    mp[x-1][y]^=1;
    mp[x][y+1]^=1;
    mp[x+1][y]^=1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=n;o++){
                scanf("%d",&a[i][o]);
                mp[i][o]=0;
            }
        }
        for(int i=2;i<=n;i++){
            for(int o=1;o<=n;o++){
                if(!mp[i-1][o])cl(i,o);
            }
        }
        printf("%d\n",tot);
    }
    return  0;
}