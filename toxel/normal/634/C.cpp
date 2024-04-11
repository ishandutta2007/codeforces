#include<bits/stdc++.h>

typedef long long ll;
const int N = 200010;

ll c[2][N];

void add(ll *c, int sit, int value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
    }
}

ll query(ll *c, int sit){
    ll ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

ll x[N];

int main(){
    int n, k, a, b, q;
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int d, val;
            scanf("%d%d", &d, &val);
            add(c[0], d, std::min(x[d] + val, (ll) a) - std::min(x[d], (ll) a));
            add(c[1], d, std::min(x[d] + val, (ll) b) - std::min(x[d], (ll) b));
            x[d] += val;
        }
        else{
            int p;
            scanf("%d", &p);
            printf("%lld\n", query(c[1], p - 1) + query(c[0], N - 1) - query(c[0], p + k - 1));
        }
    }
    return 0;
}