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
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (n%2==1){
		puts("YES");
		printf("%d\n",n-1);
		for (int i=2;i<=n;i+=2) printf("1 %d %d\n",i,i+1);
		for (int i=2;i<=n;i+=2) printf("1 %d %d\n",i,i+1);
	}
	else{
		int S=0;
		For(i,1,n) S^=a[i];
		if (S) return puts("NO"),void(0);
		puts("YES");
		printf("%d\n",n-2);
		for (int i=3;i<=n;i+=2) printf("2 %d %d\n",i,i+1);
		for (int i=3;i<=n;i+=2) printf("2 %d %d\n",i,i+1);
	}
}
int main(){
	solve();
}