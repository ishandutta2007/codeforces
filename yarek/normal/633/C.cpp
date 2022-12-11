#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int K = 1001, N = 10001, M = 100000, mod = 1000000007, base = 31;
typedef unsigned long long ull;
typedef pair<int, ull> hashh;

map<hashh, int> words[K];
hashh table[N];
char buf[N+1];
string w[M];
int tab[N];
hashh powers[N];

int main()
{
    int n, m;
    scanf("%d %s", &n, buf + 1);
    ull k1 = 0, k2 = 0, p1 = 1, p2 = 1;
    powers[0] = make_pair((int)p1, p2);
    for(int i = 1; i <= n; i++)
    {
        k1 *= base;
        k2 *= base;
        k1 += buf[i] - 'a';
        k2 += buf[i] - 'a';
        k1 %= mod;
        table[i] = make_pair((int)k1, k2);
        p1 = p1 * base % mod;
        p2 *= base;
        powers[i] = make_pair((int)p1, p2);
    }
    scanf("%d", &m);
    int maxL = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%s", buf + 1);
        w[i] = buf + 1;
        int d = w[i].size();
        reverse(buf + 1, buf + 1 + d);
        k1 = 0; k2 = 0;
        for(int j = 1; j <= d; j++)
        {
            k1 *= base;
            k2 *= base;
            int add = buf[j] - 'a';
            if(add < 0 || add > 25) add = buf[j] - 'A';
            k1 += add;
            k2 += add;
            k1 %= mod;
        }
        words[d][make_pair((int)k1, k2)] = i;
        maxL = max(maxL, d);
    }
    for(int i = 1; i <= n; i++)
    {
        tab[i] = -1;
        for(int j = 1; j <= maxL; j++)
        {
            if(i - j < 0) break;
            if(tab[i-j] == -1) continue;
            long long h1 = (table[i].first - (long long)table[i-j].first * powers[j].first) % mod;
            ull h2 = table[i].second - table[i-j].second * powers[j].second;
            if(h1 < 0) h1 += mod;
            auto it = words[j].find(make_pair((int)h1, h2));
            if(it != words[j].end())
            {
                tab[i] = it->second;
                break;
            }
        }
    }
    vector<string> vec;
    int k = n;
    while(k > 0)
    {
        vec.push_back(w[tab[k]]);
        k -= w[tab[k]].size();
    }
    for(int i = vec.size() - 1; i >= 0; i--)
        printf("%s ", vec[i].c_str());
    puts("");
}