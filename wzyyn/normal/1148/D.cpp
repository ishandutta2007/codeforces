#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
struct node{
	int x,y,id;
	bool operator <(const node &a)const{
		return y>a.y;
	}
}a[N],b[N];
int n,cnt,ans[N];
void solve(){
	int tot=0;
	For(i,1,n) if (a[i].y>a[i].x) b[++tot]=a[i];
	if (!tot) return;
	sort(b+1,b+tot+1);
	int l=1,le=b[1].x;
	For(i,2,tot+1)
		if (i==tot+1||b[i].y<le){
			if (i-l>cnt){
				cnt=i-l;
				For(j,l,i-1)
					ans[j-l+1]=b[j].id;
			}
			l=i;
			le=b[i].x;
		}
		else
			le=min(le,b[i].x);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	solve();
	For(i,1,n){
		a[i].x=2*n+1-a[i].x;
		a[i].y=2*n+1-a[i].y;
	}
	solve();
	printf("%d\n",cnt);
	For(i,1,cnt) printf("%d ",ans[i]);
}