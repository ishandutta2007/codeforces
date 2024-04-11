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
ll two[N];
pii arr[N];
int father[N];
map<int,int>ans;
vi id[N];
int ff(int a)
{
    return a==father[a]?a:father[a]=ff(father[a]);
}
int main()
{
    two[0]=1;
    for(int i=1;i<N;i++)
        two[i]=two[i-1]*2%mod;
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        father[i]=i;

    for(int i=1;i<=n;i++)
    {
        int o;
        cin>>o>>arr[i].fi;
        if(o==2)
        {
            cin>>arr[i].se;
        }
        else
        {
            arr[i].se=m+1;
        }
        if(arr[i].fi>arr[i].se)swap(arr[i].fi,arr[i].se);
    }

    for(int i=1;i<=n;i++)
    {
        if(ans.find(arr[i].fi)!=ans.end())
        {
            int a=ans[arr[i].fi];
            int fa=ff(a);
            arr[i].fi=arr[fa].se;
        }
        if(ans.find(arr[i].se)!=ans.end())
        {
            int a=ans[arr[i].se];
            int fa=ff(a);
            arr[i].se=arr[fa].se;
        }
        if(arr[i].fi>arr[i].se)swap(arr[i].fi,arr[i].se);
//        cout<<arr[i].fi<<' '<<arr[i].se<<endl;
        if(arr[i].fi!=arr[i].se)
        {
            ans[arr[i].fi]=i;
            for(auto a:id[arr[i].fi])
            {
                int fa=ff(a);
                father[fa]=i;
            }
            id[arr[i].se].push_back(i);
        }
    }
    cout<<two[ans.size()]<<' '<<ans.size()<<endl;
    vi tmp;
    for(auto i:ans)
        tmp.push_back(i.se);
    sort(tmp.begin(),tmp.end());
    for(auto i:tmp)
        cout<<i<<' ';
	return 0;
}