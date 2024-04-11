#include <bits/stdc++.h>
using namespace std;
#define ldb double
#define pt pair<ldb,ldb>
#define x first
#define y second
#define seg pair<pt,pt>
#define pb push_back

pt operator - (pt a,pt b){return {a.x-b.x,a.y-b.y};}
pt operator + (pt a,pt b){return {a.x+b.x,a.y+b.y};}
pt operator * (pt a,ldb b){return {a.x*b,a.y*b};}
pt operator / (pt a,ldb b){return {a.x/b,a.y/b};}
ldb cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ldb dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
int part(pt a){
	if(a.y>0||(a.y==0&&a.x>0))return 0;
	return 1;
}

pt rot(pt a,ldb ang){
	return {a.x*cos(ang)-a.y*sin(ang),a.x*sin(ang)+a.y*cos(ang)};
}

struct line{
	pt v;ldb c;
	line(pt a,pt b):v(b-a),c(cross(v,a)){}
	line(seg a):line(a.first,a.second){}
	pt sec(line b){
		return (b.v*c-v*b.c)/cross(v,b.v);
	}
	ldb dot(pt a){return ::dot(v,a);}
};

const int N=50050;
const ldb eps_ang=1e-5;
pt ray;
seg s[N];
pt sec(pt ray,seg a){
	return line(pt(0,0),ray).sec(line(a));
}
ldb abs(pt a){return sqrt(a.x*a.x+a.y*a.y);}
pt p[N];
struct cmp{
	bool operator ()(seg a,seg b) const {
		return abs(sec(ray,a))<abs(sec(ray,b));
	}
};
set<seg,cmp> all;
bool in[N];
void PRINT(){
	for(auto it:all){
		printf("(%.0f %.0f) (%.0f %.0f)\n",it.first.x,it.first.y,it.second.x,it.second.y);
	}
}
int main(){
	int n,m=0;
	scanf("%i",&n);
	while(n--){
		int k;
		scanf("%i",&k);
		for(int i=0;i<k;i++){
			scanf("%lf %lf",&p[i].x,&p[i].y);
		}
		for(int i=0;i<k;i++){
			s[++m]={p[i],p[(i+1)%k]};
		}
	}
	vector<pair<pt,int>> evs;
	for(int i=1;i<=m;i++)if(cross(s[i].first,s[i].second)!=0){
		evs.pb({s[i].first,i});
		evs.pb({s[i].second,i});
	}
	auto evcmp=[&](pair<pt,int> a,pair<pt,int> b){
		if(part(a.first)!=part(b.first))return part(a.first)<part(b.first);
		return cross(a.first,b.first)>0;
	};
	sort(evs.begin(),evs.end(),evcmp);
	ray=rot({1,0},-eps_ang);
	pt last={1,0};
	for(int i=1;i<=m;i++)if(cross(s[i].first,s[i].second)!=0){
		pt A=s[i].first;
		pt B=s[i].second;
		if(part(A)!=part(B)){
			if(part(A)==0)swap(A,B);
			if(cross(A,B)>0){
				all.insert(s[i]);
				in[i]=true;
			}
		}

		/*pt tmp=sec(ray,s[i]);
		line ln(s[i]);
		ldb L=ln.dot(s[i].first);
		ldb R=ln.dot(s[i].second);
		if(L>R)swap(L,R);
		ldb X=ln.dot(tmp);
		if(L<X&&X<R){
			all.insert(s[i]);
			in[i]=true;
		}*/
	}
	ldb ans=0;
	for(int i=0,j;i<evs.size();i=j){
		vector<int> add,del;
		for(j=i;j<evs.size()&&!evcmp(evs[i],evs[j]);j++){
			if(in[evs[j].second])del.pb(evs[j].second);
			else add.pb(evs[j].second);
		}
		ray=rot(evs[i].first,-eps_ang);
		//printf("Ray: (%.0f %.0f)\n",evs[i].first.x,evs[i].first.y);
		//PRINT();
		if(all.size()>=2){
			ans-=abs(cross(sec(last,*all.begin()),sec(evs[i].first,*all.begin())))/2;
			ans+=abs(cross(sec(last,*next(all.begin())),sec(evs[i].first,*next(all.begin()))))/2;
		}
		for(int z:del){
			all.erase(s[z]);
			in[z]=false;
		}
		ray=rot(evs[i].first,eps_ang);
		for(int z:add){
			all.insert(s[z]);
			in[z]=true;
		}
		last=evs[i].first;
	}
	if(all.size()>=2){
		ans-=abs(cross(sec(last,*all.begin()),sec({1,0},*all.begin())))/2;
		ans+=abs(cross(sec(last,*next(all.begin())),sec({1,0},*next(all.begin()))))/2;
	}
	printf("%.12f\n",ans);
	return 0;
}