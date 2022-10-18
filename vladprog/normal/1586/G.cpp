#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define a first
#define b second

const int MOD=1e9+7;

struct vertex {
	vertex * l, * r;
	int sum;

	vertex (int val)
		: l(NULL), r(NULL), sum(val)
	{ }

	vertex (vertex * l, vertex * r)
		: l(l), r(r), sum(0)
	{
		if (l)  sum += l->sum;
		if (r)  sum += r->sum;
		sum%=MOD;
	}
};

vertex * build (int tl, int tr) {
	if (tl == tr)
		return new vertex (0);
	int tm = (tl + tr) / 2;
	return new vertex (
		build (tl, tm),
		build (tm+1, tr)
	);
}

int get_sum (vertex * t, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && tr == r)
		return t->sum;
	int tm = (tl + tr) / 2;
	return (get_sum (t->l, tl, tm, l, min(r,tm))
		+ get_sum (t->r, tm+1, tr, max(l,tm+1), r))%MOD;
}

vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		return new vertex (new_val);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return new vertex (
				update (t->l, tl, tm, pos, new_val),
				t->r
			);
	else
		return new vertex (
				t->l,
				update (t->r, tm+1, tr, pos, new_val)
			);
}

const int N=2e5+100;

struct In
{
    int a,b,i;
    friend bool operator<(In l,In r)
    {
        return l.b<r.b;
    }
};

In in[N];
int where[N];
int s[N];
vertex* tree[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>in[i].a>>in[i].b,
        in[i].i=i;
    sort(in+1,in+n+1);
    for(int i=1;i<=n;i++)
        where[in[i].i]=i,
        in[i].i=i;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        cin>>s[i],
        s[i]=where[s[i]];
    sort(s+1,s+t+1);
    tree[0]=build(1,2*n);
    for(int i=1;i<=n;i++)
    {
        int a=in[i].a,b=in[i].b;
        int res=(get_sum(tree[i-1],1,2*n,a,b)+1)%MOD;
//        cout<<res<<" ";
        tree[i]=update(tree[i-1],1,2*n,a,res);
    }
//    cout<<"\n";
    vector<In> need{in[s[t]]};
    for(int i=t-1;i>=1;i--)
        if(need.back().a<in[s[i]].a&&in[s[i]].b<need.back().b)
            need.push_back(in[s[i]]);
//    for(int q=0;q<need.size();q++)
//    {
//        auto[A,B,I]=need[q];
//        cout<<A<<" "<<B<<" "<<I<<"\n";
//    }
    int ans=(get_sum(tree[need[0].i-1],1,2*n,1,2*n)+1)%MOD;
    for(int q=0;q+1<need.size();q++)
    {
        auto[A,B,I]=need[q];
        auto[a,b,i]=need[q+1];
        int cur=get_sum(tree[i-1],1,2*n,A,B);
//        cout<<cur<<" ";
        ans+=cur+1;
        ans%=MOD;
    }
//    cout<<"\n";
    cout<<ans;
}