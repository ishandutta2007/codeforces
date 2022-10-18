#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

const int N=2e5+100;

int n;
int t[N];

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i <= n; i = (i | (i+1)))
		t[i] += delta;
}

int a[N];
pii ai[N];
array<int,3> kpi[N];
int ans[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        ai[i].x=-a[i],ai[i].y=i;
    sort(ai+1,ai+n+1);
    for(int i=1;i<=n;i++)
        ai[i].x*=-1;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>kpi[i][0]>>kpi[i][1],
        kpi[i][2]=i;
    sort(kpi+1,kpi+m+1);
    int k=0;
    for(int i=1;i<=m;i++)
    {
        while(k<kpi[i][0])
            k++,
            inc(ai[k].y,1);
        int l=1,r=n;
        while(l<r)
        {
            int x=(l+r)/2;
            if(sum(x)>=kpi[i][1])
                r=x;
            else
                l=x+1;
        }
//        cout<<kpi[i][0]<<"="<<k<<" "<<kpi[i][1]<<" "<<kpi[i][2]<<" -> a["<<l<<"]="<<a[l]<<"\n";
        ans[kpi[i][2]]=a[l];
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
}