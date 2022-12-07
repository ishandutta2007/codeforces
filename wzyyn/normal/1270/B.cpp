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
const int N=200005;
int n,a[N],q1[N],q2[N];
pii v1[N],v2[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int t1=0,t2=0;
	v1[0]=v2[0]=pii(-(1<<30),1<<30);
	For(i,1,n){
		for (;t1&&a[q1[t1]]>a[i];--t1);
		for (;t2&&a[q2[t2]]<a[i];--t2);
		q1[++t1]=q2[++t2]=i;
		//printf("%d %d\n",t1,t2);
		v1[t1]=max(v1[t1-1],pii(-a[i]+(i-1),i));
		v2[t2]=max(v2[t2-1],pii( a[i]+(i-1),i));
		//printf("%d %d\n",v1[t1].fi,v2[t2].fi);
		if (v1[t1].fi-i+a[i]>=0){
			printf("YES\n");
			printf("%d %d\n",v1[t1].se,i);
			return;
		}
		if (v2[t2].fi-i-a[i]>=0){
			printf("YES\n");
			printf("%d %d\n",v2[t2].se,i);
			return;
		}
		
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}