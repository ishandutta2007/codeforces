#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[100500];
ll cons[1555];
string s, ans;
int main() {
    //freopen("input.txt","r",stdin);
    string ttt = "aoeui";
    for (i = 0; i < 5; i++)
        cons[ttt[i]] = 1;
    cin >> s;
    char lst;
    bool same = true;
    ll cnt = 0;
    for (i = 0; i < s.size(); i++)
    {
        if (cons[s[i]])
        {
            ans.push_back(s[i]);
            same = true;
            cnt = 0;
            continue;
        } else
        {
            if (cnt == 0)
                cnt++, lst = s[i];
            else
            {
                if (s[i] != lst)
                    same = false;
                cnt++;
                if (same == false && cnt > 2)
                {
                    same = true;
                    cnt = 1;
                    lst = s[i];
                    ans.push_back(' ');
                }
            }
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}