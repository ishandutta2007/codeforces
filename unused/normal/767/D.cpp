#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ASD
{
    int exp, pos;
};

bool comp(ASD A, ASD B)
{
    return A.exp < B.exp;
}

vector<ASD> fridge;
vector<ASD> shop;

int n, m, k, i, a, maxim, sum;
vector < ASD> solution;

int main()
{
    cin.sync_with_stdio(false);
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> a;
        ASD x;
        x.exp = a;
        fridge.push_back(x);
        if (a > maxim)
        {
            maxim = a;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> a;
        ASD x;
        x.exp = a;
        x.pos = i;
        shop.push_back(x);
        if (a > maxim)
            maxim = a;
    }
    sort(fridge.begin(), fridge.begin() + fridge.size(), comp);
    int n = fridge.size();
    sort(shop.begin(), shop.begin() + shop.size(), comp);
    int m = shop.size();
    for (i = maxim; i >= 0; i--)
    {
        ASD x;
        x.exp = i;
        int nr = n - (lower_bound(fridge.begin(), fridge.begin() + n, x, comp) - fridge.begin());
        if (nr > k)
        {
            if (i == 0)
            {
                cout << -1;
                return 0;
            }
            
            nr = k;
            n -= nr;
        }
        else
        {
            put:
            //we can fill with items from shop
            int nrsh = m - (lower_bound(shop.begin(), shop.begin() + m, x, comp) - shop.begin());
            //int capat_stanga = lower_bound(shop.begin(), shop.begin() + m, x, comp);
            //int capat_dreapta = upper_bound(shop.begin(), shop.begin() + m, x, comp);
            //we need nr - k items only
            sum += min(nrsh, k - nr);
            ASD res;
            res.exp = m - min(nrsh, k - nr);
            res.pos = m;
            solution.push_back(res);
            m = m - min(nrsh, k - nr);
            n = n - nr;
        }
        
    }
    cout << sum << "\n";
    for (i = solution.size() - 1; i >= 0; i--)
    {
        for (int j = solution[i].exp; j < solution[i].pos; j++)
        {
            cout << shop[j].pos << " ";
        }
    }
}