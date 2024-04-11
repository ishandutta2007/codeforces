#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b%a,a);
}

int n;
int arr[150100], brr[150100];
queue<int> lis;

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++)scanf("%d%d",&arr[i],&brr[i]);
    lis.push(0);
    int j;
    for (i=0;i<n;i++) {
        int sz = lis.size();
        for (j=0;j<sz;j++) {
            int p = lis.front(); lis.pop();
            int a = gcd(p,arr[i]), b = gcd(p,brr[i]);
            if (a>b) swap(a,b);
            if (b%a==0) a = -1;
            if (a==1) a = -1;
            if (b==1) b = -1;
            if (~a) lis.push(a);
            if (~b) lis.push(b);
        }
    }
    if (lis.empty()) printf("-1\n");
    else printf("%d\n",lis.front());

    return 0;
}