#include <bits/stdc++.h>
using namespace std;

struct query
{
    int type;
    union
    {
        struct
        {
            int pos; char val;
        };
        struct
        {
            int l, r; char e[11];
        };
    };
} qry[100005];

constexpr char chs[] = "ATGC";
char target;

int ans[100005];
char dat[100005];
int val[100005];
int fw[11][11][100005];
int len;

void add(int pos, int val, int *f)
{
    for (++pos; pos <= len; pos += pos & -pos)
        f[pos] += val;
}

int query(int pos, int *f)
{
    int ret = 0;
    for (++pos; pos; pos -= pos & -pos)
        ret += f[pos];
    return ret;
}

int main()
{
    scanf("%s", dat);
    len = strlen(dat);
    int q;
    scanf("%d",&q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &qry[i].type);
        if (qry[i].type == 1)
        {
            scanf("%d %c", &qry[i].pos, &qry[i].val);
            --qry[i].pos;
        }
        else
        {
            scanf("%d%d%s", &qry[i].l, &qry[i].r, qry[i].e);
            --qry[i].l;
            --qry[i].r;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        target = chs[i];
        memset(fw, 0, sizeof(fw));

        for (int j = 0; j < len; j++)
        {
            val[j] = dat[j] == target;
            if (val[j])
            {
                for (int k = 1; k <= 10; k++) add(j, 1, fw[k][j % k]);
            }
        }

        for (int j = 0; j < q; j++)
        {
            if (qry[j].type == 1)
            {
                int newval = target == qry[j].val;

                if (newval != val[qry[j].pos])
                {
                    for (int k = 1; k <= 10; k++) add(qry[j].pos, newval - val[qry[j].pos], fw[k][qry[j].pos % k]);

                    val[qry[j].pos] = newval;
                }

                continue;
            }

            int qlen = strlen(qry[j].e);

            if (qlen >= qry[j].r - qry[j].l + 1)
            {
                for (int k = qry[j].l; k <= qry[j].r; k++)
                {
                    if (val[k] && qry[j].e[k - qry[j].l] == target) ++ans[j];
                }
            }
            else
            {
                for (int k = 0; k < qlen; k++)
                {
                    if (qry[j].e[k] != target) continue;
                    int mod = (qry[j].l + k) % qlen;
                    ans[j] += query(qry[j].r, fw[qlen][mod]) - query(qry[j].l - 1, fw[qlen][mod]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) if (qry[i].type == 2) printf("%d\n", ans[i]);
}