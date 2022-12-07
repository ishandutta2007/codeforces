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
const int N=2005;
int la[N],id[N],cnt[N];
int n,e[N][N];
struct node{
	int x,y,id;
	bool operator <(const node &a)const{
		return y<a.y;
	}
}a[N];
bool check(int mid){
	int p=1,pp=0;
	For(i,1,n) la[i]=n;
	For(i,1,n){
		id[i]=a[p].id; la[p]=i;
		For(j,1,n) if (e[p][j]) la[j]=min(la[j],i+mid);
		For(j,1,n) cnt[j]=0;
		For(j,1,n) cnt[la[j]]++;
		For(j,1,n) cnt[j]+=cnt[j-1];
		For(j,1,n) if (cnt[j]>j) return 0;
		for (pp=i+1;cnt[pp]<pp;++pp);
		Rep(j,n,1) if (i<la[j]&&la[j]<=pp) p=j;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	For(i,1,n) For(j,i+1,n)
		if (a[j].x<=a[i].y)
			e[i][j]=e[j][i]=1;
	int l=1,r=n,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	check(ans);
	For(i,1,n) printf("%d ",id[i]);
}