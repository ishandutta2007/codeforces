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
const int N=3005;
struct Line{
	int a,b,c;
	bool operator <(const Line &x)const{
		return 1ll*a*x.b<1ll*x.a*b;
	}
}l[N];
int n;
double ans;
void calc(Line x,Line y,double &px,double &py){
	py=-1.0*(x.c*y.b-y.c*x.b)/(x.a*y.b-y.a*x.b);
	px=-1.0*(x.c*y.a-y.c*x.a)/(x.b*y.a-x.a*y.b);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d%d",&l[i].a,&l[i].b,&l[i].c);
		if (l[i].a<0||(l[i].a==0&&l[i].b<0))
			l[i].a*=-1,l[i].b*=-1,l[i].c*=-1;
	}
	sort(l+1,l+n+1);
	For(i,1,n){
		double px=0,py=0,sx=0,sy=0;
		for (int j=i%n+1;j!=i;j=j%n+1){
			calc(l[i],l[j],px,py);
			//cout<<px<<' '<<py<<endl;
			ans+=sx*py-sy*px;
			sx+=px; sy+=py;
		}
	}
	printf("%.10lf\n",ans/2/(1ll*n*(n-1)*(n-2)/6));
} 
/*
4
1 0 0
0 1 0
1 1 2
-1 1 -1
*/