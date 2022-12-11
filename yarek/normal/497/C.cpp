#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int offset = 1 << 19;
pair<int, int> mn[offset << 1];
vector<pair<int, int> > l[offset];

const int inf = 1000000000;

void pop(int k)
{
    if(l[k].empty()) return;
    if(--l[k].back().first == 0)
    {
        l[k].pop_back();
        int p = k + offset;
        if(l[k].empty()) mn[p] = make_pair(inf, 0);
        else mn[p] = make_pair(k, l[k].back().second);
        while(p > 1)
        {
            p >>= 1;
            mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
        }
    }
}

void insert(int k, int x, int nr)
{
    l[k].push_back(make_pair(x, nr));
    int p = k + offset;
    mn[p] = make_pair(k, l[k].back().second);
    while(p > 1)
    {
        p >>= 1;
        mn[p] = min(mn[p * 2], mn[p * 2 + 1]);
    }
}

pair<int, int> answer(int a, int b)
{
    a += offset;
    b += offset;
    pair<int, int> ans(inf, 0);
    while(a < b)
    {
        if(a & 1) ans = min(ans, mn[a++]);
        if((b & 1) == 0) ans = min(ans, mn[b--]);
        a >>= 1;
        b >>= 1;
    }
    if(a == b) ans = min(ans, mn[a]);
    return ans;
}

struct seg
{
    int a, b, num;
    seg(int A = 0, int B = 0, int Num = 0) : a(A), b(B), num(Num) { }
};

bool operator<(const seg &a, const seg &b)
{
    return make_pair(a.a, a.num) < make_pair(b.a, b.num);
}

int ans[100001];
int k[100001];

int main()
{
    int n, m, a, b;
    vector<int> val;
    vector<seg> vec;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        vec.push_back(seg(a, b, i));
        val.push_back(a);
        val.push_back(b);
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &a, &b, k + i);
        vec.push_back(seg(a, b, -i));
        val.push_back(a);
        val.push_back(b);
    }
    sort(val.begin(), val.end());
    for(int i = 0; i < vec.size(); i++)
    {
        vec[i].a = lower_bound(val.begin(), val.end(), vec[i].a) - val.begin();
        vec[i].b = lower_bound(val.begin(), val.end(), vec[i].b) - val.begin();
    }
    sort(vec.begin(), vec.end());
    for(int i = 2 * offset - 1; i >= 0; i--)
        mn[i] = make_pair(inf, 0);
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i].num < 0)
        {
            int nr = -vec[i].num;
            insert(vec[i].b, k[nr], nr);
        }
        else
        {
            pair<int, int> p = answer(vec[i].b, val.size());
            if(p.first == inf)
            {
                puts("NO");
                return 0;
            }
            pop(p.first);
            ans[vec[i].num] = p.second;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    puts("");
}