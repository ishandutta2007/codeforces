#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[200010];
vector<int>pos[5000100];
int cnt[5000010];
vector<int>fuck;
pii can[5000100];

void check(int x, int y, int z, int w) {
    if (x == y || x == z || x == w || y == z || y == w || z == w) return;
    puts("YES");
    printf("%d %d %d %d\n",x,y,z,w);
    exit(0);
}

int main() {
    scanf("%d",&N);
    int BIGCNT = 0;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            BIGCNT++;
            fuck.push_back(a[i]);
        }
        pos[a[i]].push_back(i);
    }
    if (fuck.size() > 1) {
        int v1 = fuck[0], v2 = fuck[1];
        puts("YES");
        printf("%d %d %d %d\n",pos[v1][0], pos[v2][0], pos[v1][1], pos[v2][1]);
        return 0;
    }
    for (int i=0;i<=5000001;i++) can[i] = pii(-1, -1);
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            int target = a[i] + a[j];
            if (can[target].first == -1) {
                can[target] = pii(i, j);
            } else {
                check(i, j, can[target].first, can[target].second);
            }
        }
    }
    puts("NO");
}