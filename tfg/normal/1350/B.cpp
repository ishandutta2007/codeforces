#include  <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn], dp[maxn];

int solve(int pos){
    if(pos == 1) return 1;
    if(dp[pos] != -1) return dp[pos];

    int tot = 1;

    for(long long i=1; i*i<=(long long)pos; i++){
        if(pos%i == 0){
            if(vet[i] < vet[pos]) tot = max(tot, 1 + solve(i));
            if(pos/i != i and vet[pos/i] < vet[pos])tot = max(tot, 1 + solve(pos/i));
        }
    }

    return dp[pos] = tot;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> vet[i];
            dp[i] = -1;
        }

        int ans = 0;

        for(int i=1; i<=n; i++) ans = max(ans, solve(i));

        cout << ans << "\n";
    }

	return 0;
}