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
const int N=300005;
int n,m;
ll T,a[N],x;
pii q[N];
int id[N],rk[N];
bool cmp(int x,int y){
	return q[x]<q[y];
}
int main(){
	scanf("%d%d%lld",&n,&m,&T);
	For(i,1,n){
		char s[5];
		scanf("%d%s",&q[i].fi,s+1);
		q[i].se=('R'==s[1]?1:-1);
		a[i]=q[i].fi+q[i].se*T;
		if (a[i]>0) x+=(a[i]-1)/m;
		else x+=a[i]/m-1;
		//cout<<(a[i]>0?(a[i]-1)/m:(a[i]/m)-1)<<endl;
		a[i]=((a[i]-1)%m+m)%m+1;
		x%=n;
	}
	//cout<<(x+n)%n<<endl;
	//cout<<x<<endl;
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	sort(a+1,a+n+1);
	For(i,1,n) rk[id[i]]=i;
	For(i,1,n) printf("%lld ",a[(rk[i]+x+n-1)%n+1]);
}