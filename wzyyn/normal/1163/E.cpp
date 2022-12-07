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
int n,m,q,ans[N];
int a[N],t[25],b[25];
bool insert(int k,int x){
	Rep(i,k-1,0)
		if (x&(1<<i))
			if (!t[i])
				return t[i]=x,1;
			else x^=t[i];
	return 0;
}
void check(int k){
	memset(t,0,sizeof(t));
	int m=0;
	For(i,1,n) 
		if (a[i]<1<<k)
			if (insert(k,a[i]))
				b[++m]=a[i];
	if (m!=k) return;
	For(i,1,m) ans[1<<(i-1)]=b[i];
	For(i,1,(1<<m)-1) ans[i]=ans[i&(-i)];
	For(i,0,(1<<k)-1) ans[i]^=ans[i-1];
	printf("%d\n",k);
	For(i,0,(1<<k)-1) printf("%d ",ans[i]);
	puts("");
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	Rep(i,18,0) check(i);
}