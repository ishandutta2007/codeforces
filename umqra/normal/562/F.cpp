#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second 
#define mp make_pair

const int INF = (int)1e9 + 10;
const int N = (int)1e5 + 10;
const int SZ = (int)8e5 + 10;
const int A = 26;


struct String
{
    string str;
    int index;
    String () : str(), index() {}
    void scan(int i)
    {
        index = i;
        cin >> str;
    }
    bool operator < (const String &s) const
    {
        return str < s.str;
    }
};

String name[N], pseudo[N];

struct Bor
{
    int go[SZ][A];
    vector <int> items[SZ];
    int minId[SZ], maxId[SZ];
    int mv;
    Bor ()
    {
        memset(go, 0, sizeof(go));
        mv = 1;
        for (int i = 0; i < SZ; i++)
        {
            items[i] = vector<int>();
            minId[i] = INF, maxId[i] = 0;
        }
    }
    void addString (string &s, int id)
    {
        int v = 0;
        minId[v] = min(minId[v], id);
        maxId[v] = max(maxId[v], id);
        for (int i = 0; i < (int)s.length(); i++)
        {
            int c = s[i] - 'a';
            if (go[v][c] == 0)
                go[v][c] = mv++;
            v = go[v][c];

            minId[v] = min(minId[v], id);
            maxId[v] = max(maxId[v], id);
        }
        items[v].push_back(id);
    }
};

struct ConList
{
    int nxt[N];
    int prv[N];
    ConList()
    {
        for (int i = 0; i < N; i++)
        {
            nxt[i] = i + 1;
            prv[i] = i - 1;
        }
    }
    void deleteNode(int v)
    {
        v++;
        int p = prv[v];
        int n = nxt[v];
        nxt[p] = n;
        prv[n] = p;
    }
    int getNext(int v)
    {
        v++;
        return nxt[v] - 1;
    }
};

Bor nBor, pBor;
set <int> nAlive, pAlive;
ConList nList, pList;
int match[N];

ll answer = 0;

void solve(int v1, int v2, int h)
{
    for (int i = 0; i < A; i++)
    {
        if (nBor.go[v1][i] == 0 || pBor.go[v2][i] == 0)
            continue;
        solve(nBor.go[v1][i], pBor.go[v2][i], h + 1);
    }
    auto nIt = nAlive.lower_bound(nBor.minId[v1]);
    auto pIt = pAlive.lower_bound(pBor.minId[v2]);
    if (nIt == nAlive.end() || pIt == pAlive.end())
        return;
    int nPos = *nIt;
    int pPos = *pIt;
    int nB = nBor.maxId[v1];
    int pB = pBor.maxId[v2];
    while (nPos <= nB && pPos <= pB)
    {
        match[name[nPos].index] = pseudo[pPos].index;         
        answer += h;
        nAlive.erase(nPos);
        pAlive.erase(pPos);
        nList.deleteNode(nPos);
        pList.deleteNode(pPos);
        nPos = nList.getNext(nPos);
        pPos = pList.getNext(pPos);
    }
}

int main()
{
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    cin.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        name[i].scan(i);
    for (int i = 0; i < n; i++)
        pseudo[i].scan(i);

    sort(name, name + n);
    sort(pseudo, pseudo + n);

    for (int i = 0; i < n; i++)
    {
        nAlive.insert(i);
        pAlive.insert(i);
    }
    for (int i = 0; i < n; i++)
        nBor.addString(name[i].str, i);
    for (int s = 0; s < n; s++)
        pBor.addString(pseudo[s].str, s);
    
    solve(0, 0, 0);
    cout << answer << endl;
    for (int i = 0; i < n; i++)
        printf("%d %d\n", i + 1, match[i] + 1);

    return 0;
}