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

const int N=100005;
int n,a[N],top;
int q[N],vis[N];
pii ans[N];
void insert(int x,int y){
	ans[++top]=(pii(x-2*y,y));
	a[x]^=1; a[x-y]^=1; a[x-y-y]^=1;
}
void check(int n){
	int st=0,h=0,t=1;
	memset(vis,-1,sizeof(vis));
	For(i,1,n) st|=a[i]<<(i-1);
	q[1]=st; vis[st]=0;
	while (h!=t){
		int x=q[++h];
		For(v1,0,n) For(v2,1,n) if (v1+2*v2<n){
			int y=x^(1<<v1)^(1<<(v1+v2))^(1<<(v1+v2+v2));
			if (vis[y]==-1) vis[y]=v1*1000+v2,q[++t]=y;
		}
	}
	if (vis[0]==-1) puts("NO");
	else{
		for (int i=0;i!=st;){
			int x=vis[i]/1000,y=vis[i]%1000;
			ans[++top]=pii(x+1,y);
			i^=(1<<x)^(1<<(x+y))^(1<<(x+y+y));
		}
		printf("YES\n%d\n",top);
		For(i,1,top) printf("%d %d %d\n",ans[i].fi,ans[i].fi+ans[i].se,ans[i].fi+2*ans[i].se);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int m=n;
	for (;;){
		for (;m>15&&a[m]==0;--m);
		if (m<=15) break;
		if (a[m-1]==0&&a[m-2]==0) insert(m,3);
		else if (a[m-1]==0&&a[m-2]==1) insert(m,2);
		else if (a[m-1]==1&&a[m-2]==1) insert(m,1);
		else if (a[m-3]==1&&a[m-4]==1&&a[m-5]==1) insert(m,4),insert(m-1,2);
		else{
			if (a[m-3]) insert(m,3);
			else if (a[m-4]) insert(m,4);
			else if (a[m-5]) insert(m,5);
			else insert(m,6);
			if (a[m-3]) insert(m-1,2);
			else if (a[m-4]) insert(m-1,3);
			else if (a[m-5]) insert(m-1,4);
			else insert(m-1,5);
		}
	}
	check(min(n,15));
}