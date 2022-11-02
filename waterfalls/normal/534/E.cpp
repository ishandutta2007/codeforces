#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int a[200013];
int dist[200013];
int b[400013];
int cnt[200013][10];
int ok[10];
long long res[10];

long long go(int x, int dir, int which) {
    cnt[x][which]-=1;
    int next = x+dir;
    if (next==-1) next = 1, dir*=-1;
    if (next==n) next = n-2, dir*=-1;
    if (cnt[next][which]==0) return 0;
    long long add = (dir==1) ? dist[x] : dist[x-1];
    return add+go(next,dir,which);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) dist[i] = a[i+1]-a[i];
    scanf("%d",&m);
    for (int i=0;i<m;i++) scanf("%d",&b[i]);
    for (int i=0;i<m;i++) b[i]-=1;
    for (int i=0;i<m;i++) cnt[b[i]][0]+=1;
    for (int i=0;i<n;i++) for (int j=1;j<10;j++) cnt[i][j] = cnt[i][0];
    long long ans = 0;
    int start = -1;
    for (int i=1;i<n-1;i++) {
        if (i!=1 && cnt[i][0]>cnt[i-1][0]) {
            start = i;
            break;
        }
        if (i!=n-2 && cnt[i][0]>cnt[i+1][0]) {
            start = i;
            break;
        }
    }
    if (start==-1) {
        res[1] = go(0,1,1);
        res[2] = go(1,1,2);
        res[3] = go(1,-1,3);
        res[4] = go(n-2,-1,4);
        res[5] = go(n-2,1,5);
        res[6] = go(n-1,-1,6);
        int bad = n-1;
        for (int i=1;i<n;i++) if (dist[i]!=dist[0]) { bad = i; break; }
        res[7] = go(bad,-1,7);
        for (int i=1;i<=7;i++) ok[i] = 1;
        for (int i=1;i<=7;i++) for (int j=0;j<n;j++) if (cnt[j][i]) ok[i] = 0;
        ans = -2;
        for (int i=1;i<=7;i++) if (ok[i]) {
            if (ans==-2) ans = res[i];
            else if (ans!=res[i]) ans = -1;
        }
    } else {
        long long one = go(start,-1,1);
        int ok1 = 1;
        for (int i=0;i<n;i++) if (cnt[i][1]) ok1 = 0;
        long long two = go(start,1,2);
        int ok2 = 1;
        for (int i=0;i<n;i++) if (cnt[i][2]) ok2 = 0;
        if (!ok1) one = two;
        if (!ok2) two = one;
        if (one!=two) ans = -1;
        else ans = one;
    }

    printf("%I64d\n",ans);

    return 0;
}