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
int n,x,q[5],a[N],c[N];
bool check(int x){
	For(i,1,n) c[i]=0;
	For(i,1,x) ++c[a[i]];
	For(i,1,x) if (c[i]!=1) return 0;
	For(i,1,n) c[i]=0;
	For(i,x+1,n) ++c[a[i]];
	For(i,1,n-x) if (c[i]!=1) return 0;
	return 1;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) c[i]=0;
	For(i,1,n) scanf("%d",&a[i]),++c[a[i]];
	for (x=1;c[x]==2;x++); --x;
	//cout<<x<<endl;
	*q=0;
	if (check(x)) q[++*q]=x;
	if (x!=n-x&&check(n-x)) q[++*q]=n-x;
	printf("%d\n",*q);
	For(i,1,*q) cout<<q[i]<<' '<<n-q[i]<<endl;
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}