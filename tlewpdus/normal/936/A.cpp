#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll k, d, t;

int main() {
    scanf("%llu%llu%llu",&k,&d,&t);
    t*=2;
    ll f = d*(k/d+(k%d!=0))-k;
    ll res = t/(2*k+f)*(k+f);
    t %= (2*k+f);
    if (t<=2*k) printf("%llu.%llu\n",res+t/2,t%2*5);
    else printf("%llu.%llu\n",res+k+t-2*k,0ULL);

    return 0;
}