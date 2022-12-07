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
int w[N],q[N],vis[N];
int n,m,k,fl,qq[N];
bool connect(){
	int h=0,t=1,cnt=0;
	For(i,1,n*m) vis[i]=0;
	For(i,1,n*m) if (w[i]) q[1]=i,++cnt;
	vis[q[1]]=1;
	while (h!=t){
		int x=q[++h];
		if (x+m<=n&&w[x+m]&&!vis[x+m])
			vis[x+m]=1,q[++t]=x+m;
		if (x-m>=1&&w[x-m]&&!vis[x-m])
			vis[x-m]=1,q[++t]=x-m;
		if (x%m!=0&&w[x+1]&&!vis[x+1])
			vis[x+1]=1,q[++t]=x+1;
		if (x%m!=1&&w[x-1]&&!vis[x-1])
			vis[x-1]=1,q[++t]=x-1;
	}
	return cnt==t;
}
int count(){
	int ans=0;
	For(i,1,(n-1)*m) if (i%m){
		ans+=w[i]&w[i+1]&w[i+m];
		ans+=w[i]&w[i+1]&w[i+1+m];
		ans+=w[i]&w[i+m]&w[i+1+m];
		ans+=w[i+1]&w[i+m]&w[i+1+m];
	}
	return ans;
}
int check(int p){
	For(i,1,n*m) w[i]=(i<=p);
	return count();
}
bool work(){
	int c=4*(n-1)*(m-1);
	if (k>c||k==c-1||k==c-2||k==c-4||k==c-5) return 0;
	if (k==c-8&&n!=3&&m!=3) return 0;
	int l=0,r=n*m,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)<=k)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	int cur=count(),top=0;
	if (cur==k) return 1;
	For(i,1,n*m)
		if ((i-1)/m==0||abs((i-1)/m-(ans-1)/m)<=1)
			qq[++top]=i;
	for (;cur^k;){
		int at,x;
		if (cur<k){
			for (;;){
				at=rand()%top+1;
				if (!w[qq[at]]) break; 
			}
			x=qq[at]; w[x]=1;
			if (!connect()){
				w[x]=0; continue;
			}
			cur=count();
		}
		else{
			for (;;){
				at=rand()%top+1;
				if (w[qq[at]]) break; 
			}
			x=qq[at]; w[x]=0;
			if (!connect()){
				w[x]=1; continue;
			}
			cur=count();
		}
	}
	return 1;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	int fl=(n<m);
	if (fl) swap(n,m);
	if (!work()) puts("-1");
	else if (!fl){
		For(i,1,n){
			For(j,1,m) putchar(w[(i-1)*m+j]?'*':'.');
			puts("");
		}
	}
	else{
		For(i,1,m){
			For(j,1,n) putchar(w[(j-1)*m+i]?'*':'.');
			puts("");
		}
	}
	puts("");
}
int main(){
	srand(19*6*817);
	int T;
	scanf("%d",&T);
	while (T--) solve();
}