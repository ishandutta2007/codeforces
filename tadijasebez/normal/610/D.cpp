#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=200050;
int max(int a, int b){ return a>b?a:b;}
vector<int> X,Y;
vector<pair<int,int> > seg1[N],seg2[N];
vector<pair<pair<int,int> ,pair<int,int> > > seg;
void Swap(int &a, int &b){ a^=b,b^=a,a^=b;}
int x1[N],y1[N],x2[N],y2[N];
vector<int> events[N][2];
vector<pair<int,int> > Take[N];
int BIT[N];
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int Get(int l, int r){ return Get(r)-Get(l-1);}
int main()
{
	int n,i,j,k;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&x1[i],&y1[i],&x2[i],&y2[i]);
		if(x1[i]>x2[i]) Swap(x1[i],x2[i]);
		if(y1[i]>y2[i]) Swap(y1[i],y2[i]);
		X.pb(x1[i]);X.pb(x2[i]);
		Y.pb(y1[i]);Y.pb(y2[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	for(i=1;i<=n;i++)
	{
		if(x1[i]==x2[i])
		{
			int id=lower_bound(X.begin(),X.end(),x1[i])-X.begin()+1;
			seg1[id].pb(mp(y1[i],y2[i]));
		}
		else
		{
			int id=lower_bound(Y.begin(),Y.end(),y1[i])-Y.begin()+1;
			seg2[id].pb(mp(x1[i],x2[i]));
		}
	}
	for(i=1;i<=X.size();i++) sort(seg1[i].begin(),seg1[i].end());
	for(i=1;i<=Y.size();i++) sort(seg2[i].begin(),seg2[i].end());
	for(k=1;k<=X.size();k++)
	{
		for(i=0;i<seg1[k].size();i=j)
		{
			int MaxL=seg1[k][i].second;
			for(j=i;j<seg1[k].size();j++)
			{
				if(seg1[k][j].first>MaxL+1) break;
				MaxL=max(MaxL,seg1[k][j].second);
			}
			seg.push_back(mp(mp(X[k-1],seg1[k][i].first),mp(X[k-1],MaxL)));
		}
	}
	int sz=seg.size();
	for(k=1;k<=Y.size();k++)
	{
		for(i=0;i<seg2[k].size();i=j)
		{
			int MaxL=seg2[k][i].second;
			for(j=i;j<seg2[k].size();j++)
			{
				if(seg2[k][j].first>MaxL+1) break;
				MaxL=max(MaxL,seg2[k][j].second);
			}
			seg.push_back(mp(mp(seg2[k][i].first,Y[k-1]),mp(MaxL,Y[k-1])));
		}
	}
	ll sol=0;
	for(i=0;i<seg.size();i++) sol+=(seg[i].second.first-seg[i].first.first+1)*(seg[i].second.second-seg[i].first.second+1);
	//printf("%i %lld\n",seg.size(),sol);
	//for(i=0;i<seg.size();i++) printf("%i %i %i %i\n",seg[i].first.first,seg[i].first.second,seg[i].second.first,seg[i].second.second);
	for(i=sz;i<seg.size();i++)
	{
		int l=lower_bound(X.begin(),X.end(),seg[i].first.first)-X.begin()+1;
		int r=lower_bound(X.begin(),X.end(),seg[i].second.first)-X.begin()+1;
		int id=lower_bound(Y.begin(),Y.end(),seg[i].first.second)-Y.begin()+1;
		events[l][0].pb(id);
		events[r][1].pb(id);
	}
	for(i=0;i<sz;i++)
	{
		int l=lower_bound(Y.begin(),Y.end(),seg[i].first.second)-Y.begin()+1;
		int r=lower_bound(Y.begin(),Y.end(),seg[i].second.second)-Y.begin()+1;
		int id=lower_bound(X.begin(),X.end(),seg[i].first.first)-X.begin()+1;
		Take[id].pb(mp(l,r));
	}
	for(i=1;i<=X.size();i++)
	{
		for(j=0;j<events[i][0].size();j++) Set(events[i][0][j],1);
		for(j=0;j<Take[i].size();j++) sol-=Get(Take[i][j].first,Take[i][j].second);
		for(j=0;j<events[i][1].size();j++) Set(events[i][1][j],-1);
	}
	printf("%lld\n",sol);
	return 0;
}