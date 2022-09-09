#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
 
const int N=100050;
const int M=2*N;
const int L=18;
 
struct vec2{
	ll x,y;
	int idx;
 
	vec2(){}
 
	vec2(ll a,ll b):x(a),y(b){}
 
	vec2 operator - (vec2 other) const {
		return vec2(x-other.x,y-other.y);
	}
};
 
bool cmp(vec2 a,vec2 b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
 
ll cross(vec2 a,vec2 b){return a.x*b.y-a.y*b.x;}
int part(vec2 a){return (a.x>0||(a.x==0&&a.y>0))?0:1;}
 
bool operator < (vec2 a,vec2 b){
	int pa=part(a),pb=part(b);
	if(pa!=pb)return pa<pb;
	return cross(a,b)>0;
}
 
struct DecrementalHull{
	int ls[M],rs[M],tsz,root;
	int ss[M],se[M];
	int ul[M],ur[M];
	int bl[M],br[M];
 
	int n;
	vector<vec2> pts;
 
	DecrementalHull(){}
 
	bool ccw(int i,int j,int k){
		return cross(pts[j]-pts[i],pts[k]-pts[i])>0;
	}
 
	void pull(int c){
		int p=ls[c],q=rs[c];
 
		ll sx=pts[ss[q]].x;
 
		while(ul[p]!=ur[p]||ul[q]!=ur[q]){
			int A=ul[p],B=ur[p];
			int C=ul[q],D=ur[q];
			if(B!=A&&!ccw(C,B,A))p=ls[p];
			else if(C!=D&&!ccw(D,C,B))q=rs[q];
			else if(A==B)q=ls[q];
			else if(C==D)p=rs[p];
			else{
				ll c1=cross(pts[B]-pts[A],pts[C]-pts[A]);
				ll c2=cross(pts[A]-pts[B],pts[D]-pts[B]);
				if(c1+c2==0||c1*pts[D].x+c2*pts[C].x<sx*(c1+c2))p=rs[p];
				else q=ls[q];
			}
		}
		ul[c]=ss[p];
		ur[c]=ss[q];
 
		p=ls[c],q=rs[c];
 
		while(bl[p]!=br[p]||bl[q]!=br[q]){
			int A=bl[p],B=br[p];
			int C=bl[q],D=br[q];
			if(B!=A&&!ccw(A,B,C))p=ls[p];
			else if(C!=D&&!ccw(B,C,D))q=rs[q];
			else if(A==B)q=ls[q];
			else if(C==D)p=rs[p];
			else{
				ll c1=cross(pts[B]-pts[A],pts[C]-pts[A]);
				ll c2=cross(pts[A]-pts[B],pts[D]-pts[B]);
				if(c1+c2==0||c1*pts[D].x+c2*pts[C].x>sx*(c1+c2))p=rs[p];
				else q=ls[q];
			}
		}
		bl[c]=ss[p];
		br[c]=ss[q];
		ss[c]=ss[ls[c]];
		se[c]=se[rs[c]];
	}
 
	void Build(int&c,int l,int r){
		c=++tsz;
		ss[c]=l;
		se[c]=r;
		if(l==r){
			ul[c]=ur[c]=l;
			bl[c]=br[c]=l;
			return;
		}
		int mid=l+r>>1;
		Build(ls[c],l,mid);
		Build(rs[c],mid+1,r);
		pull(c);
	}
 
	void Build(){
		sort(pts.begin(),pts.end(),cmp);
		n=pts.size();
		Build(root,0,n-1);
	}
 
	void Del(int&c,int qi){
		if(ss[c]==se[c])c=0;
		else{
			if(qi<=se[ls[c]])Del(ls[c],qi);
			else Del(rs[c],qi);
			if(!ls[c])c=rs[c];
			else if(!rs[c])c=ls[c];
			else pull(c);
		}
	}
 
	vector<vec2> hull;
	vector<int> top,bot,ids;
	void GetTop(int c,int l,int r){
		if(ul[c]==ur[c]){
			top.pb(ss[c]);
		}else if(ul[c]>=r){
			GetTop(ls[c],l,r);
		}else if(ur[c]<=l){
			GetTop(rs[c],l,r);
		}else{
			GetTop(rs[c],ur[c],r);
			GetTop(ls[c],l,ul[c]);
		}
	}
 
	void GetBot(int c,int l,int r){
		if(bl[c]==br[c]){
			bot.pb(ss[c]);
		}else if(bl[c]>=r){
			GetBot(ls[c],l,r);
		}else if(br[c]<=l){
			GetBot(rs[c],l,r);
		}else{
			GetBot(ls[c],l,bl[c]);
			GetBot(rs[c],br[c],r);
		}
	}
 
	vector<vec2> GetHull(){
		top.clear();
		bot.clear();
		GetTop(root,0,n-1);
		GetBot(root,0,n-1);
		ids.clear();
		for(int i:bot)ids.pb(i);
		for(int i:top)if(ids.back()!=i&&ids.front()!=i)ids.pb(i);
		hull.clear();
		for(int i:ids)hull.pb(pts[i]);
		for(int i:ids)Del(root,i);
		return hull;
	}
}DH;
 
int n,q;
vec2 pts[N];
 
vector<vector<vec2>> layers;
vector<vec2> slopes;
vector<int> pref;
int go[N][L],idx[N];
 
void buildConvexHullLayers(){
	for(int i=1;i<=n;i++)DH.pts.pb(pts[i]);
	DH.Build();
	while(DH.root!=0){
		vector<vec2> layer=DH.GetHull();
		for(int i=0;i<layer.size();i++)idx[layer[i].idx]=i;
		layers.pb(layer);
	}
 
	int sz=layers[0].size();
	for(int i=0;i<sz;i++){
		slopes.push_back(layers[0][(i+1)%sz]-layers[0][i]);
	}
}
 
void buildLayerConnections(){
	for(int i=0;i+1<layers.size();i++){
		vector<vec2> layer=layers[i];
		vector<vec2> nextl=layers[i+1];
		int lsz=layer.size(),ptr=0;
		auto nxt=[&](int x){return x+1==nextl.size()?0:x+1;};
		auto pre=[&](int x){return x==0?nextl.size()-1:x-1;};
		for(int j=0;j<lsz;j++){
			vec2 src=layer[j==0?lsz-1:j-1];
			while(cross(nextl[ptr]-src,nextl[nxt(ptr)]-src)<0)ptr=nxt(ptr);
			while(cross(nextl[ptr]-src,nextl[pre(ptr)]-src)<0)ptr=pre(ptr);
			go[layer[j].idx][0]=nextl[ptr].idx;
		}
	}
 
	for(int j=1;j<L;j++){
		for(int i=1;i<=n;i++){
			go[i][j]=go[go[i][j-1]][j-1];
		}
	}
 
	pref.reserve(layers.size()+1);
	pref.push_back(0);
	for(int i=0;i<layers.size();i++){
		pref.push_back(pref.back()+layers[i].size());
	}
}
 
int getFirst(vec2 dir){
	int idx=lower_bound(slopes.begin(),slopes.end(),dir)-slopes.begin();
	if(idx==slopes.size())idx=0;
	return layers[0][idx].idx;
}
 
int getDestLayer(int k){
	return lower_bound(pref.begin(),pref.end(),k)-pref.begin()-1;
}
 
int walkCCW(int layer,int start,int steps){
	int layer_size=layers[layer].size();
	return layers[layer][(idx[start]+steps)%layer_size].idx;
}
 
int main() {
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&pts[i].x,&pts[i].y);
		pts[i].idx=i;
	}
 
	buildConvexHullLayers();
	buildLayerConnections();
 
	scanf("%i",&q);
	while(q--){
		vec2 dir;
		int k;
		scanf("%lld %lld %i",&dir.x,&dir.y,&k);
		int idx=getFirst(dir);
		int destLayer=getDestLayer(k);
		for(int j=0;j<L;j++)
			if(destLayer>>j&1)
				idx=go[idx][j];
		int ost=k-pref[destLayer];
		int ans=walkCCW(destLayer,idx,ost-1);
		printf("%i\n",ans);
	}
	return 0;
}