#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

//#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int N=2e5+100,INF=2e9+100;

int a[10][N];
pair<int,int> t[10][4*N];

pair<int,int> combine (pair<int,int> a, pair<int,int> b) {
	if(b.first<a.second)
        a.second=b.first;
    if(a.second<a.first)
        swap(a.first,a.second);
	if(b.second<a.second)
        a.second=b.second;
    if(a.second<a.first)
        swap(a.first,a.second);
    return a;
}

void build (int a[], pii t[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_pair (a[tl], INF);
	else {
		int tm = (tl + tr) / 2;
		build (a,t, v*2, tl, tm);
		build (a,t, v*2+1, tm+1, tr);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

pair<int,int> get_max (pii t[], int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair (INF, INF);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine (
		get_max (t,v*2, tl, tm, l, min(r,tm)),
		get_max (t,v*2+1, tm+1, tr, max(l,tm+1), r)
	);
}

void update (pii t[], int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_pair (new_val, INF);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (t,v*2, tl, tm, pos, new_val);
		else
			update (t,v*2+1, tm+1, tr, pos, new_val);
		t[v] = combine (t[v*2], t[v*2+1]);
	}
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0,y=x;j<10;j++,y/=10)
            if(y%10)
                a[j][i]=x;
            else
                a[j][i]=INF;
    }
//    for(int j=0;j<10;j++,cout<<"\n")
//        for(int i=1;i<=n;i++)
//            cout<<a[j][i]<<" ";
    for(int j=0;j<10;j++)
        build(a[j],t[j],1,1,n);
    while(m--)
    {
        int tp;
        cin>>tp;
        if(tp==1)
        {
            int i,x;
            cin>>i>>x;
            for(int j=0,y=x;j<10;j++,y/=10)
                if(y%10)
                    update(t[j],1,1,n,i,x);
                else
                    update(t[j],1,1,n,i,INF);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int ans=INF;
            for(int j=0;j<10;j++)
            {
                pair<int,int> mn=get_max(t[j],1,1,n,l,r);
//                cout<<j<<" -> "<<mn.first<<" "<<mn.second<<"\n";
                if(mn.second!=INF)
                    ans=min(ans,mn.first+mn.second);
            }
            cout<<(ans==INF?-1:ans)<<"\n";
        }
    }
}