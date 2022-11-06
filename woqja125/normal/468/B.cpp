#include<stdio.h>
#include<map>
int p[200001];
int p2[200001];
int dat[200001];
int ans[200001];
std::map<int, int> M;
int getp(int x)
{
    if(p[x] == -1) return x;
    return p[x] = getp(p[x]);
}
void uni(int a, int b)
{
    a = getp(a);
    b = getp(b);
    if(a!=b) p[a] = b;
}
int main()
{
    int n, i, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &dat[i]);
        M[dat[i]] = i;
        p[i*2-1] = -1;
        p[i*2] = -1;
    }
    p[0] = -1;
    // 0 : false
    for(i=1; i<=n; i++)
    {
        if(M.count(a - dat[i]) == 0)
            uni(2*i-1, 0);
        else
        {
            uni(2*i-1, 2*M[a-dat[i]]-1);
            if(M.count(b-dat[i]) == 1) uni(2*i-1, 2*M[b-dat[i]]-1);
        }

        if(M.count(b - dat[i]) == 0)
            uni(2*i, 0);
        else
        {
            uni(2*i, 2*M[b-dat[i]]);
            if(M.count(a-dat[i]) == 1) uni(2*i, 2*M[a-dat[i]]);
        }
    }
    for(i=1; i<=n; i++)
    {
        int a = getp(2*i-1), b = getp(2*i), c = getp(0);
        if(a == b)
        {
            printf("NO");
            return 0;
        }
    }
    for(i=1; i<=n; i++)
    {
        int a = getp(2*i-1), b = getp(2*i), c = getp(0);
        if(a == c) ans[i] = 1;
        else ans[i] = 0;
    }
    printf("YES\n");
    for(i=1; i<=n; i++) printf("%d ", ans[i]);
    return 0;
}