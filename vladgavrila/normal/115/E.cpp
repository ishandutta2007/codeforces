#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define maxn 200010

int n, m;
long long d[maxn], s[maxn];
vector<pair<int, int> > v[maxn];
struct arbore
{
    long long val, pls;
} arb[3*maxn];

void update(int nod, int left, int right, int uleft, int uright, long long val)
{
    if(uleft<=left && right<=uright)
    {
        arb[nod].val+=val;
        arb[nod].pls+=val;
        return;
    }

    int med=(left+right)/2;
    if(uleft<=med)
        update(nod*2, left, med, uleft, uright, val);
    if(med<uright)
        update(nod*2+1, med+1, right, uleft, uright, val);

    arb[nod].val=max(arb[nod*2].val, arb[nod*2+1].val)+arb[nod].pls;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &s[i]);
        s[i]+=s[i-1];
    }
    for(int i=1; i<=m; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v[b].push_back(make_pair(a-1, c));
    }

    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<v[i].size(); ++j)
            update(1, 0, n, 0, v[i][j].first, v[i][j].second);
        d[i]=max(d[i-1], arb[1].val-s[i]);
        update(1, 0, n, i, i, d[i]+s[i]);
    }

    printf("%I64d\n", d[n]);

    return 0;
}