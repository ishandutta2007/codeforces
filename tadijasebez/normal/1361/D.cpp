#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
struct pt{
	ll x,y;
	pt(){}
	pt(ll a,ll b):x(a),y(b){}
};
int part(pt a){return (a.y>0||a.y==0&&a.x>0)?0:1;}
ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ldb abs(pt a){return sqrt(a.x*a.x+a.y*a.y);}
bool operator < (pt a,pt b){return mp(part(a),(ll)0)<mp(part(b),cross(a,b));}
vector<pt> pts;
//vector<deque<ldb>> groups;
vector<vector<ldb>> groups;
vector<int> take,hi,ptl,ptr;
vector<ldb> lo;
int n,k;
ldb calc(int g){
	//assert(groups[g].size()>0);
	int ost=k-take[g]-1;
	int L=take[g]-hi[g];
	int R=hi[g];
	int bal=ost+L-R;
	ldb sum=-lo[g]*2;
	if(bal<0)return sum+bal*groups[g][ptl[g]];
	else return sum+bal*groups[g][ptr[g]];
}
void rem(int g){
	//assert(groups[g].size()>0);
	int ost=k-take[g]-1;
	int L=take[g]-hi[g];
	int R=hi[g];
	int bal=ost+L-R;
	if(bal<0){
		take[g]++;
		lo[g]+=groups[g][ptl[g]];
		ptl[g]++;
		//groups[g].pop_front();
	}else{
		take[g]++;
		hi[g]++;
		groups[g][ptr[g]];
		ptr[g]--;
	}
}
int main(){
	rd(n,k);
	for(int i=1;i<=n;i++){
		int x,y;rd(x,y);
		if(x!=0||y!=0)pts.pb(pt(x,y));
	}
	sort(pts.begin(),pts.end());
	//deque<ldb> tmp;tmp.push_back(0);
	//groups.pb(tmp);take.pb(0);lo.pb(0);hi.pb(0);
	groups.pb({0});take.pb(0);lo.pb(0);hi.pb(0);ptl.pb(0);ptr.pb(0);
	for(int i=0,j;i<pts.size();i=j){
		vector<ldb> dst;
		for(j=i;j<pts.size()&&!(pts[j]<pts[i])&&!(pts[i]<pts[j]);j++)dst.pb(abs(pts[j]));
		sort(dst.begin(),dst.end());
		//deque<ldb> dq;for(auto i:dst)dq.push_back(i);
		//groups.pb(dq);
		groups.pb(dst);
		take.pb(0);
		lo.pb(0);
		hi.pb(0);
		ptl.pb(0);
		ptr.pb(dst.size()-1);
		//for(auto i:dst)printf("%.6f ",i);printf("\n");
	}
	ldb ans=0;
	int work=1;
	for(int i=0;i<groups.size();i++){
		if(n-(ptr[i]-ptl[i]+1)<k){
			while(n-(ptr[i]-ptl[i]+1)<k){
				ans+=calc(i);
				rem(i);
				work++;
			}
		}
	}
	priority_queue<pair<ldb,int>> pq;
	for(int i=0;i<groups.size();i++){
		if((ptr[i]-ptl[i]+1))pq.push({calc(i),i});
	}
	for(int i=work;i<=k;i++){
		ans+=pq.top().first;
		int idx=pq.top().second;
		pq.pop();
		rem(idx);
		//printf("%i %.12f\n",idx,ans);
		if((ptr[idx]-ptl[idx]+1)){
			pq.push({calc(idx),idx});
		}
	}
	printf("%.12f\n",ans);
	return 0;
}