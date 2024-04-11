#include <bits/stdc++.h>
using namespace std;

struct seg_tree
{
    int *tab;
    int offset;
    bool in = false;
    
    void init(int n)
    {
        in = true; 
        offset = 1;
        while(offset <= n)
            offset *= 2;
        tab = new int[offset * 2];
        for(int i = 0; i < offset * 2; i++)
            tab[i] = 0;
    }
    
    void insert(int p, int x)
    {
        assert(p < offset && in);
        p += offset;
        while(p > 0)
        {
            tab[p] += x;
            p >>= 1;
        }
    }
    
    int sum(int a, int b)
    {
        assert(a < offset && b < offset && in);
        a += offset; b += offset;
        int ans = 0;
        while(a < b)
        {
            if(a & 1) ans += tab[a++];
            if((b & 1) == 0) ans += tab[b--];
            a >>= 1;
            b >>= 1;
        }
        if(a == b) ans += tab[a];
        return ans;
    }
};

const int N = 100001;
char str[N];
const int K = 4, M = 11;
seg_tree tree[K][M][M];
char e[M];
char c[2];

void insert(int pos, int k, int x)
{
    for(int i = 1; i < M; i++)
        tree[k][i][pos % i].insert(pos / i, x);
}

int num(char c)
{
    if(c == 'A') return 0;
    if(c == 'T') return 1;
    if(c == 'G') return 2;
    if(c == 'C') return 3;
    assert(false);
}

int main()
{
    scanf("%s", str);
    int n = strlen(str);
    for(int i = 0; i < K; i++)
        for(int j = 1; j < M; j++)
            for(int k = 0; k < j; k++)
                tree[i][j][k].init(n / j + 1);
    for(int i = 0; i < n; i++)
        insert(i, num(str[i]), 1);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            int x;
            scanf("%d %s", &x, c);
            x--;
            insert(x, num(str[x]), -1);
            str[x] = c[0];
            insert(x, num(str[x]), 1);
        }
        else
        {
            int l, r;
            scanf("%d %d %s", &l, &r, e);
            l--; r--;
            int m = min((int)strlen(e), r - l + 1);
            int ans = 0;
            for(int i = 0; i < m; i++)
            {
                int last = l + i + (r - l) / m * m - 2 * m;
                while(last + m <= r) last += m;
                ans += tree[num(e[i])][m][(l + i)%m].sum((l+i)/m, last/m);
                //printf("%d %d\n", i, tree[num(e[i])][m][(l + i)%m].sum((l+i)/m, last/m));
            }
            printf("%d\n", ans);
        }
    }
}