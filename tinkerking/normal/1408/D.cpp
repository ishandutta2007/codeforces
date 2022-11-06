#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
pii r[2010],s[2010];
const int INF = 1e9;
const int MX = 1000000;
int my[MX + 10];


int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) scanf("%d%d",&r[i].first,&r[i].second);
    for (int i=1;i<=M;i++) scanf("%d%d",&s[i].first,&s[i].second);
    s[M+1] = pii(-INF, INF);
    s[M+2] = pii(INF, -INF);
    M += 2;
    sort(s+1,s+M+1);
    for (int i=1;i<M;i++) {
        if (i > 1 && s[i].first == s[i-1].first) continue;
        for (int j=1;j<=N;j++) {
            int dx = s[i].first + 1 - r[j].first;
            int dy = max(0, s[i+1].second + 1 - r[j].second);
            //printf("%d %d %d %d\n",i,j,dx,dy);
            dx = min(dx, MX + 1);
            if (dx>=0) my[dx] = max(my[dx], dy);
            dx = s[i].first - r[j].first;
            dy = max(0, s[i].second + 1 - r[j].second);
            dx = min(dx, MX + 1);
            if (dx>=0) my[dx] = max(my[dx], dy);
            //printf("%d %d %d %d\n",i,j,dx,dy);
        }
    }
    int ans = 1e9;
    for (int i=MX+1;i>=0;i--) {
        my[i] = max(my[i + 1], my[i]);
        ans = min(ans, i + my[i]);
    }
    printf("%d\n",ans);
}