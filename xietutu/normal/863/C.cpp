#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL > pll;
#define PB push_back
int a, b, n, A[4][4], B[4][4];
map<pii, int> M;
LL K;
pii ret[205];
pll score[205];
pll operator+(const pll& lhs, const pll& rhs) {
    return pll(lhs.first + rhs.first, lhs.second + rhs.second);
}
pll operator*(const pll& lhs, const LL& rhs) {
    return pll(lhs.first * rhs, lhs.second * rhs);
}
int calc(int a, int b) {
    if (a == 2 && b == 1) return 1;
    if (a == 3 && b == 2) return 1;
    if (a == 1 && b == 3) return 1;
    return 0;
}
int main() {
    cin >> K >> a >> b;
    for (int i = 1; i <= 3; ++i) 
        for (int j = 1; j <= 3; ++j)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= 3; ++i) 
        for (int j = 1; j <= 3; ++j)
            scanf("%d", &B[i][j]);
    do {
        ret[++n] = {a, b};
        score[n].first += calc(a, b);
        score[n].second += calc(b, a);
        M[ret[n]] = n;
        int aa = A[a][b], bb = B[a][b];    
        a = aa; b = bb;
    } while (M.find(pii(a, b)) == M.end());
    
    pll ans = {0, 0};
    if (K <= n) {
        for (int i = 1; i <= K; ++i)
            ans = ans + score[i];
    }
    else {
        int t = M[{a,b}];
        pii tmp = {0, 0};
        for (int i = 1; i < t; ++i)
            ans = ans + score[i];
        for (int i = t; i <= n; ++i)
            tmp = tmp + score[i];
        LL len = (K - t + 1) / (n - t + 1);
        int mod = (K - t + 1) % (n - t + 1);
        
        ans = ans + (tmp * len);
        for (int i = t, j = 0; j < mod; ++j, ++i)
            ans = ans + score[i];
    }
    
    cout << ans.first << " " << ans.second << endl;
}