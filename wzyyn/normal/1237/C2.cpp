#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
int n;
struct P{
	int x,y,z,id;
	bool operator <(const P &a)const{
		if (x!=a.x) return x<a.x;
		if (y!=a.y) return y<a.y;
		return z<a.z;
	}
}a[50005];
vector<pii> ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id=i;
	sort(a+1,a+n+1);
	int top=0;
	For(i,1,n)
		if (top&&a[i].x==a[top].x&&a[i].y==a[top].y)
			ans.PB(pii(a[i].id,a[top--].id));
		else a[++top]=a[i];
	n=top; top=0;
	For(i,1,n)
		if (top&&a[i].x==a[top].x)
			ans.PB(pii(a[i].id,a[top--].id));
		else a[++top]=a[i];
	n=top; top=0;
	For(i,1,n)
		if (top)
			ans.PB(pii(a[i].id,a[top--].id));
		else a[++top]=a[i];
	For(i,0,ans.size()-1)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}