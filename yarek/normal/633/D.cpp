#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000;
int tab[N];
int used[N];
int cnt[N];
int q[N];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", tab + i);
    sort(tab, tab + n);
    for(int i = 0; i < n; i++)
        cnt[i] = upper_bound(tab, tab + n, tab[i]) - tab - i;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j && cnt[i] == 1) continue;
            if((i > 0 && tab[i] == tab[i-1]) || (j > 0 && tab[j] == tab[j-1])) continue;
            int a = tab[i], b = tab[j];
            used[i]++;
            used[j]++;
            q[0] = i; q[1] = j;
            int m = 2;
            while(true)
            {
                int c = a + b;
                int k = lower_bound(tab, tab + n, c) - tab;
                if(tab[k] != c) break;
                if(used[k] >= cnt[k]) break;
                q[m++] = k;
                used[k]++;
                a = b;
                b = c;
            }
            ans = max(ans, m);
            for(int i = 0; i < m; i++)
                used[q[i]] = 0;
        }
    printf("%d\n", ans);
}