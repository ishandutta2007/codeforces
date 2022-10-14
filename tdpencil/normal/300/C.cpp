#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll m = 1e9 + 7;

const int M = 1e6;
ll f1[M], f2[M], D[M];

int N, A, B;
ll ans = 0;
bool good_string(string &s) {
    return count(s.begin(), s.end(), char('0' + A)) + count(s.begin(), s.end(), char('0' + B)) == s.size();
}
int main() {
    scanf("%d%d%d", &A, &B, &N);
    f1[0]=f1[1]=f2[0]=f2[1]=D[0]=D[1]=1;
    for (int i = 2; i <= N; i++) {
        D[i]=(D[m%i]*(m-m/i))%m;
        f1[i]=f1[i-1]*i%m;
        f2[i]=f2[i-1]*D[i]%m;
    }
    for (int i = 0; i <= N; i++) {
        int S = (i * A) + (N - i) * B;
        string template_string = to_string(S);
        if(good_string( template_string )) {
            ans += (f1[N]*f2[i]%m*f2[N-i])%m;
            ans%=m;
        }
    }
    printf("%lld\n", ans);
}