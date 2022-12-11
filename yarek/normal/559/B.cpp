#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int base = 37;

const int N = 200001;
ull pw[N];

ull hsh(char *begin, char *end)
{
    if((end - begin) % 2)
    {
        ull ans = 0;
        while(begin != end)
        {
            ans = ans * base + (*begin - 'a');
            begin++;
        }
        return ans;
    }
    int half = (end - begin) / 2;
    char *mid = begin + half;
    ull a = hsh(begin, mid), b = hsh(mid, end);
    if(a > b) swap(a, b);
    return a * pw[half] + b;
}

char s1[N];
char s2[N];

int main()
{
    pw[0] = 1;
    for(int i = 1; i < N; i++)
        pw[i] = pw[i-1] * base;
    scanf("%s %s", s1, s2);
    int n = strlen(s1);
    puts(hsh(s1, s1 + n) == hsh(s2, s2 + n) ? "YES" : "NO");
}