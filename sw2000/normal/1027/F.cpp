#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int n;
pii arr[N];
int brr[N],cnt,father[N],sz[N],num[N];
map<int,int>mp;
int ff(int a){return a==father[a]?a:father[a]=ff(father[a]);}
bool solve(int h)
{
    for(int i=1;i<=cnt;i++)father[i]=i,sz[i]=1;
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
    {
        if(arr[i].fi>h)return 0;

        int fa=ff(arr[i].fi),fb=ff(arr[i].se);
        if(arr[i].se<=h)
        {
            if(fa!=fb)
            {
                father[fb]=fa;
                num[fa]+=num[fb];
                sz[fa]+=sz[fb];
            }
        }

        num[fa]++;
    }

    for(int i=1;i<=cnt;i++)if(father[i]==i)
    {
        if(sz[i]<num[i])return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
        brr[++cnt]=arr[i].fi;
        brr[++cnt]=arr[i].se;
    }
    sort(brr+1,brr+1+cnt);
    cnt=unique(brr+1,brr+1+cnt)-brr-1;
    for(int i=1;i<=cnt;i++)
    {
        mp[brr[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        arr[i].fi=mp[arr[i].fi];
        arr[i].se=mp[arr[i].se];
    }
    if(!solve(cnt))
    {
        cout<<-1;
        return 0;
    }
    int l=0,r=cnt;
    while(l!=r-1)
    {
        if(solve(mid))r=mid;
        else l=mid;
    }
    cout<<brr[r];
	return 0;
}