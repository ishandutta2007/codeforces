#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
struct he
{
    int l, h;
} H[200001];
bool operator<(const he &A, const he &B)
{
    return A.h > B.h;
}

int s[200001];
int p[200001];

int getp(int x) { return (p[x] == -1) ? (x) : (p[x]=getp(p[x])); }
void uni(int a, int b) { a = getp(a); b = getp(b); p[a] = b; s[b] += s[a]; }

int ans[200001];
bool chk[200001];

int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        H[i].l = i;
        scanf("%d", &H[i].h);
    }
    std::sort(H + 1, H + n + 1);
    for (i = 1; i <= n; i++)
    {
        p[i] = -1;
        s[i] = 1;
    }
    int left = 1;
    for (i = 1; i <= n; i++)
    {
        int x = H[i].l;
        chk[x] = true;
        if (chk[x + 1] == true) uni(x, x + 1);
        if (chk[x - 1] == true) uni(x, x - 1);
        for (; left <= s[getp(x)]; left++)printf("%d ", H[i].h);
    }
    return 0;
}