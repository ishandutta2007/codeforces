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
const int mod = 1e9 + 7;

int n,q,sum[N<<2];
string s,t;
pii arr[N];
void pushdown(int o,int l,int r)
{
    if(sum[o]==0)
    {
        sum[lo]=sum[ro]=0;
    }
    if(sum[o]==r-l+1)
    {
        sum[lo]=mid-l+1;
        sum[ro]=r-mid;
    }
}
void update(int ql,int qr,int v,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        if(v)sum[o]=r-l+1;
        else sum[o]=0;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)update(ql,qr,v,lo,l,mid);
    if(qr>mid)update(ql,qr,v,ro,mid+1,r);
    sum[o]=sum[lo]+sum[ro];
}
int query(int ql,int qr,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        return sum[o];
    }
    pushdown(o,l,r);
    int ret=0;
    if(ql<=mid)ret+=query(ql,qr,lo,l,mid);
    if(qr>mid)ret+=query(ql,qr,ro,mid+1,r);
    return ret;
}
bool solve()
{
    cin>>n>>q;
    cin>>s>>t;
    for(int i=1;i<=q;i++)
    {
        cin>>arr[i].fi>>arr[i].se;
    }
    update(1,n,0);
    for(int i=0;i<n;i++)
    {
        if(t[i]=='1')update(i+1,i+1,1);
    }

    for(int i=q;i;i--)
    {
        int l=arr[i].se-arr[i].fi+1;
        int t=query(arr[i].fi,arr[i].se);
        if(l%2==0&&t==l/2)return 0;

        if(t<=l/2)
        {
            update(arr[i].fi,arr[i].se,0);
        }
        else
        {
            update(arr[i].fi,arr[i].se,1);
        }
    }

    for(int i=1;i<=n;i++)
    {
        int a=query(i,i);
        if(a+'0'!=s[i-1])return 0;
    }
    return 1;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;
	cin>>_;
	while(_--)
    {
        cout<<(solve()?"YES":"NO")<<endl;
    }
	return 0;
}