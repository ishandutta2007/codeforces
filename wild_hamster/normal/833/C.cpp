#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,w,path_w,m,a[100500],used[100500], t[100500];
ll num_cnt[15], sz, ans;
vector<ll> num1, num2;
void try_to_count(int x, int bot)
{
    if (x != sz)
    {
        for (int i = bot; i <= 9; i++)
        {
            num_cnt[i]++;
            try_to_count(x+1, i);
            num_cnt[i]--;
        }
    }

    for (int j = num1[0]+1; j < num2[0]; j++)
        if (num_cnt[j] > 0)
        {
            ans++;
            return;
        }
    a[0] = sz-x;
    for (int i = 1; i <= 9; i++)
        a[i] = num_cnt[i];
    if (a[num1[0]])
    {
        a[num1[0]]--;
        int bs = 9;
        int i;
        for (i = 1; i < sz; i++)
        {
            for (int j = num1[i]+1; j <= bs; j++)
            {
                if (a[j])
                {
                    ans++;
                    return;
                }
            }
            bs = num1[i];
            if (a[bs] == 0)
                break;
            a[bs]--;
        }
        if (i == sz)
        {
            ans++;
            return;
        }
    }
    a[0] = sz-x;
    for (int i = 1; i <= 9; i++)
        a[i] = num_cnt[i];
    if (a[num2[0]])
    {
        a[num2[0]]--;
        int bs = 0;
        for (i = 1; i < sz; i++)
        {
            for (int j = bs; j < num2[i]; j++)
            {
                if (a[j])
                {
                    ans++;
                    return;
                }
            }
            bs = num2[i];
            if (a[bs] == 0)
                break;
            a[bs]--;
        }
        if (i == sz)
        {
            ans++;
            return;
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    long long x,y;
    cin >> x >> y;
    if (x == y)
    {
        cout << 1 << endl;
        return 0;
    }
    while (x)
    {
        num1.push_back(x%10);
        x /= 10;
    }
    while (y)
    {
        num2.push_back(y%10);
        y /= 10;
    }
    sz = num2.size();
    while (num1.size() < sz)
    {
        num1.push_back(0);
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int l = 0;
    while (l < sz && num1[l] == num2[l])
        l++;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (i = 0; i < l; i++)
    {
        num1.pop_back();
        num2.pop_back();
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    sz = num1.size();
    try_to_count(0, 1);
    cout << ans << endl;
    return 0;
}