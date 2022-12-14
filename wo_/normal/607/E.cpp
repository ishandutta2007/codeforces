#include<cstdio>
#include<cmath>
#include<complex>
#include<vector>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;

struct BIT{
	int N;
	int dat[100100];
	void init(int N_){
		N=N_;
		for(int i=1;i<=N;i++) dat[i]=0;
	}
	void add(int i,int x){
		while(i<=N){
			dat[i]+=x;
			i+=(i&(-i));
		}
	}
	int get(int i){
		int res=0;
		while(i>0){
			res+=dat[i];
			i-=(i&(-i));
		}
		return res;
	}
	int get(int l,int r){//[l,r)
		return get(r-1)-get(l-1);
	}
};

BIT bit;

typedef double Real;
typedef complex<Real> Point;
typedef complex<Real> Vector;
typedef pair<Point,Point> Line;
typedef pair<Point,Point> Segment;

typedef pair<Real,int> P;

const Real eps=1e-9;
const Real PI=acos(-1);
const Real inf=1e100;

const Point NPoint=Point(NAN,NAN);

template<class T> bool eq_(T a,T b){
	return abs(a-b)<eps;
}

template<class T> bool lt_(T a,T b){
	if(eq_(a,b)) return false;
	return a<b;
}

template<class T> bool le_(T a,T b){
	if(eq_(a,b)) return true;
	return a<b;
}

Real normalize(Real x){
	while(x>PI) x-=PI*2;
	while(x<-PI) x+=PI*2;
	return x;
}

struct Circle:vector<P>{
	Point c;
	Real r;
	Circle(){}
	Circle(Point c_,Real r_){
		c=c_;
		r=r_;
	}
	Point getPoint(Real ang){
		return c+r*Point(cos(ang),sin(ang));
	}
};

Real doP(Vector a,Vector b){
	return (conj(a)*b).real();
}

Real crP(Vector a,Vector b){
	return (conj(a)*b).imag();
}

Vector proj(Vector p,Vector b){
	return b*doP(p,b)/norm(b);
}

Point perp(Line l,Point a){
	Point p=l.first,q=l.second;
	return p+proj(a-p,q-p);
}

Vector toVec(Line l){
	return l.second-l.first;
}

bool isPara_(Line l1,Line l2){
	return eq_((Real)0,crP(toVec(l1),toVec(l2)));
}

void iCL(Circle &c,Line l,int id){
	Point h=perp(l,c.c);
	Real d=abs(h-c.c);
	if(le_(c.r,d)) return;//reject tangent
	if(eq_(d,(Real)0)){
		Point p=l.first;
		if(eq_(p,c.c)) p=l.second;
		Real ang=arg(p-c.c);
		c.push_back(P(normalize(ang),id));
		c.push_back(P(normalize(ang+PI),id));
	}else{
		Real ang=arg(h-c.c);
		Real ang2=acos(d/(c.r));
		c.push_back(P(normalize(ang+ang2),id));
		c.push_back(P(normalize(ang-ang2),id));
	}
}

Point iLL(Line la,Line lb){
	if(isPara_(la,lb)) return NPoint;
	Point a1=la.first,a2=la.second;
	Point b1=lb.first,b2=lb.second;
	Real num=crP(b1-a1,a2-a1);
	Real den=crP(a2-a1,b2-b1);
	return b1+(b2-b1)*(num/den);
}

Line ls[50500];
int N;
Point qpoint;
int M;

Circle c;

int prv[50500];

long long countIntersections(Circle &vec){
	bit.init(vec.size());
	sort(vec.begin(),vec.end());
	for(int i=0;i<N;i++) prv[i]=-1;
	long long res=0;
	for(int i=0;i<vec.size();i++){
		int id=vec[i].second;
		if(prv[id]==-1){
			prv[id]=i;
			bit.add(i+1,1);
		}else{
			int l=prv[id];
			int r=i;
			l++;r++;
			bit.add(l,-1);
			res+=bit.get(l,r);
		}
	}
	return res;
}

bool check(Real d,bool debug=false){
	c=Circle(qpoint,d);
	for(int i=0;i<N;i++){
		iCL(c,ls[i],i);
	}
	long long cnt=countIntersections(c);
	if(debug){
		for(int i=0;i<c.size();i++){
			printf("%f\n",c[i].first/PI*2);
		}
		printf("%d\n",(int)cnt);
	}
	return cnt>=M;
}

Real calc_dis(Point o,Circle &c,Real ang11,Real ang12,Real ang21,Real ang22){
	Point p1=c.getPoint(ang11);
	Point p2=c.getPoint(ang12);
	Point q1=c.getPoint(ang21);
	Point q2=c.getPoint(ang22);
	Line lp=Line(p1,p2);
	Line lq=Line(q1,q2);
	Point p=iLL(lp,lq);
	if(isnan(p.real())) return inf;
	return abs(o-p);
}

Real as[100100],bs[100100];

Real f(int i1,int i2){
	Real a1=as[i1],b1=bs[i1];
	Real a2=as[i2],b2=bs[i2];
//	printf("%f %f %f %f\n",a1,b1,a2,b2);
//	printf("(%f %f) (%f %f) (%f %f) (%f %f)\n",ls[i1].first.real(),ls[i1].first.imag(),ls[i1].second.real(),ls[i1].second.imag(),
//	ls[i2].first.real(),ls[i2].first.imag(),ls[i2].second.real(),ls[i2].second.imag());
	if(eq_(a1,a2)) return inf;
	Real x=(b2-b1)/(a1-a2);
	Real y=x*a1+b1;
//	printf("(%f %f) ",x,y);
	Point p=iLL(ls[i1],ls[i2]);
//	printf("(%f %f)\n",p.real(),p.imag());
	Real dx=x-qpoint.real();
	Real dy=y-qpoint.imag();
	return sqrt(dx*dx+dy*dy);
}

const int inf_int=1e9;

struct Solver{
Real diss[30300300];
int diss_id;
bool exi[100100];
Real ang_sm[100100];
Real ang_la[100100];
int prv[100100],nxt[100100];
P ps[100100];
int sm_id[100100];

Real getSum(Real d, int M){
	if(eq_(d,(Real)0)) return 0;
	c=Circle(qpoint, d);
	for(int i=0;i<N;i++){
		iCL(c,ls[i],i);
	}
	sort(c.begin(),c.end());
	long long num=countIntersections(c);
	if(num>M){
		return getSum(d-eps,M);
	}
	for(int i=0;i<N*2;i++){
		prv[i]=i-1,nxt[i]=i+1;
		exi[i]=false;
	}
	for(int i=0;i<N;i++){
		ang_sm[i]=inf;
		ang_la[i]=-inf;
	}
	diss_id=0;
	for(int i=0;i<c.size();i++){
		int id=c[i].second;
		Real ang=c[i].first;
		ang_sm[id]=min(ang_sm[id],ang);
		ang_la[id]=max(ang_la[id],ang);
	}
	Real res=0;
	int cnt=0;
	for(int i=0;i<c.size();i++){
		Real ang=c[i].first;
		int id=c[i].second;
		if(!exi[id]){
			//ins (ang, id)
			exi[id]=true;
			ps[i]=c[i];
			sm_id[id]=i;
		}else{
			Real ang11=ang;
			Real ang12=ang_sm[id];
			int j;
			int to_del=-1;
			for(j=prv[i];j!=-1;j=prv[j]){
				Real ang21=ps[j].first;
				int id2=ps[j].second;
			/*	if(id2==id){
					to_del=j;
					break;
				}*/
				if(le_(ang21,ang12)) break;
				Real ang22=ang_la[id2];
	//			Real d_=calc_dis(qpoint,c,ang11,ang12,ang21,ang22);
				Real d=f(id,id2);
	//			printf("%f %f\n",d_,d);
	//			diss[diss_id++]=d;
				res+=d;
				cnt++;
			}
			//del j
			j=sm_id[id];
			int p=prv[j];
			int n=nxt[j];
			if(p!=-1) nxt[p]=n;
			prv[n]=p;
			//del i
			p=prv[i];
			n=nxt[i];
			if(p!=-1) nxt[p]=n;
			prv[n]=p;
		}
	}
	/*sort(diss,diss+diss_id);
	for(int i=0;i<M;i++){
		res+=diss[i];
	}*/
	res+=d*(M-cnt);
	return res;
}
} calc_sum;

/*
Real getSum(Real d,int M){
	c=Circle(qpoint,d);
	for(int i=0;i<N;i++){
		iCL(c,ls[i],i);
	}
	sort(c.begin(),c.end());
	for(int i=0;i<N;i++) ang_la[i]=-10;
	for(int i=0;i<c.size();i++){
		ang_la[c[i].second]=c[i].first;
	}
	set<P> se;
	for(int i=0;i<c.size();i++){
		Real ang=c[i].first;
		int id=c[i].second;
		if(!exi[id]){
			exi[id]=true;
			ang_sm[id]=ang;
			se.insert(c[i]);
		}else{
			multiset<P>::reverse_iterator it=se.rbegin();
			for(;it!=se.rend();it++){
				Real another_ang=it->first;
				int another_id=it->second;
				if(lt_(another_ang,ang_sm[id])) break;
				Real cur_dis=calc_dis(c.c,c,ang,ang_sm[id],ang_la[another_id],another_ang);
				diss[diss_id++]=cur_dis;
			}
		}
	}
	sort(diss,diss+diss_id);
	Real res=0;
	for(int i=0;i<M;i++){
		res+=diss[i];
	}
	return res;
}*/

void input(){
	scanf("%d",&N);
	int x,y;
	scanf("%d%d%d",&x,&y,&M);
	qpoint=Point((Real)x/1000,(Real)y/1000);
	for(int i=0;i<N;i++){
		int a_,b_;
		scanf("%d%d",&a_,&b_);
		Real a=(Real)a_/1000;
		Real b=(Real)b_/1000;
		as[i]=a,bs[i]=b;
		if(a_!=0){
			Point p1=Point(0,b);
			Point p2=Point(1,a+b);
			ls[i]=Line(p1,p2);
		}else{
			Point p1=Point(0,b);
			Point p2=Point(1,b);
			ls[i]=Line(p1,p2);
		}
	}
}

int main(){
	input();
	Real lb=0,ub=1e10;
	for(int stage=0;stage<70;stage++){
		Real mid=(ub+lb)/2;
		bool flg=check(mid);
		if(flg) ub=mid;
		else lb=mid;
	}
	Real ans=calc_sum.getSum(ub,M);
	printf("%.9f\n",(double)ans);
	return 0;
}