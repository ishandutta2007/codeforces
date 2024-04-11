#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int K = 1000001;
int cont[3][K];
int tab[K];
vector<ll> vec[3];

ll read(int cnt)
{
    ll ans = 1;
    for(int i = 0; i < 3; i++)
    {
        int x;
        scanf("%d", &x);
        ans *= x;
        for(int j = 2; j <= 1000; j++)
            while(x % j == 0)
            {
                x /= j;
                vec[cnt].push_back(j);
                cont[cnt][j]++;
            }
        if(x != 1)
        {
            vec[cnt].push_back(x);
            cont[cnt][x]++;
        }
    }
    return ans;
}

ll poww(ll a, int b)
{
    if(b == 0) return 1;
    if(b & 1) return a * poww(a, b - 1);
    return poww(a * a, b / 2);
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        ll n = read(0), m = read(1), s = read(2);
        s *= 2;
        cont[2][2]++;
        vec[2].push_back(2);
        for(int i = 0; i < 3; i++)
        {
            sort(vec[i].begin(), vec[i].end());
            vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
        }
        ll k = 1;
        ll ans = 0;
        for(int i = 0; i < vec[2].size(); i++)
            tab[i] = -1;
        for(int i = 0; i >= 0; )
            if(i == vec[2].size())
            {
                if(k <= n) ans++;
                i--;
            }
            else if(tab[i] == cont[2][vec[2][i]])
            {
                while(tab[i]--)
                    k /= vec[2][i];
                i--;
            }
            else
            {
                if(++tab[i] != 0)
                    k *= vec[2][i];
                i++;
            }
        vector<ll> forb;
        for(auto x: vec[0])
            if(cont[0][x] > cont[2][x])
                forb.push_back(poww(x, cont[2][x] + 1));
        k = 1;
        ans += m;
        for(int i = 1, j = 0; i < (1 << forb.size()); i++)
        {
            int x = i ^ (i / 2);
            assert(__builtin_popcount(x ^ j) == 1);
            int diff = __builtin_ctz(x ^ j);
            if(x > j)
                k *= forb[diff];
            else k /= forb[diff];
            ans += m / k * (__builtin_popcount(x) % 2 ? -1 : 1);
            j = x;
        }
        printf("%lld\n", ans);
        for(int i = 0; i < 3; i++)
        {
            for(auto x: vec[i])
                cont[i][x] = 0;
            vec[i].clear();
        }
    }
}