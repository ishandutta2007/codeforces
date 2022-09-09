#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll p, q, b;

ll gcd(ll a, ll b) {
    return ((a==0)?b:gcd(b%a,a));
}

int main() {
    int n;

    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lld%lld%lld",&p,&q,&b);
        ll g = gcd(p,q);
        p/=g;q/=g;
        ll t;
        t = gcd(b,q);
        while(t!=1) {
            q/=t;
            if (q%t!=0) t = gcd(b,q);
        }
        if (q==1) printf("Finite\n");
        else printf("Infinite\n");
    }


    return 0;
}