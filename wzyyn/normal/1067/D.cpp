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
#define pdd pair<double,double>
const int N=100005;
struct mat{
	double a[3][3];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator *(const mat &b)const{
		mat ans;
		For(i,0,2) For(j,0,2) For(k,0,2)
			ans.a[i][j]+=a[i][k]*b.a[k][j];
		return ans;
	}
};
struct node{
	int id;
	ll las;
	mat pre;
};
mat tr[N],f[40],ord;
node q[N];
int n;
ll T;
double B;
pdd p[N];
int main(){
	scanf("%d%lld",&n,&T);
	For(i,1,n){
		double x,y,v;
		scanf("%lf%lf%lf",&x,&y,&v);
		B=max(B,y*v);
		p[i]=pdd(x*v,v);
	}
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	ord.a[2][0]=1;
	For(i,1,n){
		tr[i].a[2][2]=1;
		tr[i].a[1][1]=1;
		tr[i].a[1][2]=B;
		tr[i].a[0][0]=1-p[i].se;
		tr[i].a[0][1]=p[i].se;
		tr[i].a[0][2]=p[i].fi;
	}
	int t=0;
	q[++t]=(node){1,T,ord};
	For(i,2,n){
		for (;t&&(tr[i]*q[t].pre).a[0][0]>
		         (tr[q[t].id]*q[t].pre).a[0][0];--t);
		if (!q[t].las) continue;
		node tmp=q[t];
		f[0]=tr[tmp.id];
		For(j,1,35) f[j]=f[j-1]*f[j-1];
		Rep(j,35,0)
			if (tmp.las>(1ll<<j))
				if ((tr[i]*f[j]*tmp.pre).a[0][0]<=
					(tr[tmp.id]*f[j]*tmp.pre).a[0][0]){
						tmp.pre=f[j]*tmp.pre;
						tmp.las-=(1ll<<j);
					}
		tmp.pre=f[0]*tmp.pre; --tmp.las;
		if (tmp.las) tmp.id=i;
		q[++t]=tmp;
	}
	mat s=q[t].pre;
	mat x=tr[q[t].id];
	ll y=q[t].las;
	for (;y;y/=2,x=x*x)
		if (y&1) s=x*s;
	printf("%.10lf\n",s.a[0][0]);
}