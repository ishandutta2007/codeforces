#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int sign(double k){
	if (k>eps) return 1; else if (k<-eps) return -1; return 0;
}
int cmp(double k1,double k2){return sign(k1-k2);}
//k3[k1,k2] 
int inmid(double k1,double k2,double k3){return sign(k1-k3)*sign(k2-k3)<=0;}
struct point{
	double x,y;
	point operator + (point k1){return (point){k1.x+x,k1.y+y};}
	point operator - (point k1){return (point){x-k1.x,y-k1.y};}
	point operator * (double k1){return (point){x*k1,y*k1};}
	point operator / (double k1){return (point){x/k1,y/k1};}
	// 
    point turn(double k1){return (point){x*cos(k1)-y*sin(k1),x*sin(k1)+y*cos(k1)};}
    point turn90(){return (point){-y,x};}
	bool operator < (point k1){
		int a=cmp(x,k1.x);
		if (a==-1) return 1; else if (a==1) return 0; else return cmp(y,k1.y)==-1;
	}
	double abs(){return sqrt(x*x+y*y);}
	double abs2(){return x*x+y*y;}
	double dis(point k1){return ((*this)-k1).abs();}
	point unit(){double w=abs(); return (point){x/w,y/w};}
	void scan(){scanf("%lf%lf",&x,&y);}
	void print(){printf("%.11lf %.11lf\n",x,y);}
	double getw(){return atan2(y,x);} 
	point getdel(){if (sign(x)==-1||(sign(x)==0&&sign(y)==-1)) return (*this)*(-1); else return (*this);}
};
int inmid(point k1,point k2,point k3){
	return inmid(k1.x,k2.x,k3.x)&&inmid(k1.y,k2.y,k3.y);
}
double cross(point k1,point k2){
	return k1.x*k2.y-k1.y*k2.x;
}
double dot(point k1,point k2){
	return k1.x*k2.x+k1.y*k2.y;
}
double rad(point k1,point k2){
	return atan2(cross(k1,k2),dot(k1,k2));
}
point proj(point k1,point k2,point q){
	//qk1,k2 
	point k=k2-k1;
	return k1+k*(dot(q-k1,k)/k.abs2());
}
point reflect(point k1,point k2,point q){
	return proj(k1,k2,q)*2-q;
}
int clockwise(point k1,point k2,point k3){
	//k1 k2 k3  1  -1  0  
	return sign(cross(k2-k1,k3-k1));
}
//(L)(S)k1,k2k3,k4 
int checkLL(point k1,point k2,point k3,point k4){
	return cmp(cross(k3-k1,k4-k1),cross(k3-k2,k4-k2))!=0;
}
point getLL(point k1,point k2,point k3,point k4){
	double w1=cross(k1-k3,k4-k3),w2=cross(k4-k3,k2-k3);
	return (k1*w2+k2*w1)/(w1+w2);
}
int intersect(double l1,double r1,double l2,double r2){
	if (l1>r1) swap(l1,r1); if (l2>r2) swap(l2,r2);
	return cmp(r1,l2)!=-1&&cmp(r2,l1)!=-1;
}
int checkSS(point k1,point k2,point k3,point k4){
	return intersect(k1.x,k2.x,k3.x,k4.x)&&intersect(k1.y,k2.y,k3.y,k4.y)&&
	sign(cross(k3-k1,k4-k1))*sign(cross(k3-k2,k4-k2))<=0&&
	sign(cross(k1-k3,k2-k3))*sign(cross(k1-k4,k2-k4))<=0;
}
double disSP(point k1,point k2,point q){
	point k3=proj(k1,k2,q);
	if (inmid(k1,k2,k3)) return q.dis(k3); else return min(q.dis(k1),q.dis(k2));
}
double disSS(point k1,point k2,point k3,point k4){
	if (checkSS(k1,k2,k3,k4)) return 0;
	else return min(min(disSP(k1,k2,k3),disSP(k1,k2,k4)),min(disSP(k3,k4,k1),disSP(k3,k4,k2)));
}
int onS(point k1,point k2,point q){
	return inmid(k1,k2,q)&&sign(cross(k1-q,k2-k1))==0;
}
//x 
double closepoint(vector<point>&A,int l,int r){
	if (r-l<=5){
		double ans=1e20;
		for (int i=l;i<=r;i++) for (int j=i+1;j<=r;j++) ans=min(ans,A[i].dis(A[j]));
		return ans;
	}
	int mid=l+r>>1; double ans=min(closepoint(A,l,mid),closepoint(A,mid+1,r));
	vector<point>B; for (int i=l;i<=r;i++) if (abs(A[i].x-A[mid].x)<=ans) B.push_back(A[i]);
	sort(B.begin(),B.end(),[](point k1,point k2){return k1.y<k2.y;});
	for (int i=0;i<B.size();i++) for (int j=i+1;j<B.size()&&B[j].y-B[i].y<ans;j++) ans=min(ans,B[i].dis(B[j]));
	return ans;
}
// vector<point>  
double area(vector<point> A){
	double ans=0;
	for (int i=0;i<A.size();i++) ans+=cross(A[i],A[(i+1)%A.size()]);
	return ans/2;
}
int checkconvex(vector<point>A){
	int n=A.size(); A.push_back(A[0]); A.push_back(A[1]);
	for (int i=0;i<n;i++) if (sign(cross(A[i+1]-A[i],A[i+2]-A[i]))==-1) return 0;
	return 1;
}
int contain(vector<point>A,point q){
	//2  1  0 
	A.push_back(A[0]); int pd=0;
	for (int i=1;i<A.size();i++){
		point u=A[i-1],v=A[i];
		if (onS(u,v,q)) return 1;
		if (cmp(u.y,v.y)>0) swap(u,v);
		if (cmp(u.y,q.y)>=0||cmp(v.y,q.y)<0) continue;
		if (sign(cross(u-v,q-v))<0) pd^=1;
	}
	return pd<<1;
}
vector<point> ConvexHull(vector<point>A,int flag=1){
	//flag=0  flag=1  
	int n=A.size(); vector<point>ans(n*2); 
	sort(A.begin(),A.end()); int now=-1;
	for (int i=0;i<A.size();i++){
		while (now>0&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag) now--;
		ans[++now]=A[i];
	}
	int pre=now;
	for (int i=n-2;i>=0;i--){
		while (now>pre&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<flag) now--;
		ans[++now]=A[i];
	}
	ans.resize(now); return ans;
}
double convexDiameter(vector<point>A){
	int now=0,n=A.size(); double ans=0;
	for (int i=0;i<A.size();i++){
		now=max(now,i);
		while (1){
			double k1=A[i].dis(A[now%n]),k2=A[i].dis(A[(now+1)%n]);
			ans=max(ans,max(k1,k2)); 
			if (k2>k1) now++; else break;
		}
	}
	return ans;
}
vector<point> convexcut(vector<point>A,point k1,point k2){
	// k1,k2,p 
	int n=A.size(); A.push_back(A[0]); vector<point>ans;
	for (int i=0;i<n;i++){
		int w1=clockwise(k1,k2,A[i]),w2=clockwise(k1,k2,A[i+1]);
		if (w1>=0) ans.push_back(A[i]);
		if (w1*w2<0) ans.push_back(getLL(k1,k2,A[i],A[i+1]));
	}
	return ans;
}
struct circle{
	point o;
	double r;
	void scan(){o.scan(); scanf("%lf",&r);}
	int inside(point k){return cmp(r,o.dis(k));}
};
int checkposCC(circle k1,circle k2){
	//
	if (cmp(k1.r,k2.r)==-1) swap(k1,k2);
	double dis=k1.o.dis(k2.o);  int w1=cmp(dis,k1.r+k2.r),w2=cmp(dis,k1.r-k2.r);
	if (w1>0) return 4; else if (w1==0) return 3; else if (w2>0) return 2; 
	else if (w2==0) return 1; else return 0;
}
vector<point> getCL(circle k1,point k2,point k3){
	//k2->k3 
	point k=proj(k2,k3,k1.o); double d=k1.r*k1.r-(k-k1.o).abs2();
	if (sign(d)==-1) return {};
	point del=(k3-k2).unit()*sqrt(max(0.0,d));
	return {k-del,k+del};
}
vector<point> getCC(circle k1,circle k2){
	//k1 
	int pd=checkposCC(k1,k2);
	if (pd==0||pd==4) return {};
	double a=(k2.o-k1.o).abs2(),cosA=(k1.r*k1.r+a-k2.r*k2.r)/(2*k1.r*sqrt(max(a,0.0)));
	double b=k1.r*cosA,c=sqrt(max(0.0,k1.r*k1.r-b*b));
	point k=(k2.o-k1.o).unit(),m=k1.o+k*b,del=k.turn90()*c;
	return {m-del,m+del};
} 
vector<point> TangentCP(circle k1,point k2){
	//k1 
	double a=(k2-k1.o).abs(),b=k1.r*k1.r/a,c=sqrt(max(0.0,k1.r*k1.r-b*b));
	point k=(k2-k1.o).unit(),m=k1.o+k*b,del=k.turn90()*c;
	return {m-del,m+del};
} 
struct line{
	//p[0]->p[1]
	point p[2];
	line(point k1,point k2){p[0]=k1; p[1]=k2;}
	line(){}
	point& operator [] (int k){return p[k];}
    line push(){ //eps 
        const double eps = 1e-6;
        point delta=(p[1]-p[0]).turn90().unit()*eps;
        return {p[0]-delta,p[1]-delta};
    }
};
int clockwise(line k1,point k2){
	return clockwise(k1[0],k1[1],k2);
}
vector<line> TangentoutCC(circle k1,circle k2){
	int pd=checkposCC(k1,k2); if (pd==0) return {}; 
	if (pd==1){point k=getCC(k1,k2)[0]; return {(line){k,k}};}
	if (cmp(k1.r,k2.r)==0){
		point del=(k2.o-k1.o).unit().turn90().getdel();
		return {(line){k1.o-del*k1.r,k2.o-del*k2.r},(line){k1.o+del*k1.r,k2.o+del*k2.r}};
	} else {
		point p=(k2.o*k1.r-k1.o*k2.r)/(k1.r-k2.r);
		vector<point>A=TangentCP(k1,p),B=TangentCP(k2,p);
		vector<line>ans; for (int i=0;i<A.size();i++) ans.push_back((line){A[i],B[i]}); 
		return ans;
	}
}
vector<line> TangentinCC(circle k1,circle k2){
	int pd=checkposCC(k1,k2); if (pd<=2) return {};
	if (pd==3){point k=getCC(k1,k2)[0]; return {(line){k,k}};} 
	point p=(k2.o*k1.r+k1.o*k2.r)/(k1.r+k2.r);
	vector<point>A=TangentCP(k1,p),B=TangentCP(k2,p);
	vector<line>ans; for (int i=0;i<A.size();i++) ans.push_back((line){A[i],B[i]}); 
	return ans;
}
vector<line> TangentCC(circle k1,circle k2){
	int flag=0; if (k1.r<k2.r) swap(k1,k2),flag=1;
	vector<line>A=TangentoutCC(k1,k2),B=TangentinCC(k1,k2);
	for (line k:B) A.push_back(k); 
	if (flag) for (line &k:A) swap(k[0],k[1]);
	return A;
}
double getarea(circle k1,point k2,point k3){
	//k1k2 k3 k1.o
	int pd1=k1.inside(k2),pd2=k1.inside(k3); 
	vector<point>A=getCL(k1,k2,k3); 
	if (pd1>=0){
		if (pd2>=0) return cross(k2-k1.o,k3-k1.o)/2;
		return k1.r*k1.r*rad(A[1],k3)/2+cross(k2-k1.o,A[1]-k1.o)/2;
	} else if (pd2>=0){
		return k1.r*k1.r*rad(k2,A[0])/2+cross(A[0]-k1.o,k3-k1.o)/2;
	}else {
		int pd=cmp(k1.r,disSP(k2,k3,k1.o));
		if (pd<=0) return k1.r*k1.r*rad(k2,k3)/2;
		return cross(A[0]-k1.o,A[1]-k1.o)/2+k1.r*k1.r*(rad(k2,A[0])+rad(A[1],k3))/2;
	}
}
int n,K; 
int main(){
	scanf("%d%d",&n,&K);
	int num=K*n/180;
	if (abs(num*180.0/n-K)>abs((num+1)*180.0/n-K)) num++;
	num=min(n-2,max(num,1));
	printf("%d %d %d\n",2,1,num+2);
}