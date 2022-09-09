#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int par[100100];
int dep[100100];
int cnt[100100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=1;i<n;i++) {
        scanf("%d",&par[i]); par[i]--;
    }
    dep[0] = 0;
    for (i=1;i<n;i++) dep[i] = dep[par[i]]+1;
    for (i=0;i<n;i++) cnt[dep[i]]^=1;
    int res =0;
    for (i=0;i<n;i++) res+=cnt[i];
    printf("%d\n",res);

    return 0;
}