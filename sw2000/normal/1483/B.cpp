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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
void solve()
{
    cin>>n;
    map<int,int>arr;
    set<int>del;
    vi ans;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        arr[i]=a;
    }
    for(int i=0;i<n;i++)
    {
        if(__gcd(arr[i],arr[(i+1)%n])==1)
        {
            del.insert(i);
        }
    }
//    for(auto i:del)cout<<i<<' ';cout<<endl;

    int v=-1;
    while(del.size())
    {
        if(v>=*(--del.end()))v=*del.begin();
        else v=*del.upper_bound(v);

        del.erase(v);

        int u;
        if(v>=(--arr.end())->fi)u=arr.begin()->fi;
        else u=arr.upper_bound(v)->fi;

        ans.push_back(u);
        arr.erase(u);
        del.erase(u);

        if(arr.empty())
        {
//            cout<<32425<<endl;
            break;
        }

        if(v>=(--arr.end())->fi)u=arr.begin()->fi;
        else u=arr.upper_bound(v)->fi;

        if(__gcd(arr[u],arr[v])==1)del.insert(v);
    }

    cout<<ans.size();
    for(auto i:ans)cout<<' '<<i+1;
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        solve();
    }

	return 0;
}