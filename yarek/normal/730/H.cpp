#include <bits/stdc++.h>
using namespace std;

const int N = 101;
char s[N][N];
bool del[N];
set<char> ch[N];
char pat[N];

int main()
{
    int n, m, len = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for(int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        k--;
        del[k] = true;
        if(len == 0)
            len = strlen(s[k]);
        else if(len != strlen(s[k]))
        {
            puts("No");
            return 0;
        }
        for(int j = 0; j < len; j++)
            ch[j].insert(s[k][j]);
    }
    for(int i = 0; i < len; i++)
        if(ch[i].size() > 1) pat[i] = '?';
        else pat[i] = *ch[i].begin();
    for(int i = 0; i < n; i++)
        if(!del[i])
        {
            if(strlen(s[i]) != len) continue;
            bool ok = true;
            for(int j = 0; j < len; j++)
                if(pat[j] != '?' && pat[j] != s[i][j])
                    ok = false;
            if(ok)
            {
                puts("No");
                return 0;
            }
        }
    puts("Yes");
    puts(pat);
}