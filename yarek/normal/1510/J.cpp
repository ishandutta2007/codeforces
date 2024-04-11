#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
char mask[N];

int main()
{
    scanf("%s", mask);
    int n = strlen(mask);
    if(count(mask, mask + n, '_') == 0)
    {
        printf("1\n%d\n", n);
        return 0;
    }
    if(count(mask, mask + n, '#') == 0)
    {
        printf("0\n\n");
        return 0;
    }
    vector<pair<int, int>> seg;
    int start = -1;
    for(int i = 0; i < n; i++)
        if(mask[i] == '#')
        {
            if(start != i)
                seg.emplace_back(start, i);
            start = i + 1;
        }
    seg.emplace_back(start, n + 1);
    bool odd = false;
    bool one = false;
    bool four = false;
    for(auto [a, b]: seg)
    {
        int m = b - a;
        if(m % 2) odd = true;
        if(m == 4) four = true;
        if(m == 1) one = true;
    }
    int k = 2;
    if(odd) k = four ? 4 : 3;
    if(one) k = 1;
    vector<int> ans;
    int prev = -2;
    for(auto [a, b]: seg)
    {
        if(prev != -2)
            ans.push_back(a - prev - 1);
        int o = b - a - k;
        prev = b - k;
        if(o == 1 || o < 0 || (k == 1 && o > 0))
        {
            puts("-1");
            return 0;
        }
        while(o > 3)
        {
            ans.push_back(1);
            o -= 2;
        }
        if(o > 0)
            ans.push_back(o - 1);
    }
    printf("%d\n", ans.size());
    for(auto x: ans)
        printf("%d ", x);
    puts("");
}