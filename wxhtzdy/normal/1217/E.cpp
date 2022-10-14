#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0)
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define erase_uni(x) x.erase(unique(all(x)),x.end())
#define inv(n) power((n), mod - 2)
#define ff(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define fff(i,a,b) for (int (i) = (a); (i) <= b; (i)++)
#define bff(i,a,b) for (int (i) = (b)-1; (i) >= (a); (i)--)
#define bfff(i,a,b) for (int (i) = (b); (i) >= (a); (i)--)
#define sum_overflow(a,b) __builtin_add_overflow_p ((a), (b), (__typeof__ ((a) + (b))) 0)
#define mul_overflow(a,b) __builtin_mul_overflow_p ((a), (b), (__typeof__ ((a) + (b))) 0)

using namespace std;
long double typedef ld;
unsigned int typedef ui;
long long int typedef li;
pair<int,int> typedef pii;
pair<li,li> typedef pli;
pair<ld,ld> typedef pld;
vector<vector<int>> typedef graph;
unsigned long long int typedef ull;
//const int mod = 998244353;
const int mod = 1000000007;

/*using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using omset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;*/







//Note to self: Check for overflow


const int inf=1e9+5;
int a[200005];
pii st[800005][10];

pii mrg(pii a,pii b)
{
    if (a.yy>b.xx) a.yy=b.xx;
    if (a.xx>a.yy) swap(a.xx,a.yy);
    if (a.yy>b.yy) a.yy=b.yy;
    if (a.xx>a.yy) swap(a.xx,a.yy);
    return a;
}

void pull(int p)
{
    ff(i,0,10) st[p][i]=mrg(st[p*2][i],st[p*2+1][i]);
}

void Build(int p,int l,int r)
{
    if (l==r)
    {
        int x=a[l];
        ff(i,0,10)
        {
            if (x%10==0) st[p][i]=mp(inf,inf); else st[p][i]=mp(a[l],inf);
            x/=10;
        }
        return;
    }
    int mid=(l+r)/2;
    Build(p*2,l,mid), Build(p*2+1,mid+1,r);
    pull(p);
}

void Upd(int p,int l,int r,int i)
{
    if (l==r)
    {
        int x=a[l];
        ff(i,0,10)
        {
            if (x%10==0) st[p][i]=mp(inf,inf); else st[p][i]=mp(a[l],inf);
            x/=10;
        }
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid) Upd(p*2,l,mid,i);
    else Upd(p*2+1,mid+1,r,i);
    pull(p);
}

pii Query(int p,int l,int r,int ql,int qr,int d)
{
    if (l>r||l>qr||r<ql) return mp(inf,inf);
    if (ql<=l&&r<=qr) return st[p][d];
    int mid=(l+r)/2;
    return mrg(Query(p*2,l,mid,ql,qr,d), Query(p*2+1,mid+1,r,ql,qr,d));
}

int main()
{
    FAST;

    int n,m; cin>>n>>m;
    ff(i,0,n) cin>>a[i];

    Build(1,0,n-1);
    while (m--)
    {
        int op; cin>>op;
        if (op==1)
        {
            int i,x; cin>>i>>x; --i;
            a[i]=x, Upd(1,0,n-1,i);
        }
        else
        {
            int l,r; cin>>l>>r; --l,--r;
            int mn=2*inf;
            ff(i,0,10)
            {
                pii vv=Query(1,0,n-1,l,r,i);
                if (vv.yy<inf) mn=min(mn,vv.xx+vv.yy);
            }
            if (mn==2*inf) mn=-1;
            cout<<mn<<"\n";
        }
    }
}

//Note to self: Check for overflow