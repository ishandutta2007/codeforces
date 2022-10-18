#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=2e5+100;

tuple<int,int,int> inp[N];
int x[N],p[N],ind[N],res[N];
bool ans[N];

int add[4*N];
void build_add (int v, int tl, int tr) {
	if (tl == tr)
		add[v] = res[tl]+x[tl];
	else {
		int tm = (tl + tr) / 2;
		build_add (v*2, tl, tm);
		build_add (v*2+1, tm+1, tr);
		add[v] = max(add[v*2], add[v*2+1]);
	}
}
int get_add (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return -3e9;
	if (l == tl && r == tr)
		return add[v];
	int tm = (tl + tr) / 2;
	return max(get_add (v*2, tl, tm, l, min(r,tm)),
		       get_add (v*2+1, tm+1, tr, max(l,tm+1), r));
}

int sub[4*N];
void build_sub (int v, int tl, int tr) {
	if (tl == tr)
		sub[v] = res[tl]-x[tl];
	else {
		int tm = (tl + tr) / 2;
		build_sub (v*2, tl, tm);
		build_sub (v*2+1, tm+1, tr);
		sub[v] = max(sub[v*2], sub[v*2+1]);
	}
}
int get_sub (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return -3e9;
	if (l == tl && r == tr)
		return sub[v];
	int tm = (tl + tr) / 2;
	return max(get_sub (v*2, tl, tm, l, min(r,tm)),
		       get_sub (v*2+1, tm+1, tr, max(l,tm+1), r));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>get<0>(inp[i])>>get<1>(inp[i]),
            get<2>(inp[i])=i;
        sort(inp+1,inp+n+1);
        for(int i=1;i<=n;i++)
            tie(x[i],p[i],ind[i])=inp[i];
        int cur=0;
        multiset<int> s;
        for(int i=1;i<=n;i++)
        {
            while(!s.empty()&&*s.begin()<x[i])
                cur-=*s.begin(),
                s.erase(s.begin());
            cur+=p[i]+x[i];
            s.insert(x[i]+p[i]);
            res[i]=cur-x[i]*s.size();
        }
        cur=0;
        s.clear();
        for(int i=n;i>=1;i--)
        {
            while(!s.empty()&&*prev(s.end())>x[i])
                cur+=*prev(s.end()),
                s.erase(prev(s.end()));
            res[i]+=cur+x[i]*s.size();
            cur+=p[i]-x[i];
            s.insert(x[i]-p[i]);
        }
        int first=n+1;
        for(int i=n;i>=1;i--)
            if(res[i]>m)
                first=i;
        int last=0;
        for(int i=1;i<=n;i++)
            if(res[i]>m)
                last=i;
        build_add(1,1,n);
        build_sub(1,1,n);
//        for(int i=1;i<=n;i++)
//            cout<<i<<" -> "<<x[i]<<" "<<p[i]<<" "<<res[i]<<endl;
        for(int i=1;i<=n;i++)
        {
            int l=x[i]-p[i],r=x[i]+p[i];
            l=lower_bound(x+1,x+n+1,l)-x;
            r=upper_bound(x+1,x+n+1,r)-x-1;
            if(first<l||last>r)
            {
                ans[ind[i]]=0;
                continue;
            }
            l=get_sub(1,1,n,l,i);
            r=get_add(1,1,n,i,r);
            l=l+x[i]-p[i];
            r=r-x[i]-p[i];
            ans[ind[i]]=(max(l,r)<=m);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i];
        cout<<"\n";
    }
}