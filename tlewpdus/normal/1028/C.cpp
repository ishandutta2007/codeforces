#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int arr[4][150000];
int brr[4][150000];
int crr[4][150000];
int INF = 1e9+10;

void solve(int arr[], int brr[], int crr[]) {
    int i;
    brr[0] = -INF;
    for (i=1;i<=n;i++) brr[i] = max(brr[i-1],arr[i]);
    crr[n+1] = -INF;
    for (i=n;i>0;i--) crr[i] = max(crr[i+1],arr[i]);
}

int main() {
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        for (int j=0;j<4;j++) scanf("%d",&arr[j][i]);
        arr[2][i] *= -1;
        arr[3][i] *= -1;
    }
    for (i=0;i<4;i++) solve(arr[i],brr[i],crr[i]);
    for (i=1;i<=n;i++) {
        int a = max(brr[0][i-1],crr[0][i+1]);
        int b = max(brr[2][i-1],crr[2][i+1]);
        if (a>-b) continue;
        a = max(brr[1][i-1],crr[1][i+1]);
        b = max(brr[3][i-1],crr[3][i+1]);
        if (a>-b) continue;
        printf("%d %d\n",max(brr[0][i-1],crr[0][i+1]), max(brr[1][i-1],crr[1][i+1]));
        break;
    }

    return 0;
}