#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e7;
int n;
int arr[1000100];
ll mini = 1LL<<62;
ll p, q;
bitset<MAX+10> chk;
ll gcd(ll a, ll b) {
    return a?gcd(b%a,a):b;
}

int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (chk[arr[i]]) {
            if (mini>arr[i]) {
                mini=arr[i];
                p = q = arr[i];
            }
        }
        chk.set(arr[i]);
    }
    for (i=1;i<=MAX;i++) {
        int cnt = 0;
        ll tmp[2];
        for (j=i;j<=MAX;j+=i) {
            if (chk[j]) tmp[cnt++] = j;
            if (cnt==2) {
                if (mini>tmp[0]*tmp[1]/gcd(tmp[0],tmp[1])){
                    mini=tmp[0]*tmp[1]/gcd(tmp[0],tmp[1]);
                    p=tmp[0];q=tmp[1];
                }
                break;
            }
        }
    }
    int t = -1, s = -1;
    for (i=0;i<n;i++) if (arr[i]==p) {
        t=i;
        break;
    }
    for (i=0;i<n;i++) if (arr[i]==q&&i!=t) {
        s=i;
        break;
    }
    printf("%d %d\n",min(t,s)+1,max(t,s)+1);

    return 0;
}