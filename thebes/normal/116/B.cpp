#include <bits/stdc++.h>
using namespace std;

const int MN = 20;
int N, M, i, j, k, a[MN][MN], ans;
int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

int main(){
    for(scanf("%d%d",&N,&M),i=1;i<=N;i++){
        for(getchar(),j=1;j<=M;j++){
            char c = getchar();
            if(c=='W') a[i][j]=2;
            else if(c=='P') a[i][j]=1;
        }   
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            if(a[i][j]!=1) continue;
            for(k=0;k<4;k++){
                int x = i+dx[k], y = j+dy[k];
                if(x<1||x>N||y<1||y>M) continue;
                if(a[x][y]==2){
                    a[x][y]=0;
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}