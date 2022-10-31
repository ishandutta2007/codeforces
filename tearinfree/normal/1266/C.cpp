#include <bits/stdc++.h>
using namespace std;

int n,m, ret[500][500];

int main() {
    scanf("%d%d",&n,&m);

    if(n==1 && m==1) {
        puts("0");
        return 0;
    } else if (m == 1) {
        for(int i=0;i<n;i++) {
            printf("%d\n",i+2);
        }
        return 0;
    }
    
    for(int j=0;j<m;j++) ret[0][j] = j+2;
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            ret[i][j] = (j+2)*(m+i+1);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) printf("%d ",ret[i][j]);
        puts("");
    }
    
    return 0;
}