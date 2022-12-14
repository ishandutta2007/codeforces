#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
int f(string s)
{
    int l=s.size();
    for(int i=1;i<=l;i++)
    {
        if(l%i==0)
        {
            int f=1;
            for(int j=i;j<l;j++)
            {
                if(s[j]!=s[j-i])
                {
                    f=0;
                }
            }
            if(f)return i;
        }
    }
}
void solve()
{
    string a,b;
    int aa=0,bb=0;
    cin>>a>>b;
    aa=f(a);
    bb=f(b);
    if(a.substr(0,aa)!=b.substr(0,bb))
    {
        cout<<-1;
        return;
    }
    for(int i=1;;i++)
    {
        cout<<a.substr(0,aa);
        if(i*aa%a.size()==0&&i*aa%b.size()==0)return;
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}