#include<cstdio>
#include<cstring>
int s[1 << 24], n;
void fac(int d)
{
    int cnt = 0;
    for(int e = d; e; e -= e & -e) cnt ^= 1;
    s[d] += cnt * 2 - 1;
}
int main()
{
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++)
    {
        char str[4];
        scanf("%s", str);
        int d = 0;
        for(int i = 0; i < 3; i++) d |= 1 << str[i] - 'a';
        for(int e = d; e; e = d & e - 1) fac(e);
    }
    for(int i = 0; i < 24; i++)
        for(int j = 0; j < 1 << 24; j++)
            if(~j & 1 << i)
                s[j + (1 << i)] += s[j];
    int ans = 0;
    for(int i = 0; i < 1 << 24; i++)
        ans ^= s[i] * s[i];
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}