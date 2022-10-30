#include <cstdio>
#include <algorithm>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,m;
bool know[4013][4013];
int tot[4013];
pair<int,int> has[4013];

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        know[a][b] = know[b][a] = 1;
        has[i] = MP(a,b);
        tot[a]+=1;
        tot[b]+=1;
    }
    int ans = 1e9;
    for (int i=1;i<=n;i++) for (int j=0;j<m;j++) if (has[j].A!=i && has[j].B!=i) {
        if (know[i][has[j].A] && know[i][has[j].B]) ans = min(ans,tot[i]+tot[has[j].A]+tot[has[j].B]-6);
    }
    printf("%d\n",ans>1e8 ? -1 : ans);

    return 0;
}