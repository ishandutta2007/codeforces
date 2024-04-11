#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int arr[10];

bool issq(int n) {
    if (n<=0)return false;
    int i;
    for (i=1;i*i<=n;i++) {
        if (i*i==n) return true;
    }
    return false;
}

int main() {
    int i;

    scanf("%d",&n); i=0;
    while(n) {
        arr[i] = n%10;
        n/=10; i++;
    }
    n = i;
    reverse(arr,arr+n);
    int mini = 100;
    for (i=0;i<(1<<n);i++) {
        int bit = i, res = 0, cnt = 0, pos = 1;
        for (int j=0;j<n;j++){
            if (bit&(1<<j)) {
                if (!cnt&&!arr[j]) {
                    pos = 0;
                }
                res *= 10;
                res += arr[j];
                cnt++;
            }
        }
        if (!pos) continue;
        if (issq(res)) {
            mini = min(mini,n-cnt);
        }
    }
    if (mini>55) {
        printf("-1\n");
    }
    else printf("%d\n",mini);

    return 0;
}