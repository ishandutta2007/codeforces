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
const int N=1000005;
int n,a[N];
int op[N],vis[N],chr[N];
int main(){
	scanf("%d",&n);
	if (n%2==0){
		printf("First\n");
		For(i,1,n) printf("%d ",i);
		For(i,1,n) printf("%d ",i);
	}
	else{
		printf("Second\n");
		fflush(stdout);
		For(i,1,2*n) scanf("%d",&a[i]);
		For(i,1,2*n) op[a[i]]^=i;
		For(i,0,n-1) if (!vis[i]){
			int x=(i?i:n),y=op[a[x]]^x;
			vis[x%n]=1; chr[a[x]]=x;
			for (;!vis[y%n];){
				x=(y>n?y-n:y+n);
				y=op[a[x]]^x;
				vis[x%n]=1;
				chr[a[x]]=x;
			}
		}
		ll sum=0;
		For(i,1,n) sum+=chr[i];
		if (sum%(2*n)) For(i,1,n) chr[i]^=op[i];
		For(i,1,n) printf("%d ",chr[i]);
	}
}