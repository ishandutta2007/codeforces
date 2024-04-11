#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110,K=110;

int c[N*K];
int last[N];
pii ans[N];

int t[4*N*K];

int get (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max(get (v*2, tl, tm, l, min(r,tm)),
		       get (v*2+1, tm+1, tr, max(l,tm+1), r));
}

int get_ (int v, int tl, int tr, int l, int r)
{
//    cout<<"get("<<l<<","<<r<<") = ";
    int res=get(v,tl,tr,l,r);
//    cout<<res<<endl;
    return res;
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] += new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

void update_ (int v, int tl, int tr, int pos, int new_val)
{
//    cout<<"update("<<pos<<","<<new_val<<")"<<endl;
    update(v,tl,tr,pos,new_val);
}

#define get get_
#define update update_

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int bound=(n+k-2)/(k-1);
    for(int i=1;i<=n*k;i++)
        cin>>c[i];
    for(int i=1;i<=n*k;i++)
    {
        if(last[c[i]]&&
           !ans[c[i]].x&&
           get(1,1,n*k,last[c[i]],i)<bound)
        {
            ans[c[i]]={last[c[i]],i};
            for(int j=last[c[i]];j<=i;j++)
                update(1,1,n*k,j,1);
        }
        last[c[i]]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i].x<<" "<<ans[i].y<<"\n";
}