#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define mp make_pair
bool debug=0;
const ldb eps=1e-9;
struct pt{ ldb x,y;pt(){}pt(ldb a, ldb b):x(a),y(b){}};
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator * (pt a, ldb b){ return pt(a.x*b,a.y*b);}
pt operator / (pt a, ldb b){ return pt((ldb)a.x/b,(ldb)a.y/b);}
bool operator < (pt a, pt b){ return a.y<b.y || (a.y==b.y && a.x<b.x);}
ldb cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
ldb dot(pt a, pt b){ return a.x*b.x+a.y*b.y;}
ldb sq(pt a){ return dot(a,a);}
ldb abs(pt a){ return sqrt(sq(a));}
struct line{ pt p;ldb c;line(pt a, pt b):p(a-b),c(cross(p,a)){}};
ll sgn(ldb x){ return abs(x)==0?0:x>0?1:-1;}
ldb side(line l, pt a){ return l.c-cross(l.p,a);}
ll sside(line l, pt a){ return sgn(side(l,a));}
pt sec(line a, line b){ return pt(-(b.c*a.p.x-a.c*b.p.x),a.c*b.p.y-b.c*a.p.y)/cross(a.p,b.p);}
int Part(pt cen, pt b){ return b.y>cen.y || (b.y==cen.y && b.x>cen.x);}
const int N=20050;
const ldb PI=acos(-1);
pt hull[N];
ldb sum[N];
set<pair<pt,int> > st;
ldb Solve(ldb mid, pt cen, int n)
{
	pt fcen=pt(cen.x,cen.y);
	pt gcen=fcen+pt(cos(mid),sin(mid));
	line ln=line(fcen,gcen);
	int add=0;
	if(side(ln,hull[1])<=eps) add=1;
	int lo=2,hi=n,mi,r=1,l=1;
	while(lo<=hi)
	{
		mi=lo+hi>>1;
		if(cross(hull[1]-hull[mi],cen-hull[mi])>=0) r=mi,lo=mi+1;
		else hi=mi-1;
	}
	int p1=n;
	lo=l,hi=r;
	ll mul=sside(ln,hull[l]);
	while(lo<=hi)
	{
		mi=lo+hi>>1;
		if(sside(ln,hull[mi])==mul) p1=mi,lo=mi+1;
		else hi=mi-1;
	}
	int p2=r;
	lo=r+1,hi=n;
	mul=sside(ln,hull[r+1]);
	while(lo<=hi)
	{
		mi=lo+hi>>1;
		if(sside(ln,hull[mi])==mul) p2=mi,lo=mi+1;
		else hi=mi-1;
	}
	if(sside(ln,hull[r+1])==sside(ln,hull[l])) p2=r;
	if(sside(ln,hull[l])==0) p1=l,p2=r;
	if(p1>p2) swap(p1,p2);
	ldb Area1=0,Area2=0;
	line l1=line(hull[p1],hull[p1+1]),l2=line(hull[p2],hull[p2+1]);
	pt sec1=sec(ln,l1),sec2=sec(ln,l2);
	if(debug)
	{
		cout<<"l1:("<<l1.p.x<<" "<<l1.p.y<<" "<<l1.c<<"\n";
		cout<<"l2:("<<l2.p.x<<" "<<l2.p.y<<" "<<l2.c<<"\n";
		cout<<"ln:("<<ln.p.x<<" "<<ln.p.y<<" "<<ln.c<<"\n";
	}
	Area1=sum[p2-1]-sum[p1]+cross(sec1,hull[p1+1])+cross(hull[p2],sec2)+cross(sec2,sec1);
	Area2=sum[p1+n-1]-sum[p2]+cross(sec2,hull[p2+1])+cross(hull[p1+n],sec1)+cross(sec1,sec2);
	Area1=abs(Area1);
	Area2=abs(Area2);
	if(debug) cout<<"mid:"<<mid<<" p1:"<<p1<<" p2:"<<p2<<"\n"<<"("<<sec1.x<<" "<<sec1.y<<") ("<<sec2.x<<" "<<sec2.y<<")\n";
	if(debug) cout<<"Area1:"<<Area1<<" Area2:"<<Area2<<"\n";
	if(debug) cout<<"l:"<<l<<" r:"<<r<<"\n";
	//int id=st.lower_bound(mp(cen,0))->second;
	int id=rand()%n+1;
	while(abs(side(ln,hull[id]))<eps) id=rand()%n+1;
	if((side(ln,hull[id])<0 && id>p1 && id<=p2) || (side(ln,hull[id])>0 && !(id>p1 && id<=p2))) swap(Area1,Area2);
	return Area1-Area2;
}
int main()
{
	srand(time(0));
	int n,q,i,x,y;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i %i",&x,&y),hull[i]=pt(x,y),hull[i+n]=hull[i],st.insert(mp(hull[i],i));
	hull[n*2+1]=hull[1];
	for(i=1;i<=n*2;i++) sum[i]=sum[i-1]+cross(hull[i],hull[i+1]);
	cout<<fixed<<setprecision(12);
	while(q--)
	{
		pt cen;
		scanf("%i %i",&x,&y);
		cen=pt(x,y);
		ldb top=PI,bot=0,mid;
		bool mod=0;
		if(Solve(0,cen,n)<0) mod=1;
		for(int work=0;work<40;work++)
		{
			mid=(top+bot)/2;
			ldb f=Solve(mid,cen,n);
			if((!mod && f<0) || (mod && f>0)) top=mid;
			else bot=mid;
			//cout<<"solve:"<<f<<" bot:"<<bot<<" top:"<<top<<"\n";
		}
		cout<<min((top+bot)/2,PI-1e-10)<<"\n";
		//debug=1;
		//cout<<"dif:"<<Solve((top+bot)/2,cen,n)<<"\n";
		debug=0;
		//if(q==1) cout<<"Sol:"<<Solve(1.27933953226473580000,cen,n)<<"\n";
		//cout<<"nula:"<<Solve(0,cen,n)<<" pi:"<<Solve(PI,cen,n)<<"\n";
	}
	return 0;
}