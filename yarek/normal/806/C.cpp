#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K = 45;
int cnt[K+5];
int diff[K+5];
int buc[K+5];
int bucsum[K+5];

int main()
{
    map<ll, int> mp;
    for(int i = 0; i < K; i++)
        mp[1LL << i] = i;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        ll a;
        scanf("%lld", &a);
        if(mp.count(a)) cnt[mp[a]]++;
        else
        {
            for(int i = 0; i < K; i++)
                if((1LL << (i + 1)) >= a)
                {
                    buc[i]++;
                    break;
                }
        }
    }
    for(int i = 0; i + 1 < K; i++)
    {
        diff[i] = cnt[i] - cnt[i+1];
        if(diff[i] < 0)
        {
            cnt[i+1] += diff[i];
            buc[i] -= diff[i];
            diff[i] = 0;
        }
    }
    int mx = cnt[0], best = -1;    
    for(int i = mx; i > 0; i--)
    {
        for(int j = K - 2; j >= 0; j--)
            bucsum[j] = bucsum[j+1] + buc[j];
        bool ok = true;
        for(int j = 0; j < K; j++)
            if(bucsum[j] > cnt[j])
                ok = false;
        if(!ok) break;
        best = i;
        bool found = false;
        for(int j = 0; j < K; j++)
            if(diff[j])
            {
                diff[j]--;
                for(int k = 0; k <= j; k++)
                {
                    cnt[k]--;
                    buc[max(0, k - 1)]++;
                }
                found = true;
                break;
            }
        if(!found) break;
    }
    if(best == -1)
        puts("-1");
    else
    {
        for(int i = best; i <= mx; i++)
            printf("%d ", i);
        puts("");
    }
}