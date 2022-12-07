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
char ans[N][N];
int n,m,S;
pii a[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) a[i].se=i;
	For(i,n-m+1,n) scanf("%d",&a[i].fi);
	For(i,n-m+1,n) S+=a[i].fi;
	if (S>n*(n-1)) return puts("no"),0;
	S=n*(n-1)-S;
	For(i,1,n-m) a[i].fi=S/(n-m)+(i<=S%(n-m));
	reverse(a+1,a+n-m+1);
	reverse(a+n-m+1,a+n+1); 
	For(i,1,n-1)
		if (a[i].fi>a[i+1].fi)
			return puts("no"),0;
	S=0;
	For(i,1,n){
		S+=a[i].fi;
		if (S<i*(i-1))
			return puts("no"),0;
	}
	For(i,1,n) ans[i][i]='X';
	Rep(i,n,1){
		sort(a+1,a+i+1);
		int rem=a[i].fi;
		For(j,1,i-1)
			if (rem>1){
				ans[a[i].se][a[j].se]='W';
				ans[a[j].se][a[i].se]='L';
				rem-=2;
			}
			else if (rem==1){
				ans[a[i].se][a[j].se]='D';
				ans[a[j].se][a[i].se]='D';
				rem-=1; a[j].fi-=1;
			}
			else{
				ans[a[i].se][a[j].se]='L';
				ans[a[j].se][a[i].se]='W';
				a[j].fi-=2;
			}
	}
	puts("yes");
	For(i,1,n) printf("%s\n",ans[i]+1);
}