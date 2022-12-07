#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=150005;
int n,id[N];
int posl[N],posr[N];
pii a[N];
ll T[N];
bool cnm(const pii &a,const pii &b){
	return 1ll*a.fi*b.se==1ll*a.se*b.fi;
}
bool rnm(const pii &a,const pii &b){
	return 1ll*a.fi*b.se>1ll*a.se*b.fi;
}
bool cmp(int x,int y){
	return a[x].fi<a[y].fi;
}
bool check(double c){
	int l=1;
	double pmx=0;
	For(i,1,n){
		if (a[id[i]].fi!=a[id[i-1]].fi&&i!=1)
			for (;l<i;l++){
				int x=id[l];
				ll clk=T[posl[x]-1]+a[x].se;
				//printf("%d %lld %d %d\n",x,clk,a[x].fi,a[x].se);
				pmx=max(pmx,1.0*a[x].fi*(1-c*clk/T[n]));
			}
		int x=id[i];
		ll clk=T[posr[x]];
		//printf("%d %lld %.10lf\n",x,clk,pmx);
		if (1.0*a[x].fi*(1-c*clk/T[n])<pmx)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i].fi);
	For(i,1,n) scanf("%d",&a[i].se);
	sort(a+1,a+n+1,rnm);
	For(i,1,n) T[i]=T[i-1]+a[i].se;
	//For(i,1,n) printf("%d %d\n",a[i].fi,a[i].se);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int l=1;
	For(i,2,n+1)
		if (i==n+1||!cnm(a[i],a[i-1])){
			For(j,l,i-1) posl[j]=l;
			For(j,l,i-1) posr[j]=i-1;
			l=i;
		}
	double L=0,R=1;
	For(T,1,50){
		double mid=(L+R)/2;
		if (check(mid)) L=mid;
		else R=mid;
	}
	printf("%.15lf\n",(L+R)/2);
}
/*
a.v/a.T<b.v/b.T
b.v*a.T

0.28 1
0.21 1
0.7  8

0.2  1
0.15 1
0.5  8
*/