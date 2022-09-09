#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

struct pt{
	ll x,y;
	pt(){}
	pt(ll a,ll b):x(a),y(b){}
};

pt operator - (pt a,pt b){return pt(a.x-b.x,a.y-b.y);}
pt operator -= (pt&a,pt b){return a=a-b;}
pt operator + (pt a,pt b){return pt(a.x+b.x,a.y+b.y);}
pt operator += (pt&a,pt b){return a=a+b;}
pt operator - (pt a){return pt(-a.x,-a.y);}
pt operator * (pt a,ll b){return pt(a.x*b,a.y*b);}

ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
int part(pt a){
	if(a.x>0||a.x==0&&a.y<0)return 0;
	else return 1;
}

bool operator < (pt a,pt b){
	if(part(a)!=part(b))return part(a)<part(b);
	return cross(a,b)>0;
}

vector<pt> dir;
vector<pt> poly;
pt lwp(0,0);

const int N=100050;
int fx[N],fy[N],a[N],fid[N];
pt f[N];
int px[N],py[N],t[N];
ll ans[N];
pt p[N];
vector<ll> cpr;

struct BIT{
	ll sum[N];
	void init(){for(int i=0;i<N;i++)sum[i]=0;}
	BIT(){init();}
	void add(int i,ll f){for(;i<N;i+=i&-i)sum[i]+=f;}
	ll get(int i){ll ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
	ll get(int l,int r){return get(r)-get(l-1);}
}BT;

bool cmp(ll a,ll b,bool dw){
	if(dw)return a<b;
	else return a<=b;
}

int main(){
	int k,n,q;
	scanf("%i %i %i",&k,&n,&q);
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%i %i",&x,&y);
		pt d(x,y);
		if(part(d)==1)d=-d;
		lwp-=d;
		dir.pb(d*2);
		dir.pb(-d*2);
	}
	sort(dir.begin(),dir.end());
	poly.pb(lwp);
	for(pt d:dir){
		poly.pb(poly.back()+d);
	}
	poly.pop_back();
	//for(pt p:poly){
	//	printf("(%lld, %lld)\n",p.x,p.y);
	//}
	for(int i=1;i<=n;i++){
		scanf("%i %i %i",&fx[i],&fy[i],&a[i]);
		f[i]=pt(fx[i],fy[i]);
		cpr.pb(fx[i]);
	}
	sort(cpr.begin(),cpr.end());
	cpr.erase(unique(cpr.begin(),cpr.end()),cpr.end());
	for(int i=1;i<=n;i++){
		fid[i]=lower_bound(cpr.begin(),cpr.end(),fx[i])-cpr.begin()+1;
	}
	for(int i=1;i<=q;i++){
		scanf("%i %i %i",&px[i],&py[i],&t[i]);
		p[i]=pt(px[i],py[i]);
	}
	bool first=true;
	for(int e=0;e<poly.size();e++){
		pt dir=poly[(e+1)%poly.size()]-poly[e];
		bool dw=dir.x>0;
		if(part(dir)==1)dir=-dir;
		if(dir.x==0){
			continue;
		}
		vector<pair<ll,int>> evs;
		for(int i=1;i<=n;i++){
			evs.pb({cross(dir,f[i]),i});
		}
		sort(evs.begin(),evs.end());
		vector<pair<ll,int>> qs;
		for(int i=1;i<=q;i++){
			pt h=poly[e]*t[i]+p[i];
			qs.pb({cross(dir,h),i});
		}
		sort(qs.begin(),qs.end());
		BT.init();
		int j=0;
		for(int i=0;i<qs.size();i++){
			int qi=qs[i].second;
			while(j<evs.size()&&cmp(evs[j].first,qs[i].first,dw)){
				int ei=evs[j].second;
				BT.add(fid[ei],a[ei]);
				j++;
			}
			pt lp=poly[e]*t[qi]+p[qi];
			pt rp=poly[(e+1)%poly.size()]*t[qi]+p[qi];
			ll L=min(lp.x,rp.x);
			ll R=max(lp.x,rp.x);
			int l=upper_bound(cpr.begin(),cpr.end(),L)-cpr.begin()+1;
			if(first||e+1==poly.size()){
				l=lower_bound(cpr.begin(),cpr.end(),L)-cpr.begin()+1;
			}
			int r=upper_bound(cpr.begin(),cpr.end(),R)-cpr.begin();
			if(lp.x>rp.x)ans[qi]+=BT.get(l,r);
			else ans[qi]-=BT.get(l,r);
		}
		first=false;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}