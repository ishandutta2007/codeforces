#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define double long double
using namespace std;
const double eps=1e-9;
const int N=25005;
struct P{
	double x,y;
	P(){}
	P(double _x,double _y){
		x=_x; y=_y;
	}
	void init(){
		int _x,_y;
		scanf("%d%d",&_x,&_y);
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	P operator *(const double &a)const{
		return P(a*x,a*y);
	}
	double operator *(const P &a)const{
		return x*a.y-y*a.x;
	}
}p[N],d[N],a[N],b[N];
int n;
double T;
pair<double,int> op[N*2];
double Insertion(int id){
	//cerr<<id<<' '<<a[id].x<<' '<<b[id].x<<' '<<T<<endl;
	//assert(a[id].x-eps<T&&T<b[id].x+eps);
	return ((b[id].x-T)*a[id].y+(T-a[id].x)*b[id].y)/(b[id].x-a[id].x);
}
struct CMPER{
	bool operator ()(const int &x,const int &y){
		double v1=Insertion(x);
		double v2=Insertion(y);
		if (fabs(v1-v2)<eps) return x<y;
		return v1<v2;
	}
};
set<int,CMPER> S;
bool Online(int x,P y){
	return fabs((y-a[x])*(b[x]-a[x]))<eps;
}
bool OnSeg(int x,P y){
	//assert(fabs((y-a[x])*(b[x]-a[x]))<1e-5);
	return a[x].x-eps<y.x&&y.x<b[x].x+eps;
}
bool Insert(int x,int y){
	//cout<<x<<' '<<y<<endl;
	if (Online(x,a[y])&&Online(x,b[y]))
		return OnSeg(x,a[y])||OnSeg(x,b[y])||OnSeg(y,a[x])||OnSeg(y,b[x]);
	double arr=(b[x]-a[x])*(b[y]-a[y]);
	if (fabs(arr)<eps) return 0;
	double ar1=(b[x]-a[x])*(a[y]-a[x]);
	double ar2=(b[x]-a[x])*(b[y]-a[x]);
	P res=(b[y]*ar1-a[y]*ar2)*(1/(ar1-ar2));
	//printf("%d %d %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n",x,y,ar1,ar2,res.x,res.y,(res-a[x])*(b[x]-a[x]),(res-a[y])*(b[y]-a[y]));
	return OnSeg(x,res)&&OnSeg(y,res);
}
bool check(double v){
	//cout<<v<<' '<<setprecision(10)<<S.size()<<endl;
	For(i,1,n){
		a[i]=p[i];
		b[i]=a[i]+d[i]*v;
		if (a[i].x>b[i].x) swap(a[i],b[i]);
		//cout<<a[i].x<<' '<<a[i].y<<' '<<b[i].x<<' '<<b[i].y<<' '<<d[i].x<<' '<<d[i].y<<' '<<p[i].x<<' '<<p[i].y<<endl;
	}
	int top=0;
	For(i,1,n){
		op[++top]=make_pair(a[i].x,-i);
		op[++top]=make_pair(b[i].x,i);
	}
	sort(op+1,op+top+1);
	S.clear();
	//cout<<S.size()<<endl;
	For(i,1,top){
		//cerr<<i<<' '<<setprecision(10)<<op[i].fi<<' '<<op[i].se<<endl;
		T=op[i].fi;
		int id=abs(op[i].se);
		if (op[i].se>0){
			//cerr<<i<<' '<<op[i].fi<<' '<<op[i].se<<endl;
			S.erase(id);
			//cerr<<i<<' '<<op[i].fi<<' '<<op[i].se<<endl;
			auto pre=S.lower_bound(id),nxt=pre,tmp=pre;
			//cout<<"DEBUG= "<<(pre==S.begin()?-1:*(--tmp))<<' '<<(nxt==S.end()?-1:*nxt)<<endl;
			if (pre==S.begin()||nxt==S.end()) continue;
			if (Insert(*(--pre),*nxt)) return 1;
		}
		else{
			auto pre=S.lower_bound(id),nxt=pre,tmp=pre;
			//cout<<"DEBUG= "<<(pre==S.begin()?-1:*(--tmp))<<' '<<(nxt==S.end()?-1:*nxt)<<endl;
			if (pre!=S.begin())
				if (Insert(*(--pre),id)) return 1;
			if (nxt!=S.end())
				if (Insert(id,*nxt)) return 1;
			S.insert(id);
		}
	}
	return 0;
}
int main(){
#ifdef zyy
	freopen("1.in","r",stdin);
#endif
	scanf("%d",&n);
	For(i,1,n){
		p[i].init();
		d[i].init();
		int v;
		scanf("%d",&v);
		double dis=sqrt(d[i].x*d[i].x+d[i].y*d[i].y);
		d[i]=d[i]*(v/dis);
	}
	double l=0,r=1e11;
	For(T,1,63){
		double mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (l>1e11-1000*eps) printf("No show :(");
	else cout<<setprecision(20)<<(l+r)/2<<endl;
}