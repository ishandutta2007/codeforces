#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const long long linf = 4e18 + 10;
const string pat = "WG";
const long long mw[2] = {3, 5};

int v[2];
int n;
long long w[N];
string s;

int checksafe(int mask, char ch) {
    for(int i = 0; i < pat.size(); i++) if ((mask >> i) & 1)
        if (pat[i] == ch) return i;
    return -1;
}
struct segtree{
    long long sum[N << 2];
    long long minpref[N << 2], laz[N << 2];


    void update(int node, int L, int R, int pos, long long val) {
        if (L > pos || R < pos) return;
        if (L == R) {
            sum[node] += val;
            minpref[node] = sum[node];
            return;
        }
        int mid = (L + R) / 2;
        update(node * 2, L, mid, pos, val);
        update(node * 2 + 1, mid + 1, R, pos, val);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
        minpref[node] = min(minpref[node * 2], sum[node * 2] + minpref[node * 2 + 1]);
    }
    long long getbad(long long bosum, int node, int L, int R, int l, int r) {
        if (L > r || R < l) return linf;
        if (l <= L && R <= r) return bosum + minpref[node];
        int mid = (L + R) / 2;
        return min(getbad(bosum, node * 2, L, mid, l, r), getbad(bosum + sum[node * 2], node * 2 + 1, mid + 1, R, l, r));
    }
}mseg;

long long solve() {
    long long ans = 0;
    long long budget = 0;
    long long cost = 5;
    int mask = 0;
    for(int i = 1; i <= n; i++) {
        if (s[i] != 'L') {
            int use = s[i] == 'G' ? 5 : 3;
            cost = min(cost, 1LL * use);
            budget += w[i];
            ans += use * w[i];
            mseg.update(1, 1, n, i, w[i]);
            continue;
        }
        ans += w[i];
        long long use = min(w[i], budget);
        if (w[i] > budget) {
            if (cost == 5) mask |= 2;
            else mask |= 1;
        }
        ans += cost * max(0LL, w[i] - budget);
        budget -= use;
        mseg.update(1, 1, n, i, -use);
    }
    //for(int i = 1; i <= n; i++) cout << mseg.getbad(0, 1, 1, n, i, i) << " ";cout << '\n';
    //cout << ans << '\n';

    for(int i = n; i >= 1; i--) if (s[i] == 'G') {
        long long cut = mseg.getbad(0, 1, 1, n, i, n);
        if (i == v[1] && (mask & 2) && cut == w[i]) cut-= 2;
        long long pro = min(cut / 2, w[i]);
        //cout << i << " " << cut << " " << pro << '\n';
        ans -= pro * 4;
        mseg.update(1, 1, n, i, -pro * 2);
    }
    for(int i = n; i >= 1; i--) if (s[i] == 'W') {
        long long cut = mseg.getbad(0, 1, 1, n, i, n);
        if (i == v[0] && (mask & 1) && cut == w[i]) cut-= 2;
        long long pro = min(cut / 2, w[i]);
        //cout << i << " " << cut << " " << pro << '\n';
        ans -= pro * 2;
        mseg.update(1, 1, n, i, -pro * 2);
    }
    return ans / 2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) w[i] <<= 1;
    cin >> s;
    s = ' ' + s;
    for(int i = n; i >= 1; i--) if (s[i] != 'L') {
        int type = s[i] == 'W' ? 0 : 1;
        v[type] = i;
    }
    cout << solve() << '\n';
}