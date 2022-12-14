#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 4e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
string s, t;
int cnt[200];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin >> s >> t;
    if(t.size() > s.size())
    {
        cout << 0;
        return 0;
    }
    for(auto i : t)
        cnt[i]++;

    int bad = 0, ans = 0;
    for(int i = 0; i < t.size(); i++)
        if(s[i] != '?')
        {
            cnt[s[i]]--;
            if(cnt[s[i]] == -1)
                bad++;
        }
    if(!bad)ans++;
    for(int i = t.size(); i < s.size(); i++)
    {
        if(s[i] != '?')
        {
            cnt[s[i]]--;
            if(cnt[s[i]] == -1)
                bad++;
        }
        int j = i - t.size();
        if(s[j] != '?')
        {
            cnt[s[j]]++;
            if(cnt[s[j]] == 0)
                bad--;
        }
        if(!bad)
            ans++;
    }
    cout << ans;
    return 0;
}