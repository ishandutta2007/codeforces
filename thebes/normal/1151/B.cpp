#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int p[MN][1<<10], l[MN][1<<10], n, m, i, j, arr[MN][MN];
vector<int> rev;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        for(j=1;j<=m;j++) scanf("%d",&arr[i][j]);
    }
    p[0][0]=-1; l[0][0]=-1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(int k=0;k<(1<<10);k++){
                if(l[i-1][arr[i][j]^k]){
                    p[i][k]=arr[i][j]^k;
                    l[i][k]=j;
                }
            }
        }
    }
    int lol = -1;
    for(i=1;i<(1<<10);i++){
        if(l[n][i]){
            printf("TAK\n");
            lol = i; j = n;
            while(lol!=-1&&j>0){
                rev.insert(rev.begin(),l[j][lol]);
                lol = p[j][lol]; j--;
            }
            for(auto v : rev) printf("%d ",v);
            printf("\n");
            return 0;
        }
    }
    printf("NIE\n");
    return 0;
}