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
const int N=2000005;
int n,l,t;
ll a[N];
double ans;
int check(ll dx,ll dy){
	ll dis=(dy-dx);
	return t/l+(dy-dx<=t%l);
}
int main(){
	scanf("%d%d%d",&n,&l,&t); t*=2;
	For(i,1,n) scanf("%lld",&a[i]),a[i+n]=a[i]+l;
	//For(i,1,2*n) a[i]=a[i]*2ll;
	int T1=t/l+1,T2=t/l,p=1;
	For(i,1,n){
		for (;check(a[i],a[p])==T1;++p);
		//cout<<p<<' '<<i<<endl;
		ans+=1.0*(n-1)*T2+(p-i-1); 
	}
	printf("%.10lf\n",0.25*ans);
}