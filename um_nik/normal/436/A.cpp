#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item
{
    int h, val;
    bool used;

    void scan()
    {
        scanf("%d%d", &h, &val);
        used = 0;
    }
};

int n, x, xx;
vector<Item> a, b;
int type;
int ans, ans2;

bool solve()
{
    int t = -1;
    if (type == 0)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (!a[i].used && x >= a[i].h && (t == -1 || a[i].val > a[t].val))
                t = i;
        }
        if (t == -1)
            return false;
        x += a[t].val;
        a[t].used = 1;
        type ^= 1;
        return true;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (!b[i].used && x >= b[i].h && (t == -1 || b[i].val > b[t].val))
                t = i;
        }
        if (t == -1)
            return false;
        x += b[t].val;
        b[t].used = 1;
        type ^= 1;
        return true;
    }
}

int main()
{
    scanf("%d%d", &n, &x);
    xx = x;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        Item tmp;
        tmp.scan();
        if (t == 0)
            a.push_back(tmp);
        else
            b.push_back(tmp);
    }
    type = 0;
    while (solve())
        ans++;
    x = xx;
    type = 1;
    for (int i = 0; i < a.size(); i++)
        a[i].used = 0;
    for (int i = 0; i < b.size(); i++)
        b[i].used = 0;
    while(solve())
        ans2++;
    printf("%d\n", max(ans, ans2));
    return 0;
}