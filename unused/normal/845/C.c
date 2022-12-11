#include <stdio.h>

typedef struct
{
    int l, r;
} pair;

int l[200005], r[200005];

pair event[400005];
pair buf[400005];

void sort(pair *p, int len)
{
    if (len == 1) return;
    sort(p, len / 2);
    sort(p + len / 2, len - len / 2);

    int ls = 0, le = len / 2;
    int rs = len / 2, re = len;
    
    int outp = 0;

    while (ls < le && rs < re)
    {
        if (p[ls].l < p[rs].l)
        {
            buf[outp++] = p[ls++];
        }
        else
        {
            buf[outp++] = p[rs++];
        }
    }

    while (ls < le)
    {
        buf[outp++] = p[ls++];
    }

    while (rs < re)
    {
        buf[outp++] = p[rs++];
    }

    for (int i = 0; i < len; i++) p[i] = buf[i];
}

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&l[i],&r[i]);

        event[i * 2].l = l[i];
        event[i * 2].r = 1;
        event[i * 2 + 1].l = r[i] + 1;
        event[i * 2 + 1].r = -1;
    }

    sort(event, n * 2);

    int cnt = 0;

    for (int i = 0; i < n * 2; i++)
    {
        cnt += event[i].r;
        if (i < n * 2 - 1 && event[i].l == event[i + 1].l) continue;

        if (cnt > 2)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
}