#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
int arr[110];
int D[110][10100];
int E[110][10100];
int F[110][10100];

int main() {
    int i, j, k;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    D[0][0] = 1;
    for (i=0;i<n;i++) {
        if (i==0||arr[i]!=arr[i-1]) {
            for (j=0;j<=i+1;j++) {
                for (k=0;k<=100*j;k++) {
                    E[j][k] = 1;
                    F[j][k] = 0;
                }
            }
        }
        else {
            for (j=0;j<=i+1;j++) {
                for (k=0;k<=100*j;k++) {
                    E[j][k] = F[j][k];
                    F[j][k] = 0;
                }
            }
        }
        for (j=i+1;j>0;j--) {
            for (k=arr[i];k<=100*j;k++) {
                if (E[j-1][k-arr[i]]&&D[j-1][k-arr[i]]) {
                    D[j][k] += D[j-1][k-arr[i]];
                    D[j][k] = min(D[j][k],2);
                    F[j][k] = 1;
                }
            }
        }
    }
    int p = 0, s = 0, val = 0;
    for (i=0;i<n;i++) {
        s += arr[i];
        if (D[i-p+1][s]==1) {
            int tv = i-p+1;
            for (j=0;j>=p&&j<=i;j++);
            int t = arr[j], fl = 0;
            for (;j<n;j++) if (t!=arr[j]) {
                fl=1; break;
            }
            if (!fl) tv = n;
            val = max(val,tv);
        }
        if (i!=n-1&&arr[i]!=arr[i+1]) {
            p = i+1;
            s = 0;
        }
    }
    printf("%d\n",val);

    return 0;
}