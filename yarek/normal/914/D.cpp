#include <bits/stdc++.h>
using namespace std;

const int offset = 1 << 19;
int tree[offset << 1];

void insert(int p, int x)
{
    p += offset;
    tree[p] = x;
    while(p > 1)
    {
        p >>= 1;
        tree[p] = __gcd(tree[p+p], tree[p+p+1]);
    }
}

bool query(int a, int b, int x)
{
    a += offset; b += offset;
    while(a < b)
    {
        if((a & 1) && tree[a++] % x) return false;
        if((b & 1) == 0 && tree[b--] % x) return false;
        a >>= 1;
        b >>= 1;
    }
    if(a == b && tree[a] % x) return false;
    return true;
}

int query_left(int a, int x)
{
    a += offset;
    while(tree[a] % x == 0)
    {
        if(a & 1) a++;
        else a >>= 1;
    }
    while(a < offset)
        if(tree[a+a] % x == 0) a = a + a + 1;
        else a = a + a;
    return a - offset;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        insert(i, a);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 2)
        {
            int i, y;
            scanf("%d %d", &i, &y);
            insert(i, y);
        }
        else
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            if(query(l, r, x))
            {
                puts("YES");
                continue;
            }
            int p = query_left(l, x);
            puts(query(p + 1, r, x) ? "YES" : "NO");
        }
    }
}