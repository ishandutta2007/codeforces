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
const int N = 2000 + 10;
const int mod = 1e9 + 7;

int n,arr[N],x;
vector<pii>ans;
multiset<int>s;
void f()
{
    for(int i=0;i<n-1;i++)
    {
        int a=*(--s.end());
        s.erase(s.find(a));
        if(s.count(x-a)==0)
        {
            return;
        }
        ans.emplace_back(x-a,a);
        s.erase(s.find(x-a));
        x=a;
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n*2;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n*2+1);
    for(int i=1;i<2*n;i++)
    {
        x=arr[2*n];
        ans.clear();
        s.clear();
        for(int j=1;j<2*n;j++)if(j!=i)
        {
            s.insert(arr[j]);
        }
        ans.emplace_back(arr[i],arr[n*2]);
        f();
        if(ans.size()==n)
        {
//            cout<<x<<endl;
//            cout<<mp[5]<<' '<<mp[6]<<endl;
            cout<<"YES"<<endl;
            cout<<arr[i]+arr[n*2]<<endl;
            for(auto k:ans)
            {
                cout<<k.first<<' '<<k.second<<endl;
            }
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}