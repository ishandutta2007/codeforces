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
int n,Q,a[500005];
ll S;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,0,(1<<n)-1) scanf("%d",&a[i]),S+=a[i];
	printf("%.10lf\n",1.0*S/(1<<n));
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		S+=y-a[x]; a[x]=y;
		printf("%.10lf\n",1.0*S/(1<<n));
	}
}