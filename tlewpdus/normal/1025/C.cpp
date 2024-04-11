#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[200100];

int main() {
    int i;

    scanf("%s",str);
    n = strlen(str);
    for (i=0;i<n;i++) {
        str[n+i] = str[i];
    }
    for (i=0;i<2*n;i++) str[i] = (str[i]=='w'?1:0);
    for (i=0;i<2*n;i++) str[i] ^= (i%2);
    int p = 0, ans = 1;
    for (i=0;i<2*n;i++) {
        if (i==2*n-1||str[i]!=str[i+1]) {
            ans = max(ans,i-p+1);
            p = i+1;
        }
    }
    printf("%d\n",min(ans,n));

    return 0;
}