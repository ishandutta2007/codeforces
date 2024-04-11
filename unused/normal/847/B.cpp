#include <bits/stdc++.h>
using namespace std;

int dat[200005];
int tree[524288];

void update(int pos, int val)
{
    pos += 262144;
    tree[pos] = val;
    while (pos >>= 1)
        tree[pos] = max(tree[pos << 1], tree[pos << 1 | 1]);
}
int search(int idx)
{
    int val = (idx == -1) ? 0 : dat[idx];
    int L = 262144 + idx + 1;
    int R = 524287;
    int look = -1;

    while (L <= R)
    {
        if (L & 1)
        {
            if (tree[L] > val)
            {
                look = L;
                break;
            }
            ++L;
        }
        L >>= 1; R >>= 1;
    }

    if (look == -1) return -1;

    while (look < 262144)
    {
        if (tree[look << 1] > val) look <<= 1;
        else look = look << 1 | 1;
    }
    return look - 262144;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d", &dat[i]);
    for (int i = 0; i < n; i++) update(i, dat[i]);

    int lastidx = -1;
    for (int T = n; T; )
    {
        int idx = search(lastidx);
        if (idx == -1)
        {
            printf("\n");
            lastidx = -1;
            continue;
        }

        printf("%d ", dat[idx]);
        update(idx, 0);
        --T;
        lastidx = idx;
    }
    printf("\n");
}