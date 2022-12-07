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
#define y1 fdhjksa
using namespace std;
const int N=300005;
int n,a[N],l[N],r[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) l[i]=n+1,r[i]=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		l[x]=min(l[x],i);
		r[x]=max(r[x],i);
	}
	int S=0,l=0,las=0,mx=0;
	For(i,1,n)
		if (r[i]){
			++S;
			if (::l[i]<las) l=0;
			mx=max(mx,++l);
			las=r[i];
		}
	printf("%d\n",S-mx);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}