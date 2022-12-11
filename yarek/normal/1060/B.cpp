#include <bits/stdc++.h>
using namespace std;

const int N = 13;
char s[N];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    reverse(s, s + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += s[i] - '0';
        if(i + 1 < n && s[i] < '9')
        {
            s[i+1]--;
            ans += 10;
        }
    }
    printf("%d\n", ans);
}