#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k;
int arr[100100];
int en[100100], st[100100];

int main() {
    int i;

    scanf("%d%d",&n,&k);
    for (i=0;i<k;i++) {
        scanf("%d",&arr[i]);
    }
    memset(st,-1,sizeof(st));
    memset(en,-1,sizeof(en));
    for (i=k-1;i>=0;i--) {
        st[arr[i]] = i;
    }
    for (i=0;i<k;i++) {
        en[arr[i]] = i;
    }
    int cnt = 0;
    for (i=1;i<=n;i++) {
        if(st[i]<0) cnt++;
        if (i!=1&&(st[i]<0||st[i]>en[i-1])) cnt++;
        if (i!=n&&(st[i]<0||st[i]>en[i+1])) cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}