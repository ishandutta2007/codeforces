#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#define Debug(in) cout<<#in<<"="<<(in)<<endl
#define mm(a,x) memset(a,x,sizeof(a))
#define mkp(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0)
#define endl '\n'
#define lr rt<<1
#define rr rt<<1|1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mod=1e9+7;
const int N=1e6;
int m,id[300005];
struct node{
    ll x,s;
}q[N<<2];
node merge(node a,node b)
{
    node c;
    c.s=a.s+b.s;
    c.x=max(b.x,a.x+b.s);
    return c;
}
void upd(int rt,int l,int r,int p,int x)
{
    if(l==r)
    {
        q[rt].s=x;
        q[rt].x=l+x;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) upd(lr,l,m,p,x);
    else upd(rr,m+1,r,p,x);
    q[rt]=merge(q[lr],q[rr]);
}
node qry(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return q[rt];
    int m=(l+r)>>1;
    if(m<L) return qry(rr,m+1,r,L,R);
    if(m>=R) return qry(lr,l,m,L,R);
    return merge(qry(lr,l,m,L,R),qry(rr,m+1,r,L,R));
}
int main(void)
{
    sync;
    cin>>m;
    for(int idx=1;idx<=m;++idx)
    {
        string op;
        cin>>op;
        if(op[0]=='+')
        {
            int t,d;
            cin>>t>>d;
            id[idx]=t;
            upd(1,1,N,t,d);
        }
        else if(op[0]=='-')
        {
            int i;
            cin>>i;
            upd(1,1,N,id[i],0);
        }
        else
        {
            int t;
            cin>>t;
            cout<<max(0ll,qry(1,1,N,1,t).x-t)<<endl;
        }
    }
    return 0;
}
//
//Think TWICE, Code ONCE!