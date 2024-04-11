#include <bits/stdc++.h>
using namespace std;

namespace IO {
    int readInt() {
        int integer; scanf("%d", &integer);
        return integer;
    }
    string readLine(int LEN=1000000) {
        int length = LEN;
        char characters[length];
        scanf("%s", characters);
        string response;
        for(int j = 0; j < length; j++)
            response += characters[j];
        return response;
    }
    long long readLong() {
        long long integer; scanf("%lld", &integer);
        return integer;
    }
    vector<int> nextArrayInt(int MAX_LIMIT = 1000000) {
        int N = MAX_LIMIT;
        vector<int> response(N);
        generate(response.begin(), response.end(), readInt);
        return response;
    }
    vector<long long> nextArrayLong(int MAX_LIMIT = 1000000) {
        int N = MAX_LIMIT;
        vector<long long> response(N);
        generate(response.begin(), response.end(), readLong);
        return response;
    }
    void ps(long long x) {
        printf("%lld\n", x);
    }
    void ps(int x) {
        printf("%d\n", x);
    }
    void ps(vector<int> &a) {
        for(int i = 0; i < (int)a.size(); i++)
            printf("%d ", a[i]);
        puts("");
    }
    void ps(vector<long long> &a) {
        for(int i = 0; i < (int)a.size(); i++)
            printf("%lld ", a[i]);
        puts("");
    }
    void pv(long long x) {
        printf("%lld", x);
    }
    void pv(int x) {
        printf("%d", x);
    }
}
using namespace IO;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T = readInt();
    while(T--) {
        int N = readInt();
        int M = readInt();

        int MOD = 1e9 + 7;
        int c = 1;
        int ans=0;
        for(int i = 0; i < 30; i++) {
            if(M & (1<<i)) {
                ans = (ans + c) % MOD;
            }
            c = (1LL * c * N) % MOD;
        }

        ps(ans);
    }
         
}