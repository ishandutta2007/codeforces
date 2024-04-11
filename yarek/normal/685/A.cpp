#include <bits/stdc++.h>
using namespace std;

int tab[7];

long long sev(int dec)
{
    long long ans = 0, mn = 1;
    while(dec)
    {
        ans += (dec % 7) * mn;
        mn *= 10;
        dec /= 7;
    }
    return ans;
}

int len(long long k)
{
    if(k == 0) return 1;
    for(int i = 0;; i++)
        if(k == 0) return i;
        else k /= 10;
}

int num(int *tab, int len)
{
    int ans = 0;
    while(len--)
    {
        ans *= 10;
        ans += *tab;
        tab++;
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    long long a = sev(n-1), b = sev(m-1);
    int l1 = len(a), l2 = len(b);
    if(l1 + l2 > 7)
    {
        puts("0");
        return 0;
    }
    for(int i = 0; i < 7; i++)
        tab[i] = i;
    set<vector<int> > ok;
    do
    {
        if(num(tab, l1) > a || num(tab + l1, l2) > b)
            continue;
        ok.insert(vector<int>(tab, tab + l1 + l2));
    } while(next_permutation(tab, tab + 7));
    printf("%d\n", ok.size());
}