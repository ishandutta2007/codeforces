#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<string>pol;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 998244353;
int n,q;
ll mul[N<<2],add[N<<2],sum[N<<2];
void pushdown(int o,int l,int r)
{
    sum[lo]=(sum[lo]*mul[o]+add[o]*(mid-l+1))%mod;
    sum[ro]=(sum[ro]*mul[o]+add[o]*(r-mid))%mod;
    mul[lo]=mul[lo]*mul[o]%mod;
    mul[ro]=mul[ro]*mul[o]%mod;
    add[lo]=(add[lo]*mul[o]+add[o])%mod;
    add[ro]=(add[ro]*mul[o]+add[o])%mod;

    mul[o]=1;
    add[o]=0;
}
void build(int o=1,int l=1,int r=n)
{
    mul[o]=1;
    if(l==r)return;
    build(lo,l,mid);
    build(ro,mid+1,r);
}
void Mul(int ql,int qr,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        sum[o]=sum[o]*2%mod;
        mul[o]=mul[o]*2%mod;
        add[o]=add[o]*2%mod;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)Mul(ql,qr,lo,l,mid);
    if(qr>mid)Mul(ql,qr,ro,mid+1,r);
    sum[o]=(sum[lo]+sum[ro])%mod;
}
void Add(int ql,int qr,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        sum[o]=(sum[o]+r-l+1)%mod;
        add[o]=(add[o]+1)%mod;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)Add(ql,qr,lo,l,mid);
    if(qr>mid)Add(ql,qr,ro,mid+1,r);
    sum[o]=(sum[lo]+sum[ro])%mod;
}
ll query(int ql,int qr,int o=1,int l=1,int r=n)
{
    if(ql<=l&&r<=qr)
    {
        return sum[o];
    }
    pushdown(o,l,r);
    ll ret=0;
    if(ql<=mid)ret+=query(ql,qr,lo,l,mid);
    if(qr>mid)ret+=query(ql,qr,ro,mid+1,r);
    return ret%mod;
}
set<pii>s[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>q;
	build();
	while(q--)
    {
        int op,l,r,x;
        cin>>op>>l>>r;
        if(op==1)
        {
            cin>>x;
            vector<pii>v;
            while(1)
            {
                auto i=s[x].lower_bound({l,-inf});
                if(i==s[x].end()||i->fi>r)break;
                v.push_back(*i);
                s[x].erase(i);
            }

            if(s[x].lower_bound({l,-inf})==s[x].end()||s[x].lower_bound({l,-inf})->se==0)s[x].insert({r,1});
            else v.push_back({r,1});

            if(s[x].lower_bound({l,-inf})==s[x].begin()||(--s[x].lower_bound({l,-inf}))->se==1)s[x].insert({l,0});
            else v.insert(v.begin(),{l,0});

            if(v.empty())
            {
                Add(l,r);
            }
            else
            {
                if(l!=v[0].fi)Add(l,v[0].fi-1);
                if(r!=v.back().fi)Add(v.back().fi+1,r);
            }

            for(int i=1;i<v.size();i++)
            {
                if(i%2)Mul(v[i-1].fi,v[i].fi);
                else if(v[i].fi>v[i-1].fi+1)Add(v[i-1].fi+1,v[i].fi-1);
            }
        }
        else
        {
            cout<<query(l,r)<<endl;
        }
    }
	return 0;
}