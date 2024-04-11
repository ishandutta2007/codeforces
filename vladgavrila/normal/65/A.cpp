#include <cstdio>

using namespace std;

int a, b, c, d, e, f;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    if(c==0 && d!=0)
    {
        printf("Ron\n");
        return 0;
    }
    if(a==0 && b>0 && d>0)
    {
        printf("Ron\n");
        return 0;
    }
    if(e==0 && f>0 && b>0 && d>0)
    {
        printf("Ron\n");
        return 0;
    }
    if(d==0)
    {
        printf("Hermione\n");
        return 0;
    }
    if(b==0 && c>0)
    {
        printf("Hermione\n");
        return 0;
    }
    if(f==0 && a>0 && c>0)
    {
        printf("Hermione\n");
        return 0;
    }
    if(a*c*e<b*d*f)
    {
        printf("Ron\n");
        return 0;
    }
    else
    {
        printf("Hermione\n");
        return 0;
    }
    return 0;
}