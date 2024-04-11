#include <bits/stdc++.h>
using namespace std;

char buffer[524288];
int parent[1 << 15];
int end_, ptr, n, m;

int Find(int t)
{
    return parent[t] == t ? t : parent[t] = Find(parent[t]);
}

bool Union(int a, int b)
{
    if (parent[a] == -1 || parent[b] == -1) return false;

    a = Find(a); b = Find(b);
    if (a == b) return false;

    if (a > b) parent[b] = a;
    else parent[a] = b;
    return true;
}

void Slide()
{
    for (int i = 0; i < m; i++)
    {
        parent[i] = parent[m + i];
        if (parent[i] >= m) parent[i] -= m;
    }

    for (int i = m; i < 2 * m; i++)
    {
        parent[i] = -1;
    }
}

char GetChar()
{
    while (ptr == end_)
    {
        end_ = fread(buffer, 1, 524288, stdin);
        if (end_ == 0) return ' ';
        ptr = 0;
    }
    return buffer[ptr++];
}

int ReadInt()
{
    int ret = 0;
    char ch;
    while ((ch = GetChar()) < '-')
        ;
    bool neg = (ch == '-'); if (neg) ch = GetChar();
    do ret = ret * 10 + ch - '0'; while ((ch = GetChar()) >= '0');
    return neg ? -ret : ret;
}

int main()
{
    n = ReadInt(), m = ReadInt();

    for (int i = 0; i < m * 2; i++) parent[i] = -1;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j += 4)
        {
            char ch;
            do ch = GetChar(); while (ch < '0');
            int num = (ch >= 'A') ? ch - 'A' + 10 : ch - '0';
            for (int k = 0; k < 4; k++)
            {
                if ((num & (1 << (3 - k))) == 0) continue;

                parent[m + j + k] = m + j + k;
                ++ans;
                if (j + k > 0 && Union(m + j + k, m + j + k - 1)) --ans;
                if (Union(m + j + k, j + k)) --ans;
            }
        }

        Slide();
    }

    printf("%d\n", ans);
}