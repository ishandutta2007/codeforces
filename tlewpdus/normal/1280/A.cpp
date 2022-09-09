#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int x;
ll n;
char str[1234567];

void cop(int s, int e, int c) {
    n += 1LL*(e-s)*(c-1);
    if (e>x+10) {
        return;
    }
    for (int i=1;i<c;i++) {
        for (int j=s;j<e;j++) {
            if (j+(e-s)*i>=x+10) break;
            str[j+(e-s)*i]=str[j];
        }
    }
}

int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%d",&x);
        scanf(" %s",str);
        n = strlen(str);
        int tl = x+1;
        for (int l=1;l<=x;l++) {
            if (n<=x) {
                cop(l,n,str[l-1]-'0');
            }
            else {
                tl = l;
                break;
            }
        }
        for (int l=tl;l<=x;l++) {
            n = (n+1LL*(n-l)*(str[l-1]-'0'-1))%MOD;
        }
        printf("%lld\n",(n%MOD+MOD)%MOD);
    }

	return 0;
}