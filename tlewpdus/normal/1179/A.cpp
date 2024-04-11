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

int n, q;
deque<int> dq;
pii arr[100100];
int brr[100100];

int main() {
    int i;

    scanf("%d%d",&n,&q);
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        dq.push_back(a);
    }
    for (i=0;i<n;i++) {
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        arr[i] = pii(a,b);
        if (a>b) {
            dq.push_front(a);
            dq.push_back(b);
        }
        else {
            dq.push_front(b);
            dq.push_back(a);
        }
    }
    int mm = dq.front();
    dq.pop_front();
    int c = 0;
    while(!dq.empty()) {
        brr[c++] = dq.front();
        dq.pop_front();
    }
    for (i=0;i<q;i++) {
        ll m;
        scanf("%lld",&m); m--;
        if (m<n) {
            printf("%d %d\n",arr[m].first,arr[m].second);
        }
        else {
            printf("%d %d\n",mm,brr[(m-n)%(n-1)]);
        }
    }

    return 0;
}