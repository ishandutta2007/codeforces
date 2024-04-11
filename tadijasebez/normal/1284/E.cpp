#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
struct pt{ ll x,y;pt(){}pt(ll a, ll b):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
ll dot(pt a, pt b){ return a.x*b.x+a.y*b.y;}
int qw(pt a){ return (a.y>0 || (a.y==0 && a.x>0))?0:1;}
bool cmp_p(pt a, pt b){ return mp(qw(a),(ll)0)<mp(qw(b),cross(a,b));}
ll ans=0;
const int N=2505;
pt a[N];
int n;
/*void Solve(int id)
{
	for(int i=1;i<=n;i++) qs[i]=ps[i]-ps[id];
	swap(qs[id],qs[n]);
	for(int i=1;i<n;i++)
	{
		ang[i]=atan2(qs[i].y,qs[i].x);
		if(ang[i]<0) ang[i]+=PI;
		ord[i]=i;
	}
	sort(ord+1,ord+n,[&](int i, int j){ return ang[i]<ang[j];});
	//for(int i=0;i<2;i++) for(int j=0;j<3;j++) sum[i][j]=0;
	for(int i=1;i<n;i++) hal[i]=(qs[i].y>=0);//,sum[hal[i]][qs[i].c]++;
	//auto Get=[&](int j, int h){ ll ret=1;for(int i=0;i<3;i++) if(i!=qs[j].c) ret*=sum[h][i];return ret;};
	//for(int j=1,i;i=ord[j],j<n;j++)
	//{
	//	sum[hal[i]][qs[i].c]--;
	//	ans+=Get(i,0)*Get(n,1)+Get(i,1)*Get(n,0);
	//	sum[hal[i]^1][qs[i].c]++;
	//}
}*/
const ldb PI=acos(-1);
void Solve(int x)
{
	vector<pt> pts;
	for(int i=1;i<=n;i++) if(i!=x) pts.pb(a[i]-a[x]);
	sort(pts.begin(),pts.end(),cmp_p);
	int n=pts.size();
	vector<pair<pt,int>> evs;
	for(int i=0;i<n;i++)
	{
		//ldb ang=atan2(pts[i].y,pts[i].x);
		//if(pts[i].y==0) ang=0;
		//if(ang<0) ang+=PI;
		if(qw(pts[i])==0) evs.pb({pts[i],i});
		else evs.pb({pt(0,0)-pts[i],i});
	}
	sort(evs.begin(),evs.end(),[&](pair<pt,int> a, pair<pt,int> b){ return cmp_p(a.first,b.first);});
	int mn_l=0,mn_r=0;
	vector<int> L,R;
	ll sum=0;
	auto Add_L=[&](int id)
	{
		int bot=mn_r,top=R.size(),mid;
		while(bot<top)
		{
			mid=top+bot>>1;
			if(cross(pts[R[mid]],pts[id])<0) bot=mid+1;
			else top=mid;
		}
		sum+=top-mn_r;
		L.pb(id);
	};
	auto Add_R=[&](int id)
	{
		int bot=mn_l,top=L.size(),mid;
		while(bot<top)
		{
			mid=top+bot>>1;
			if(cross(pts[L[mid]],pts[id])<0) bot=mid+1;
			else top=mid;
		}
		sum+=L.size()-top;
		R.pb(id);
	};
	auto Del_L=[&](int id)
	{
		int bot=mn_r,top=R.size(),mid;
		while(bot<top)
		{
			mid=top+bot>>1;
			if(cross(pts[R[mid]],pts[id])<0) bot=mid+1;
			else top=mid;
		}
		sum-=top-mn_r;
		mn_l++;
	};
	auto Del_R=[&](int id)
	{
		int bot=mn_l,top=L.size(),mid;
		while(bot<top)
		{
			mid=top+bot>>1;
			if(cross(pts[L[mid]],pts[id])<0) bot=mid+1;
			else top=mid;
		}
		sum-=L.size()-top;
		mn_r++;
	};
	for(int i=0;i<n;i++)
	{
		if(qw(pts[i])==0) Add_L(i);
		else Add_R(i);
		//printf("%lld\n",sum);
	}
	//sum/=2;
	//printf("Solve: %i sum:%lld\n",x,sum);
	for(auto e:evs)
	{
		int id=e.second;
		if(qw(pts[id])==0)
		{
			Del_L(id);
			ans+=(ll)sum*(::n-4);
			Add_R(id);
		}
		else
		{
			Del_R(id);
			ans+=(ll)((ll)(L.size()-mn_l)*(R.size()-mn_r)-sum)*(::n-4);
			Add_L(id);
		}
		//printf("id:%i %lld\n",id,ans);
	}
	/*printf("Solve: %i\n",x);
	vector<pt> pts;
	for(int i=1;i<=n;i++) if(i!=x) pts.pb(a[i]-a[x]);
	sort(pts.begin(),pts.end(),cmp_p);
	for(pt p:pts) printf("(%lld %lld)",p.x,p.y);
	int n=pts.size();
	vector<int> rng(n);
	auto nxt=[&](int x){ return x==n-1?0:x+1;};
	for(int i=0,ptr=0;i<n;i++)
	{
		while(nxt(ptr)!=i && cross(pts[i],pts[nxt(ptr)])>=0) ptr=nxt(ptr);
		rng[i]=ptr;
		printf("%i %i\n",i,rng[i]);
		if(nxt(ptr)==i) return;
	}
	function<int(int,int,int,int)> sec=[&](int l, int r, int a, int b)
	{
		if(r<l) return sec(0,l,a,b)+sec(r,n-1,a,b);
		if(b<a)	return sec(l,r,0,b)+sec(l,r,a,n-1);
		return max(0,min(r,b)-max(l,a)+1);
	};
	ll sum=0;
	int ptr;
	for(int i=0;i<n && qw(pts[i])==0;i++) ptr=i;
	for(int i=0;i<=ptr;i++) sum+=sec(ptr+1,n-1,i,rng[i]);
	//for(int i=ptr+1;i<n;i++) sum+=sec(0,ptr,rng[i]+1,i);
	printf("ptr:%i sum:%lld\n",ptr,sum);
	vector<pair<ldb,int>> evs;
	for(int i=0;i<n;i++)
	{
		ldb ang=atan2(pts[i].y,pts[i].x);
		if(ang<0) ang+=PI;
		evs.pb({ang,i});
	}
	sort(evs.begin(),evs.end());
	pair<int,int> intervals[2]={{0,ptr},{ptr+1,n-1}};
	vector<int> hal(n);
	for(int i=0;i<n;i++) hal[i]=qw(pts[i]),printf("%i ",hal[i]);printf("\n");
	for(auto e:evs)
	{
		int id=e.second;
		if(hal[id]==0)
		{
			sum-=sec(intervals[1].first,intervals[1].second,id,rng[id]);
			printf("%i ",sec(intervals[1].first,intervals[1].second,id,rng[id]));
			assert(intervals[0].first==id);
			intervals[0].first=nxt(intervals[0].first);
			intervals[1].second=nxt(intervals[1].second);
			assert(intervals[1].second==id);
			ans+=(ll)sum*(::n-4);
			//printf("%lld %i %lld\n",sum,::n-4,(ll)sum*(::n-4));
			sum+=sec(intervals[0].first,intervals[0].second,nxt(rng[id]),id);
		}
		else
		{
			sum-=sec(intervals[0].first,intervals[0].second,nxt(rng[id]),id);
			printf("%i ",sec(intervals[0].first,intervals[0].second,nxt(rng[id]),id));
			assert(intervals[1].first==id);
			intervals[1].first=nxt(intervals[1].first);
			intervals[0].second=nxt(intervals[0].second);
			assert(intervals[0].second==id);
			ans+=(ll)sum*(::n-4);
			sum+=sec(intervals[1].first,intervals[1].second,id,rng[id]);
		}
		hal[id]^=1;
		printf("id:%i %lld %lld\n",id,ans,sum);
	}*/
}
int main()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%i %i",&x,&y);
		a[i]=pt(x,y);
	}
	for(int i=1;i<=n;i++) Solve(i);
	//for(int i=1;i<=n;i++) a[i].x*=-1,a[i].y*=-1;
	//for(int i=1;i<=n;i++) Solve(i);
	//assert(ans%6==0);
	ans/=6;
	printf("%lld\n",ans);
	return 0;
}