#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[100010];
const int INF = 1e9;
multiset<int>f[400010];
int delta[400010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    int GLOBAL = 0;
    multiset<int>allset;
    f[0].insert(1);
    allset.insert(1);
    int ans = -INF;
    for (int i=2;i<=N;i++) {
        /*
        printf("i = %d GLOBAL = %d\n",i,GLOBAL);
        puts("allset:");
        for (auto &t:allset) printf("%d ",t);
        puts("");
        for (int j=0;j<=N;j++) {
            if (!f[j].empty()) {
                printf("%d: ",j);
                for (auto &t:f[j]) printf("%d ",t);
                puts("");
            }
        }*/
        int tmp = -1;
        if (!f[a[i]].empty()) {
            tmp = *f[a[i]].rbegin();
            allset.erase(allset.find(tmp));
        }
        int fuck = *allset.rbegin() + GLOBAL + 1;
        if (!f[a[i]].empty()) {
            fuck = max(fuck, tmp + GLOBAL);
            allset.insert(tmp);
        }
        if (a[i] != a[i - 1]) {
            GLOBAL++;
        }
        if (!f[a[i-1]].empty()) {
            allset.erase(allset.find(*f[a[i-1]].rbegin()));
        }
        f[a[i-1]].insert(fuck - GLOBAL);
        allset.insert(*f[a[i-1]].rbegin());
    }
    printf("%d\n",*allset.rbegin() + GLOBAL);
}