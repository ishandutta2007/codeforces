#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,m;
        scanf("%i %i",&n,&m);
        int a[n][m];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)if((a[i][j]+i+j)%2==1)a[i][j]++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)printf("%i ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}