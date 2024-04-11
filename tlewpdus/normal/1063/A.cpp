#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[100100];

int main() {
    int i;

    scanf("%d",&n);
    scanf("%s",str);
    sort(str,str+n);
    printf("%s\n",str);

    return 0;
}