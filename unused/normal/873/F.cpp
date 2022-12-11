#pragma GCC target("popcnt")
#include <cctype>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef char T;
// calculates suffix array.
// O(n*logn)
vector<int> suffix_array(const string& in) {
    int n = (int)in.size(), c = 0;
    vector<int> temp(n), pos2bckt(n), bckt(n), bpos(n), out(n);
    for (int i = 0; i < n; i++) out[i] = i;
    sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
    for (int i = 0; i < n; i++) {
        bckt[i] = c;
        if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
    }
    for (int h = 1; h < n && c < n; h <<= 1) {
        for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
        for (int i = n - 1; i >= 0; i--) bpos[bckt[i]] = i;
        for (int i = 0; i < n; i++)
            if (out[i] >= n - h) temp[bpos[bckt[i]]++] = out[i];
        for (int i = 0; i < n; i++)
            if (out[i] >= h) temp[bpos[pos2bckt[out[i] - h]]++] = out[i] - h;
        c = 0;
        for (int i = 0; i + 1 < n; i++) {
            int a = (bckt[i] != bckt[i + 1]) || (temp[i] >= n - h)
                || (pos2bckt[temp[i + 1] + h] != pos2bckt[temp[i] + h]);
            bckt[i] = c;
            c += a;
        }
        bckt[n - 1] = c++;
        temp.swap(out);
    }
    return out;
}
// calculates lcp array. it needs suffix array & original sequence.
// O(n)
vector<int> lcp_(const string& in, const vector<int>& sa) {
    int n = (int)in.size();
    if (n == 0) return vector<int>();
    vector<int> rank(n), height(n - 1);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0, h = 0; i < n; i++) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && in[i + h] == in[j + h]) h++;
        height[rank[i] - 1] = h;
        if (h > 0) h--;
    }
    return height;
}

string str, forbid;
vector<int> sa, lcp;
long long ans;

void divide_and_conquer(int L, int R)
{
    int mid = (L + R) / 2;

    int LP = mid - 1, RP = mid + 1;
    int height = str.size() - sa[mid];
    int cnt = (forbid[sa[mid]] == '0');

    for (;;)
    {
        ans = max(ans, height * 1ll * cnt);

        if (LP == L - 1 && RP == R + 1) break;

        if (LP == L - 1)
        {
            g1:
            height = min(height, lcp[RP - 1]);
            if (forbid[sa[RP]] == '0') ++cnt;
            ++RP;
        }
        else if (RP == R + 1)
        {
            g2:
            height = min(height, lcp[LP]);
            if (forbid[sa[LP]] == '0') ++cnt;
            --LP;
        }
        else if (lcp[LP] < lcp[RP - 1])
        {
            goto g1;
        }
        else goto g2;
    }

    if (L < mid) divide_and_conquer(L, mid - 1);
    if (mid < R) divide_and_conquer(mid + 1, R);
}

int main()
{
    cin.sync_with_stdio(false);
    int n; cin >> n >> str >> forbid;
    reverse(str.begin(), str.end());
    reverse(forbid.begin(), forbid.end());

    sa = suffix_array(str);
    lcp = lcp_(str, sa);

    divide_and_conquer(0, n - 1);

    printf("%lld\n", ans);
}