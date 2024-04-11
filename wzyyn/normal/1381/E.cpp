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
using namespace std;
const int N=100005;
int n,Q,x[N],y[N];
int q1[N],q2[N],q[N];
int top;
double dif[N];
struct node{
	int id;
	double T,a,b,c;
	bool operator <(const node &aa)const{
		if (fabs(T-aa.T)<1e-9)
			return id<aa.id;
		return T<aa.T;
	}
}op[N*15];
double func(int r,int l,int p){
	assert(y[l]<=p&&p<=y[r]);
	return (1.0*(y[r]-p)*x[l]+1.0*(p-y[l])*x[r])/(y[r]-y[l]);
}
void Insert_opp(int l,int r,double p1,double p2,int rp){
	if (p1>p2) swap(p1,p2);
	if (fabs(p1-p2)>1e-9){
		double a=(r-l)/(p2-p1);
		op[++top]=(node){0,p1,0.5*a*rp,-1*a*p1*rp,0.5*a*p1*p1*rp};
		op[++top]=(node){0,p2,-0.5*a*rp,1*a*p1*rp,-0.5*a*p1*p1*rp};
	}
	double ar=(p2-p1)*(r-l)*0.5;
	op[++top]=(node){0,p2,0,(r-l)*rp,(ar-(r-l)*p2)*rp};
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	int p=1;
	for (;y[p]>y[p%n+1];p=p%n+1);
	for (;y[p]<y[p%n+1];p=p%n+1);
	for (;y[p]>y[p%n+1];p=p%n+1) q1[++*q1]=p;
	for (;y[p]<y[p%n+1];p=p%n+1) q2[++*q2]=p%n+1;
	reverse(q1+1,q1+*q1+1);
	For(i,1,n) q[i]=y[i]; *q=n;
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	assert(*q1+*q2==n);
	double l1,r1,m1;
	l1=r1=m1=x[q1[1]%n+1];
	int p1=1,p2=1;
	double arr=0;
	For(i,2,*q){
		for (;y[q1[p1]]<q[i];++p1);
		for (;y[q2[p2]]<q[i];++p2);
		double l2=func(q1[p1],q1[p1]%n+1,q[i]);
		double r2=func(q2[p2],(q2[p2]+n-2)%n+1,q[i]);
		if (l2>r2) swap(l2,r2);
		double m2=(l2+r2)/2;
		arr+=(q[i]-q[i-1])*((r1-l1)+(r2-l2))/2;
		Insert_opp(q[i-1],q[i],l1,l2,-1);
		Insert_opp(q[i-1],q[i],m1,m2,2);
		Insert_opp(q[i-1],q[i],r1,r2,-1);
		l1=l2; r1=r2; m1=m2;
	}
	For(i,1,Q){
		int x;
		scanf("%d",&x);
		op[++top]=(node){i,x,0,0,0};
	}
	sort(op+1,op+top+1);
	double a=0,b=0,c=0;
	For(i,1,top)
		if (op[i].id){
			//cout<<a<<' '<<b<<' '<<c<<' '<<op[i].id<<endl;
			dif[op[i].id]=a*op[i].T*op[i].T+b*op[i].T+c;
		}
		else{
			a+=op[i].a;
			b+=op[i].b;
			c+=op[i].c;
			//cout<<a<<' '<<b<<' '<<c<<' '<<op[i].T<<endl;
		}
	For(i,1,Q)
		printf("%.15lf\n",arr+dif[i]);
}