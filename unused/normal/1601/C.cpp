#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cstring>
#include <cstdlib>
using namespace std;

const int TSIZE = 2100000; // always 2^k form && n <= TSIZE
int segtree[TSIZE * 2];
int prop[TSIZE * 2];
void seg_relax(int nod, int l, int r) {
    if (prop[nod] == 0) return;
    if (l < r) {
        int m = (l + r) >> 1;
        segtree[nod << 1] += prop[nod];
        prop[nod << 1] += prop[nod];
        segtree[nod << 1 | 1] += prop[nod];
        prop[nod << 1 | 1] += prop[nod];
    }
    prop[nod] = 0;
}
int seg_query(int nod, int l, int r, int s, int e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return segtree[nod];
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    return min(seg_query(nod << 1, l, m, s, e), seg_query(nod << 1 | 1, m + 1, r, s, e));
}
void seg_update(int nod, int l, int r, int s, int e, int val) {
    if (r < s || e < l) return;
    if (s <= l && r <= e) {
        segtree[nod] += val;
        prop[nod] += val;
        return;
    }
    seg_relax(nod, l, r);
    int m = (l + r) >> 1;
    seg_update(nod << 1, l, m, s, e, val);
    seg_update(nod << 1 | 1, m + 1, r, s, e, val);
    segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
}

int fw[2000005];
int fwsize;

void fwadd(int pos)
{
    for (pos += 1; pos < fwsize; pos += pos & -pos)
    {
        fw[pos]++;
    }
}

int fwquery(int pos)
{
    int ret = 0;
    for (pos += 1; pos; pos -= pos & -pos)
    {
        ret += fw[pos];
    }
    return ret;
}

namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if (p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return ret;
    }
}

int main()
{
    int T = fio::readInt();
	while (T--)
	{
		int n, m;
        n = fio::readInt();
        m = fio::readInt();
		vector<int> a(n), b(m);
		vector<int> coord(n + m);

        for (int i = 0; i < n; i++) a[i] = fio::readInt();
        for (int i = 0; i < m; i++) b[i] = fio::readInt();

		memcpy(&coord[0], &a[0], sizeof(int) * n);
		memcpy(&coord[n], &b[0], sizeof(int) * m);
		sort(coord.begin(), coord.end());
		coord.erase(unique(coord.begin(), coord.end()), coord.end());

		for (int& t : a) t = lower_bound(coord.begin(), coord.end(), t) - coord.begin();
		for (int& t : b) t = lower_bound(coord.begin(), coord.end(), t) - coord.begin();

		sort(b.begin(), b.end());

		vector<pair<int, int>> events;
		for (int i = 0; i < n; i++) events.emplace_back(a[i], i);
		sort(events.begin(), events.end());

        int tsize = 1;
        while (tsize < n + m) tsize <<= 1;
        memset(segtree, 0, 8 * tsize);
        memset(prop, 0, 8 * tsize);

        // 0 ~ n (inclusive)
        for (int i = 0; i < n; i++)
        {
            seg_update(1, 0, n, i + 1, n, 1);
        }
        int L = 0, R = 0;

        long long ans = 0;
        for (int x : b)
        {
            while (R < n && events[R].first <= x)
            {
                seg_update(1, 0, n, events[R].second + 1, n, -1);
                ++R;
            }

            while (L < n && events[L].first < x)
            {
                seg_update(1, 0, n, 0, events[L].second, 1);
                ++L;
            }

            ans += seg_query(1, 0, n, 0, n);
        }

        fwsize = coord.size() + 2;
        memset(fw, 0, 4 * fwsize);
        for (int i = n - 1; i >= 0; i--)
        {
            ans += fwquery(a[i] - 1);
            fwadd(a[i]);
        }

        printf("%lld\n", ans);
	}

    fflush(stdout);
    _Exit(0);
}