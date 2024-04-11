#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
    return b?gcd(b, a % b):a;
}
int a[111111], mx, d, n;
int main()
{
    scanf("%d", &n);
    mx = d = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
        d = gcd(d, a[i]);
    }
    if((mx / d - n) % 2 == 1)
        printf("Alice\n");
    else
        printf("Bob\n");
    fclose(stdin);
    return 0;
}