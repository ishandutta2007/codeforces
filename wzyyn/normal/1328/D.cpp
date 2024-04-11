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
int n,a[200005];
bool jud1(){
	bool flg=0;
	For(i,1,n) if (a[i]!=a[i%n+1]) flg=1;
	if (flg) return 0;
	printf("1\n");
	For(i,1,n) printf("1 ");
	puts("");
	return 1;
}
bool jud2(){
	int p=0,flg=0;
	For(i,1,n) if (a[i]==a[i%n+1]) flg=1,p=i+1;
	if (!flg&&(n%2==1)) return 0;
	//cerr<<"INF "<<p<<endl;
	printf("2\n");
	For(i,1,n) printf("%d ",1+(i-p+n)%n%2);
	puts("");
	return 1;
}
void jud3(){
	printf("3\n3 ");
	For(i,1,n-1) printf("%d ",1+(i&1));
	puts("");
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (jud1()) return;
	if (jud2()) return;
	jud3();
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}