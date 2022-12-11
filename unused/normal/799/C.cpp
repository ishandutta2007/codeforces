#include <bits/stdc++.h>
using namespace std;

int b[100005], p[100005];

multiset<int> fw[100005];

void add(int pos, int val)
{
    while (pos <= 100000)
    {
        fw[pos].insert(val);
        pos += pos & -pos;
    }
}
void sub(int pos, int val)
{
    while (pos <= 100000)
    {
        fw[pos].erase(fw[pos].find(val));
        pos += pos & -pos;
    }
}
int query(int pos)
{
    int ret = -1;
    while (pos >= 1)
    {
        if (fw[pos].empty() == false) ret = max(ret, *fw[pos].rbegin());
        pos -= pos & -pos;
    }
    return ret;
}

vector<pair<int, int>> cvt, dvt;
int c, d;

int ans1()
{
    int x1 = -1, x2 = -1;
    for (auto &e : cvt)
    {
        if (e.first > c) continue;
        x1 = max(x1, e.second);
    }

    for (auto &e : dvt)
    {
        if (e.first > d) continue;
        x2 = max(x2, e.second);
    }

    if (x1 == -1 || x2 == -1) return 0;
    else return x1 + x2;
}

int ans2()
{
    int ret = 0;
    for (int i = 0; i <= 100000; i++) fw[i].clear();
    for (auto &e : cvt)
    {
        add(e.first, e.second);
    }

    for (auto &e : cvt)
    {
        if (e.first > c) continue;
        sub(e.first, e.second);

        int rem = c - e.first;
        int x = query(rem);
        if (x != -1) ret = max(ret, x + e.second);
        add(e.first, e.second);
    }

    return ret;
}

int ans3()
{
    cvt = move(dvt);
    c = d;
    return ans2();
}

int main()
{
    int n;
    scanf("%d%d%d",&n,&c,&d);
    for (int i = 1; i <= n; i++)
    {
        char type;
        scanf("%d%d %c",&b[i],&p[i],&type);
        if (type == 'C') cvt.emplace_back(p[i], b[i]);
        else dvt.emplace_back(p[i], b[i]);
    }

    int a1 = ans1();
    int a2 = max(a1, ans2());
    int a3 = max(a2, ans3());

    printf("%d\n", a3);
}