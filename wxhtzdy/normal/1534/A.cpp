#include <bits/stdc++.h>
#define maxn 55
using namespace std;
char c[55][55];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%s",c[i]);
        }
        for(int i=0;i<2;i++) {
            bool valid=true;
            for(int x=0;x<n;x++) {
                for(int y=0;y<m;y++) {
                    int a=(i+x+y)%2;
                    if(c[x][y]=='W')a=0;
                    if(c[x][y]=='R')a=1;
                    if(a!=(i+x+y)%2) {
                        valid=false;
                    }
                }
            }
            if(valid) {
                printf("YES\n");
                for(int x=0;x<n;x++) {
                    for(int y=0;y<m;y++) {
                        if((i+x+y)%2==0) printf("W");
                        else printf("R");
                    }
                    printf("\n");
                }
                break;
            }
            if(i==1) {
                printf("NO\n");
            }
        }
    }
    return 0;
}