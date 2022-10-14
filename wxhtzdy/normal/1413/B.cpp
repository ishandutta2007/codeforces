#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,m;
        scanf("%i %i",&n,&m);
        int a[n][m],b[m][n];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]);
        map<int,int> pos;
        int x;
        for(int i=0;i<m;i++){
            bool ok=0;
            for(int j=0;j<n;j++){
                scanf("%i",&b[i][j]);
                if(b[i][j]==a[0][0])ok=1;
            }
            if(ok){
                x=i;
                for(int j=0;j<n;j++)pos[b[i][j]]=j;
            }
        }
        int ans[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[pos[a[i][0]]][j]=a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)printf("%i ",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}