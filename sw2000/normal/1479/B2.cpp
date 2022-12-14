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

int n,arr[N],a,b,ans;
vi v;
int main()
{
//    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=arr[i-1])v.push_back(arr[i]);
    }
    ans=v.size();
    set<int>s;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==a)
        {
            ans--;
            if(s.size())b=v[i-1];
            s.clear();
        }
        else if(v[i]==b)
        {
            ans--;
            if(s.size())a=v[i-1];
            s.clear();
        }
        else if(s.count(v[i]))
        {
            ans--;
            s.clear();
            a=v[i];
            b=v[i-1];
        }
        else s.insert(v[i]);
    }
    cout<<ans;
	return 0;
}