#include <bits/stdc++.h>
using namespace std;

namespace fio {
    const int BSIZE = 1048576;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    inline int readInt() {
        char c = readChar();
        while (c < '0') {
            c = readChar();
        }
        int ret = 0;
        while (c >= '0') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return ret;
    }
}

using hval = array<unsigned, 4>;

vector<int> graph[1000005];
vector<int> deg[1000005];
pair<int,int> edge[1000005];
vector<hval> fh[1000005];
map<pair<int,hval>, int> cnt;

constexpr unsigned P[] =
{
    1000003,
    1000033,
    1000003,
    1000033
};

constexpr unsigned Q[] =
{
    1000000007,
    1000000007,
    1000000009,
    1000000009
};

unsigned modpow[4][1000002];

int main()
{
    for (int i = 0; i < 4; i++)
    {
        modpow[i][0] = 1;
        for (int j = 1; j <= 1000000; j++) modpow[i][j] = modpow[i][j-1] * (unsigned long long)P[i] % Q[i];
    }

    int n, m;
    n = fio::readInt(); m = fio::readInt();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        a = fio::readInt();
        b = fio::readInt();
        edge[i] = {a, b};
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        deg[graph[i].size()].push_back(i);
        hval h{};
        fh[i].push_back(h);
        for (int idx = 0; idx < graph[i].size(); idx++)
        {
            int t = graph[i][idx];
            for (int j = 0; j < 4; j++)
            {
                h[j] = (h[j] + (unsigned long long)modpow[j][idx] * t) % Q[j];
            }
            fh[i].push_back(h);
        }
    }

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        tie(a, b) = edge[i];

        int idx1 = lower_bound(graph[a].begin(), graph[a].end(), b) - graph[a].begin();
        hval h1 = fh[a].back();
        for (int j = 0; j < 4; j++) h1[j] = (h1[j] + Q[j] - fh[a][idx1+1][j] + (unsigned long long)fh[a][idx1][j] * P[j]) % Q[j];
        int idx2 = lower_bound(graph[b].begin(), graph[b].end(), a) - graph[b].begin();
        hval h2 = fh[b].back();
        for (int j = 0; j < 4; j++) h2[j] = (h2[j] + Q[j] - fh[b][idx2+1][j] + (unsigned long long)fh[b][idx2][j] * P[j]) % Q[j];
        if (h1 == h2) ++ans;
    }

    for (int i = 1; i <= n; i++)
    {
        cnt[make_pair((int)graph[i].size(),fh[i].back())]++;
    }

    for (auto &&e : cnt)
    {
        ans += e.second * (e.second - 1ll) / 2;
    }

    printf("%lld\n", ans);
    fflush(stdout);
    _Exit(0);
}