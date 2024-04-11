#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
pii arr[4];
pii brr[4];

int main() {
    int i;

    for (i=0;i<4;i++) {
        scanf("%d%d",&arr[i].first,&arr[i].second);
    }
    for (i=0;i<4;i++) {
        scanf("%d%d",&brr[i].first,&brr[i].second);
        brr[i] = pii(brr[i].first+brr[i].second,brr[i].first-brr[i].second);
    }
    int mx = min(arr[0].first,arr[2].first), Mx = max(arr[0].first,arr[2].first), my = min(arr[0].second,arr[2].second), My = max(arr[0].second,arr[2].second);
    int mmx = min(brr[0].first,brr[2].first), MMx = max(brr[0].first,brr[2].first), mmy = min(brr[0].second,brr[2].second), MMy = max(brr[0].second,brr[2].second);

        bool flag = 0;
    for (i=mx;i<=Mx;i++) {
        for (int j=my;j<=My;j++) {
            if (mmx<=i+j&&i+j<=MMx&&mmy<=i-j&&i-j<=MMy) {
                flag = 1;
            }
        }
    }
    puts(flag?"YES":"NO");

    return 0;
}