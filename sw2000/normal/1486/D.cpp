#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n,k,arr[N],pre[N];
bool can(int a)
{
    map<int,int>mp;
    mp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>=a)pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1]-1;
        if(mp.find(pre[i])==mp.end())
            mp[pre[i]]=i;

        int b=min(0,pre[i]-1);
        if(mp.find(b)!=mp.end()&&i-mp[b]>=k)
            return 1;
    }
    return 0;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int l=1,r=n+1;
    while(l<r-1)
    {
        if(can(mid))l=mid;
        else r=mid;
    }

    cout<<l;
	return 0;
}