#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 500;

int A[N], n;

void solve(){
        vector < tuple < int, int, int > > ans;
        for(int i = 0;i < n - 2;i += 2){
                ans.push_back({i, i + 1, i + 2});
                int x = A[i] ^ A[i + 1] ^ A[i + 2];
                A[i] = A[i + 1] = A[i + 2] = x;
        }
        for(int i = 0;i < n - 2;i += 2){
                ans.push_back({i, i + 1, n - 1});
                int x = A[i] ^ A[i + 1] ^ A[n - 1];
                A[i] = A[i + 1] = A[n - 1] = x;
        }
        for(int i = 0;i < n;i++){
                assert(A[i] == A[n - 1]);
        }
        printf("YES\n%d\n", ans.size());
        for(int i = 0;i < ans.size();i++){
                printf("%d %d %d\n", get<0>(ans[i]) + 1, get<1>(ans[i]) + 1, get<2>(ans[i]) + 1);
        }
}

int main(){
        scanf("%d", &n);
        for(int i = 0;i < n;i++) scanf("%d", A + i);
        if(n % 2 == 1){
                solve();
                return 0;
        }
        int ksor = 0;
        for(int i = 0;i < n;i++){
                ksor ^= A[i];
        }
        if(ksor != 0) return 0 * printf("NO");
        n--;
        solve();
        return 0;
}