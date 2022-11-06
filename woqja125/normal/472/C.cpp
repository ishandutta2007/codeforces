#include<stdio.h>
#include<algorithm>
#include<string>
struct name
{
    std::string dat;
    int l;
} n1[200001];
bool operator<(const name &A, const name &B)
{
    return A.dat<B.dat;
}
int p[100001];
int main()
{
    int n, i;
    scanf("%d", &n);
    char t[100001];
    for(i=1; i<=n; i++)
    {
        n1[i*2-1].l = n1[i*2].l = i;
        scanf("%s", t);
        n1[i*2-1].dat = t;
        scanf("%s", t);
        n1[i*2].dat = t;
    }
    std::sort(n1+1, n1+1+2*n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", p+i);
    }
    int j = 1;
    for(i=1; i<=n; i++)
    {
        for(;p[i]!=n1[j].l && j<=2*n; j++);
        if(j==2*n+1)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}