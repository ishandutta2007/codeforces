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
const int N=1005;
int n,a[N],p[N];
char ans[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) a[p[i]]=i;
	For(i,1,n) For(j,1,n) ans[i][j]='.';
	int flg=0;
	For(i,1,n) flg|=(a[i]!=i);
	printf("%d\n",n-flg);
	For(T,1,n){
		int pl=-1,pr=-1;
		For(i,1,n) if (a[i]!=i) pr=i; 
		Rep(i,n,1) if (a[i]!=i) pl=i;
		if (pl==pr){}
		else if (a[pl]==-1){
			ans[T][pr]=ans[T][a[pr]]=ans[T][pl]='/';
			a[pl]=a[a[pr]]; a[a[pr]]=a[pr]; a[pr]=-1;
		}
		else{
			ans[T][pl]=ans[T][a[pl]]=ans[T][pr]='\\';
			a[pr]=a[a[pl]]; a[a[pl]]=a[pl]; a[pl]=-1;
		}
		printf("%s\n",ans[T]+1);
	}
}