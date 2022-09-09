#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k, q;
int ps[200100];
int cnt[200100];

int main() {
    int i;

    scanf("%d%d%d",&n,&k,&q);
    for (i=0;i<n;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        ps[a]++; ps[b+1]--;
    }
    for (i=1;i<=200050;i++) ps[i] += ps[i-1];
    for (i=1;i<=200050;i++) cnt[i] = (ps[i]>=k);
    for (i=1;i<=200050;i++) cnt[i] += cnt[i-1];
    for (i=0;i<q;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        printf("%d\n",cnt[b]-cnt[a-1]);
    }

    return 0;
}