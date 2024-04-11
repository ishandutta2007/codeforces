#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

pii a[maxn+5],b[maxn+5];
int k[maxn+5];
int ida[maxn+5],idb[maxn+5];
int ans[maxn+5];

bool cmpa(int x,int y)
{
	return a[x].SE<a[y].SE;
}
bool cmpb(int x,int y)
{
	if(b[x].SE!=b[y].SE) return b[x].SE<b[y].SE;
	return b[x].FI>b[y].FI;
}

int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d%d",&a[i].FI,&a[i].SE);
	int m; scanf("%d",&m);
	rep(i,1,m) scanf("%d%d%d",&b[i].FI,&b[i].SE,&k[i]);
	rep(i,1,n) ida[i]=i;
	rep(i,1,m) idb[i]=i;

	sort(ida+1,ida+n+1,cmpa);
	sort(idb+1,idb+m+1,cmpb);

	vi V; rep(i,1,n) V.pb(a[i].SE); V.pb(inf);
	sort(V.begin(),V.end()); V.erase(unique(V.begin(),V.end()),V.end());
	set<pii> S;
	int i=1,j=1;
	int N=V.size();
	while(j<=m && b[idb[j]].SE<V[0]) j++;
	rep(K,0,N-2)
	{
		int thr=V[K];
		while(i<=n && a[ida[i]].SE<=thr) S.insert(mp(a[ida[i]].FI,ida[i])),i++;
		while(j<=m && b[idb[j]].SE<V[K+1])
		{
			int ID=idb[j];
			while(S.size() && S.lower_bound(mp(b[ID].FI,-1))!=S.end() && k[ID])
			{
				auto it=S.lower_bound(mp(b[ID].FI,-1));
				ans[it->SE]=ID;
				k[ID]--;
				S.erase(it);
			}
			j++;
		}
	}
	int f=1;
	rep(i,1,n) if(ans[i]==0) f=0;
	if(f==0) puts("NO");
	else
	{
		puts("YES");
		rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
	}
	
	return 0;
}