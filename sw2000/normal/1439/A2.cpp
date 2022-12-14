#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
bool boa[110][110];
int n, m;
vector<vi>ans;
void add(int x, int y)
{
    vi a;
    if(boa[x][y])
    {
        boa[x][y] = 0;
        a.push_back(x);
        a.push_back(y);
    }
    if(boa[x][y + 1])
    {
        boa[x][y + 1] = 0;
        a.push_back(x);
        a.push_back(y + 1);
    }
    if(a.empty())
        return;
    a.push_back(x + 1);
    a.push_back(y);
    boa[x + 1][y] = !boa[x + 1][y];
    if(a.size() != 6)
    {
        a.push_back(x + 1);
        a.push_back(y + 1);
        boa[x + 1][y + 1] = !boa[x + 1][y + 1];
    }
    ans.push_back(a);
}
void add2(int x, int y)
{
    vi a;
    if(boa[x][y])
    {
        a.push_back(x);
        a.push_back(y);
        boa[x][y] = 0;
    }
    if(boa[x + 1][y])
    {
        a.push_back(x + 1);
        a.push_back(y);
        boa[x + 1][y] = 0;
    }
    if(a.empty())
        return;
    a.push_back(x);
    a.push_back(y + 1);
    boa[x][y + 1] = !boa[x][y + 1];
    if(a.size() != 6)
    {
        a.push_back(x + 1);
        a.push_back(y + 1);
        boa[x + 1][y + 1] = !boa[x + 1][y + 1];
    }
    ans.push_back(a);
}
void add3(int x, int y)
{
//    for(int i=1;i<3;i++)
//    {
//        for(int j=1;j<3;j++)
//            cout<<boa[i][j];
//        cout<<endl;
//    }
    vi a;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(boa[x+i][y+j])
            {
                a.push_back(x + i);
                a.push_back(y + j);
            }
    if(a.size()==0)
        return;
    if(a.size()==4)
    {

    a.pop_back();
    a.pop_back();
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(!boa[x+i][y+j])
            {
                a.push_back(x + i);
                a.push_back(y + j);
            }
    if(a.size()==8)
    {
        a.pop_back();
    a.pop_back();
    }


    ans.push_back(a);
    for(int i=0;i<6;i+=2)
    {
        boa[a[i]][a[i+1]]=!boa[a[i]][a[i+1]];
    }
    add3(x,y);
}
void solve()
{
    ans.clear();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++)
            boa[i][j] = s[j - 1] - '0';
    }


    for(int i = 1; i <= n - 2; i++)
        for(int j = 1; j < m; j++)
            add(i, j);
    for(int i = 1; i <= m - 2; i++)
        add2(n - 1, i);
    add3(n - 1, m - 1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin >> _;
    while(_--)
    {
        solve();
//        cout<<boa[1][1]<<endl;
        cout << ans.size() << endl;
        for(auto i:ans)
        {
            for(auto j:i)
                cout<<j<<' ';
            cout<<endl;
        }
    }
    return 0;
}