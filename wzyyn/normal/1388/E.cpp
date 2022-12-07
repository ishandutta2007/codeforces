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

const int N=2005;
int n,L[N],R[N],y[N],top;
pair<double,double> op[N*N/2];
struct P{
	double x,y;
	P(){}
	P(double _x,double _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
};
struct Hull{
	P q[N];
	int top,pos;
	bool cmp(P x,P y,P z){
		y=y-x; z=z-x;
		return -y.y/y.x>=-z.y/z.x;
	}
	void build(){
		For(i,1,n) q[i]=P(y[i],R[i]);
		For(i,1,n) For(j,i+1,n)
			if (q[i].x>q[j].x||(q[i].x==q[j].x&&q[i].y>q[j].y))
				swap(q[i],q[j]);
		top=1;
		For(i,2,n){
			for (;top&&q[i].x==q[top].x&&q[i].y>q[top].y;--top);
			for (;top>=2&&cmp(q[top-1],q[top],q[i]);--top);
			q[++top]=q[i];
		}
		/*printf("%d\n",top);
		For(i,1,top){
			printf("%.10lf %.10lf\n",q[i].x,q[i].y);
		}*/
		pos=1;
	}
	double F(P x,double y){
		return x.x*y+x.y;
	}
	double query(double v){
		int l=1,r=top-1,p=0;
		while (l<=r){
			int mid=(l+r)/2;
			if (F(q[mid],v)<F(q[mid+1],v))
				p=mid,l=mid+1;
			else r=mid-1;
		}
		if (p==0) return F(q[1],v);
		return max(F(q[p],v),F(q[p+1],v));
	}
}T[2];
double ans;
void UPD(double i){
	//printf("%.10lf %.10lf %.10lf\n",i,T[0].query(i),T[1].query(-i)); 
	ans=min(ans,T[0].query(i)+T[1].query(-i));
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d%d",&L[i],&R[i],&y[i]);
	For(i,1,n) For(j,1,n)
		if (y[i]>y[j]){
			double vl=-(R[i]-L[j])*1.0/(y[i]-y[j]);
			double vr=-(L[i]-R[j])*1.0/(y[i]-y[j]);
			//cout<<vl<<' '<<vr<<endl;
			assert(vl<vr);
			//if (i==3&&j==9) cout<<vl<<' '<<vr<<endl;
			op[++top]=make_pair(vl,vr);
		}
	T[0].build();
	For(i,1,n){
		swap(L[i],R[i]);
		L[i]*=-1; R[i]*=-1;
	}
	T[1].build();
	double le=-1e9;
	ans=1e18;
	sort(op+1,op+top+1);
	For(i,1,top){
		if (op[i].fi>le-1e-9){
			//cout<<op[i].fi<<' '<<le<<endl;
			UPD(le),UPD(op[i].fi);
		}
		le=max(le,op[i].se);
	}
	UPD(le);
	printf("%.10lf\n",ans);
}