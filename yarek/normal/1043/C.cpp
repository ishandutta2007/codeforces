#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
char s[N];
int ans[N];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    bool inv = false;
    for(int i = n - 1; i >= 0; i--)
    {
        if((s[i] == 'b') == inv)
        {
            ans[i] = 1;
            inv = !inv;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    puts("");
}