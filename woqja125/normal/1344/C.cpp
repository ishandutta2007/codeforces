#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

void fail() {
    printf("-1\n");
    exit(0);
}

const int N = 200001;

vector<int> ed[N];
vector<int> edr[N];

int chk[N], chkr[N];

void dfs(int x) {
    if(chk[x] == -1) fail();
    if(chk[x]) return;
    chk[x] = -1;
    for(int e: ed[x]) {
        dfs(e);
    }
    chk[x] = 1;
}

void dfsr(int x) {
    if(chkr[x] == -1) fail();
    if(chkr[x]) return;
    chkr[x] = -1;
    for(int e: edr[x]) {
        dfsr(e);
    }
    chkr[x] = 1;
}

char ans[N];

int main() {
    int n, m;
    int cnt = 0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ed[x].push_back(y);
        edr[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        ans[i-1] = 'E';
        if(chk[i] == 0 && chkr[i] == 0) {
            cnt++;
            ans[i-1] = 'A';
        }
        dfs(i);
        dfsr(i);
    }

    ans[n] = 0;
    printf("%d\n%s\n", cnt, ans);
    return 0;
}