#include<bits/stdc++.h>

typedef long long ll;

char s[10];

bool ask(ll l, ll r){
    printf("%lld %lld\n", l, r);
    fflush(stdout);
    scanf("%s", s);
    if (!strcmp(s, "Bad")){
        exit(0);
    }
    if (!strcmp(s, "Yes")){
        if (l == r){
            exit(0);
        }
        return true;
    }
    return false;
}

int main(){
    srand((unsigned) time(NULL));
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll l = 1, r = n;
    while (true){
        if (r - l > 50){
            ll mid = l + r >> 1;
            if (ask(l, mid)){
                r = mid + k;
                l -= k;
            }
            else{
                l = mid - k;
                r += k;
            }
        }
        else{
            ll sit = l + rand() % (r - l + 1);
            ask(sit, sit);
            l -= k;
            r += k;
        }
        l = std::max(1ll, l);
        r = std::min(n, r);
    }
    return 0;
}