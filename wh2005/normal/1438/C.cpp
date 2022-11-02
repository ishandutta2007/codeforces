#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int t,n,m,a[N][N];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2==1&&a[i][j]%2==0) a[i][j]++;
                if((i+j)%2==0&&a[i][j]%2==1) a[i][j]++;
                printf("%d ",a[i][j]);
            }
            puts("");
        }
    }
    return 0;
}