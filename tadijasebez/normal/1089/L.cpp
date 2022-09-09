#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}

int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	vector<vector<int> > a(k);
	vector<int> done(k);
	vector<int> niz(n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        niz[i]--;
    }
    vector<int> cost(n);
    for(int i=0;i<n;i++)
        scanf("%i",&cost[i]);
    for(int i=0;i<n;i++)
    {
        a[niz[i]].pb(cost[i]);
        done[niz[i]]=1;
    }
    vector<int> costs;
    int cnt=0;
    for(int i=0;i<k;i++)
    {
        if(!done[i])
            cnt++;
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());
        for(int j=1;j<a[i].size();j++)
            costs.pb(a[i][j]);
    }
    sort(costs.begin(),costs.end());
    ll sol=0;
    for(int i=0;i<cnt;i++)
        sol+=costs[i];
    printf("%lld\n",sol);
    return 0;
}