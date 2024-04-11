#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int arr[300100];
int divi[15000010];
int cnt[15000010];

int gcd(int a, int b) {
    return a?gcd(b%a,a):b;
}

int main() {
    int i;

    int j;
    for (i=2;i<=15000000;i++) {
        if (divi[i]) continue;
        for (j=i;j<=15000000;j+=i) divi[j] = i;
    }
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    int g = 0;
    for (i=0;i<n;i++) g = gcd(g,arr[i]);
    for (i=0;i<n;i++) arr[i]/=g;
    int flag = 1;
    for (i=0;i<n;i++) {
        if (arr[i]!=1) flag = 0;
    }
    if (flag) {
        printf("-1\n");
        return 0;
    }
    for (i=0;i<n;i++) {
        int p = arr[i];
        while(p!=1) {
            int q = divi[p];
            while(divi[p]==q) p/=divi[p];
            cnt[q]++;
        }
    }
    int maxi = 0;
    for (i=0;i<=15000000;i++) {
        maxi = max(maxi,cnt[i]);
    }
    printf("%d\n",n-maxi);

    return 0;
}