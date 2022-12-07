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
int n,m,a[N],l[N],at[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d",&a[i]);
	Rep(i,m,1) l[i]=max(l[i+1]+1,a[i]);
	if (l[1]>n) return puts("-1"),0;
	int p=0;
	For(i,1,m){
		at[i]=min(p+1,n-l[i]+1);
		p=max(p,at[i]+a[i]-1);
	}
	if (p<n) return puts("-1"),0;
	For(i,1,m) printf("%d ",at[i]); puts("");
}