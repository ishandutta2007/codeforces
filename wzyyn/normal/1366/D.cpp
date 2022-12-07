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
const int N=10000005;
int n,fl[N],too[N],a[N/2];
void init(){
	For(i,2,N-1) if (!fl[i])
		For(j,1,(N-1)/i) fl[i*j]=i;
	For(i,2,N-1){
		too[i]=i;
		for (;too[i]%fl[i]==0;too[i]/=fl[i]);
	}
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n)
		if (a[i]==1||too[a[i]]==1) printf("-1 ");
		else printf("%d ",too[a[i]]);
	puts("");
	For(i,1,n)
		if (a[i]==1||too[a[i]]==1) printf("-1 ");
		else printf("%d ",a[i]/too[a[i]]);
	puts("");
}