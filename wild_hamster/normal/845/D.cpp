#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y, b[500000], ans[500500];
pii a[500500];
vector<ll> speed;
string s;
int main() {
    //freopen("input.txt", "r", stdin);
    ll razr = 1, cur_speed = 0, alr = 0, alr2 = 0, cnt = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d",&y);
            cur_speed = y;
            while (!speed.empty() && speed.back() < cur_speed)
            {
                k++;
                speed.pop_back();
            }
        } else
        if (x == 2)
        {
            if (razr == 0)
            {
                k+=cnt;
                cnt = 0;
            }
        } else
        if (x == 3)
        {
            scanf("%d",&y);
            speed.push_back(y);
            while (!speed.empty() && speed.back() < cur_speed)
            {
                k++;
                speed.pop_back();
            }
        } else
        if (x == 4)
        {
            razr = 1;
            alr2 = 0;
            cnt = 0;
        } else
        if (x == 5)
            speed.clear();
        else
            razr = 0, alr2 = 0, cnt++;
    }
    cout << k << endl;
    return 0;
}