#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
pii arr[20];
pii brr[20];
int num[30][20];
int chk[20];

int good(pii a, pii b) {
    if (a.first==b.first||a.first==b.second||a.second==b.first||a.second==b.second) {
        if ((a.first==b.first&&a.second==b.second)||(a.first==b.second&&a.second==b.first)) return 0;
        int t = -1;
        if (a.first==b.first||a.first==b.second) t = a.first;
        else t = a.second;
        return t;
    }
    return 0;
}

int main() {
    int i, j, t = -1;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) scanf("%d%d",&arr[i].first,&arr[i].second);
    for (i=0;i<m;i++) scanf("%d%d",&brr[i].first,&brr[i].second);
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            int k=-1;
            if (k=good(arr[i],brr[j])) {chk[k]=1;num[i][k]++;num[n+j][k]++;}
        }
    }
    int sum = 0, flag = 0;
    for (i=0;i<n+m;i++) {
        int ts = 0;
        for (j=0;j<10;j++) if (num[i][j]) ts++;
        if (ts>1) flag = 1;
    }
    for (i=0;i<10;i++) {
        sum += chk[i];
        if (chk[i]) t =i;
    }
    if (flag) {
        printf("-1\n");
        return 0;
    }
    if (sum>1) {
        printf("0\n");
        return 0;
    }
    printf("%d\n",t);

    return 0;
}