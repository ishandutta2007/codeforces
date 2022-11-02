#include <cstdio>

using namespace std;

int n,m,put;
int w[500];
int b[1000];
int o[500];
int placed[500];

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&w[i]);
    for (int i=0;i<m;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++) placed[i] = 0;
    for (int i=0;i<m;i++) {
        if (!placed[b[i]-1]) {
            placed[b[i]-1] = 1;
            o[put] = b[i]-1;
            put+=1;
        }
    }
    long long ans = 0;
    for (int i=0;i<m;i++) {
        int where;
        for (where=0;o[where]!=b[i]-1;where++) ans+=w[o[where]];
        for (int j=where-1;j>=0;j--) o[j+1] = o[j];
        o[0] = b[i]-1;
    }
    printf("%I64d\n",ans);

    return 0;
}