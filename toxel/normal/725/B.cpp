#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll n;
    char ch;
    scanf("%lld%c", &n, &ch);
    -- n;
    ll ans = n / 4 * 16;
    n %= 2;
    ans += n == 1 ? 7 : 0;
    switch (ch){
        case 'e' : ans += 1; break;
        case 'd' : ans += 2; break;
        case 'a' : ans += 3; break;
        case 'b' : ans += 4; break;
        case 'c' : ans += 5; break;
    }
    printf("%lld\n", ans + 1);
    return 0;
}