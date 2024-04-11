#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;
ll memo[2002][2002];
ll acc[2002][2002];
char s[2002];

int main() {
        int k, i, sum, pref;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        

        acc[0][0] = memo[0][0] = s[i] - 'a';
        acc[0][n] = memo[0][n] = 'z' - s[i];
        for(i = 1; i < n; i++)
                for(sum = 0; sum <= k; sum++) {
                        memo[i][sum] = (s[i] - 'a') * (sum == 0);
                        memo[i][sum] += (s[i] - 'a') * acc[i - 1][sum];
                        for(pref = 0; pref < i && sum >= (n - i) * (pref + 1); pref++)
                                memo[i][sum] += ('z' - s[i]) * memo[i - pref - 1][sum - (n - i) * (pref + 1)];
                        if(sum == (n - i) * (i + 1)) memo[i][sum] += ('z' - s[i]);
                        memo[i][sum] = mod(memo[i][sum]);
                        acc[i][sum] = mod(memo[i][sum] + acc[i - 1][sum]);
                }
        int tot = 0;
        for(i = 0; i < n; i++)
                tot = mod(tot + memo[i][k]);
        if(k == 0) tot++;
        printf("%d\n", tot);
}