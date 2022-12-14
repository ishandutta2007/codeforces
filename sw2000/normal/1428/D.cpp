#include <bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int n,arr[N];
void solve()
{
    int id=n+1;
    vector<pii>ans;
    vector<pii> v1,v2;

    for(int i=n;i;i--)if(arr[i])
    {
        if(arr[i]==1)
        {
            ans.push_back({i,--id});
            v1.push_back({i,id});
        }
        else if(arr[i]==2)
        {
            if(v1.empty())
            {
                cout<<-1;
                return;
            }
            pii t=*(--v1.end());
            v1.pop_back();
            ans.push_back({i,t.se});
            v2.push_back({i,t.se});
        }
        else
        {
            if(v1.empty()&&v2.empty())
            {
                cout<<-1;
                return;
            }
            pii t;
            if(v2.size())
            {
                t=*(--v2.end());
                v2.pop_back();
            }
            else
            {
                t=*(--v1.end());
                v1.pop_back();
            }
            ans.push_back({i,--id});
            ans.push_back({t.fi,id});
            v2.push_back({i,id});
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i.se<<' '<<i.fi<<endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    solve();
    return 0;
}