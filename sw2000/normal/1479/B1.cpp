#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
//#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n,arr[N];
vector<pii>v;
int main()
{
//    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==arr[i-1])
        {
            v.back().se++;
        }
        else
        {
            v.push_back({arr[i],1});
            ans++;
        }
    }
    for(int i=0;i<v.size();i++)if(v[i].se!=1)
    {
        vi t{v[i].fi};
        int j=i-1;
        for(;j>=0&&v[j].se==1;j--)
        {
            t.push_back(v[j].fi);
        }
//        cout<<j<<endl;
        if(j<0||v[j].fi!=v[i].fi)ans++;
        else
        {
            t.push_back(v[j].fi);
            for(j=1;j<t.size()-1;j+=2)
            {
                if(t[j-1]!=t[j+1]&&t[j]!=v[i].fi)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
	return 0;
}