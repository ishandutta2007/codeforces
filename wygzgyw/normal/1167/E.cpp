#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e6)+10;
const int INF=(1e9);
int n,x,mx[maxn],mn[maxn];
struct node {
	int val,pos;
} d[maxn];
bool cmp(node a,node b) {
	if (a.val==b.val) return a.pos<b.pos;
	return a.val<b.val;
}
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(x); int l,r,mid,res;
	for (int i=1;i<=n;i++) read(d[i].val),d[i].pos=i;
	sort(d+1,d+n+1,cmp);
	int Mx=0,Mn=INF,t1=x,t2=1;
	for (int i=1;i<=n;i++) {
		if (d[i].pos<Mx) { t1=d[i].val-1; break; }
		Mx=d[i].pos;
		mx[d[i].val]=Mx;
	}
	for (int i=1;i<=t1;i++)
		if (!mx[i]) mx[i]=mx[i-1];
	for (int i=n;i>=1;i--) {
		if (d[i].pos>Mn) { t2=d[i].val+1; break; }
		Mn=d[i].pos;
		mn[d[i].val]=Mn;
	} mn[x+1]=INF;
	for (int i=x;i>=t2;i--)
		if (!mn[i]) mn[i]=mn[i+1];
	//for (int i=1;i<=x;i++)
		//printf("%d %d\n",mn[i],mx[i]);
	int lst=t2;
	for (int i=0;i<=t1;i++) {
		lst=max(lst,i+2);
		l=lst,r=x+1; res=0;
		while (l<=r) {
			mid=(l+r)/2;
			//printf("%d %d %d %d\n",l,r,mid,res);
			if (mn[mid]>mx[i]) res=mid,r=mid-1;
			else l=mid+1;
		}
		//printf("%d %d\n",i,res);
		if (!res) continue;
		ans+=x-res+2;
		lst=res;
	}
	printf("%lld\n",ans);
	return 0;
}