#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int n,m,a[N];
int l[N],r[N];
int l2[N],r2[N];
char s[N];
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	For(i,1,n) a[i]=a[i-1]+(s[i]=='+'?1:-1);
	For(i,1,n){
		l[i]=min(l[i-1],a[i]);
		r[i]=max(r[i-1],a[i]);
	}
	l2[n+1]=r2[n+1]=a[n];
	Rep(i,n,1){
		l2[i]=min(l2[i+1],a[i]);
		r2[i]=max(r2[i+1],a[i]);
	}
	while (m--){
		int x,y;
		scanf("%d%d",&x,&y);
		int vl=l[x-1],vr=r[x-1];
		if (y!=n){
			vl=min(vl,l2[y+1]-a[y]+a[x-1]);
			vr=max(vr,r2[y+1]-a[y]+a[x-1]);
		}
		printf("%d\n",vr-vl+1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}