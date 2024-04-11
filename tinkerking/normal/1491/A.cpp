#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int a[100010];
int n, q;
int cnt[2];
int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    while(q--) {
        int tp, v;
        scanf("%d%d",&tp,&v);
        if (tp == 1) {
            cnt[a[v]]--;
            cnt[a[v]^1]++;
            a[v] ^= 1;
        } else {
            puts(cnt[1] >= v ? "1" : "0");
        }
    }
}