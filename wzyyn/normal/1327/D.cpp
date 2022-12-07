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
const int N=200005;
int q[N],a[N],c[N],vis[N],n,ans;
void F(int x){
	*q=0;
	for (int y=x;;){
		q[++*q]=y; vis[y]=1;
		if ((y=a[y])==x) break;
	}
	//cout<<x<<' '<<*q<<endl;
	For(i,1,*q)
		if ((*q)%i==0)
			For(j,1,i){
				bool flg=0;
				for (int k=j;k<=*q;k+=i)
					if (c[q[k]]!=c[q[j]]) flg=1;
				if (!flg) ans=min(ans,i);
			}
}
void solve(){
	ans=1<<30;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&c[i]);
	For(i,1,n) vis[i]=0;
	For(i,1,n) if (!vis[i]) F(i);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}