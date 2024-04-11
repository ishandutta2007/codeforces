#include <bits/stdc++.h>
using namespace std;

const int K = 10, L = 19;
int tab[K];
int tmp[K];
int c[L];
typedef long long ll;

int main()
{
    ll l, r;
    scanf("%lld %lld", &l, &r);
    for(int i = L - 1; i >= 0; i--)
    {
        c[i] = l % 10;
        l /= 10;
    }
    int sum = 0;
    for(int i = 1; i < K; i++)
        tab[i] = -1;
    int ans = 0;
    for(int i = 0; i >= 0;)
    {
        if(i == K - 1)
        {
            tab[K-1] = L - sum;
            ll x = 0;
            copy(tab, tab + K, tmp);
            int last = -1;
            int mx = 9;
            while(!tmp[mx]) mx--;
            for(int j = 0; j < L; j++)
            {
                x *= 10;
                int y = c[j];
                if(tmp[y])
                {
                    tmp[y]--;
                    x += y;
                    if(mx > y) last = j;
                    while(!tmp[mx]) mx--;
                }
                else
                {
                    for(int k = y + 1; ; k++)
                    {
                        if(k == K)
                        {
                            x = -1;
                            break;
                        }
                        if(tmp[k])
                        {
                            x += k;
                            tmp[k]--;
                            for(int t = 0; t < K; t++)
                                while(tmp[t]--)
                                    x = x * 10 + t;
                            break;
                        }
                    }
                    break;
                }
            }
            if(x != -1 || last != -1)
            {
                if(x == -1)
                {
                    x = 0;
                    copy(tab, tab + K, tmp);
                    for(int j = 0; j < last; j++)
                    {
                        tmp[c[j]]--;
                        x = x * 10 + c[j];
                    }
                    for(int j = c[last] + 1; ; j++)
                        if(tmp[j])
                        {
                            x = x * 10 + j;
                            tmp[j]--;
                            break;
                        }
                    for(int j = 0; j < K; j++)
                        while(tmp[j]--)
                            x = x * 10 + j;
                }
                if(x <= r) ans++;
            }
            i--;
        }
        if(++tab[i]) sum++;
        if(sum > L)
        {
            sum -= tab[i];
            tab[i] = -1;
            i--;
        }
        else i++;
    }
    printf("%d\n", ans);
}