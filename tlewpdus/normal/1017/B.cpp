#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[100100], ttr[100100];
ll ans;
ll cnt[4];

int main() {
    int i;

    scanf("%d",&n);
    scanf("%s",str);
    scanf("%s",ttr);
    for (i=0;i<n;i++) {
        cnt[(str[i]-'0')*2+(ttr[i]-'0')]++;
    }
    printf("%lld\n",cnt[0]*cnt[3]+cnt[1]*cnt[2]+cnt[0]*cnt[2]);

    return 0;
}