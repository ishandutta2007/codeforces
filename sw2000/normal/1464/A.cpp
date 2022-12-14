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
const int N = 5e5 + 10;
const int mod = 1e9 + 7;
int n,m;
int father[N];
int ff(int a){return a==father[a]?a:father[a]=ff(father[a]);}
int solve()
{
    int ret=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)father[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a!=b)
        {
            int fa=ff(a),fb=ff(b);
            if(fa==fb)ret+=2;
            else
            {
                ret++;
                father[fa]=fb;
            }
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}