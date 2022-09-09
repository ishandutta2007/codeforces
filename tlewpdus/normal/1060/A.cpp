#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[110];

int main() {
    int i;
    scanf("%d",&n);
    scanf("%s",str);
    int cnt = 0;
    for (i=0;i<n;i++) if (str[i]=='8') cnt++;
    printf("%d\n",min(cnt,n/11));

    return 0;
}