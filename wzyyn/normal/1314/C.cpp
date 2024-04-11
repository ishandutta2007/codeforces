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
const int N=1005;
const ll inf=1ll<<60;
int n,m,top,at[N];
int LCP[N][N];
pii q[N*N/2];
ll rk,f[N],sum[N];
char s[N];
void init(){
	Rep(i,n,1) Rep(j,n,1)
		LCP[i][j]=(s[i]==s[j]?LCP[i+1][j+1]+1:0);
}
bool cmp(pii x,pii y){
	int L=min(min(x.se,y.se),LCP[x.fi][y.fi]);
	if (L==y.se) return 0;
	if (L==x.se) return 1;
	return s[x.fi+L]<s[y.fi+L];
}
ll check(int pos){
	if (pos>top) return 0;
	memset(f,0,sizeof(f));
	f[n+1]=1; at[n+1]=n+2;
	For(i,1,n){
		int p=i;
		for (;p<=n&&cmp(pii(i,p-i+1),q[pos]);p++);
		at[i]=p; //cout<<p<<' ';
	}
	For(i,1,m){
		Rep(j,n+1,1) sum[j]=min(inf,sum[j+1]+f[j]);
		For(j,1,n+1) f[j]=sum[at[j]+1];
	}
	//cout<<pos<<' '<<f[1]<<endl;
	return f[1];
}
int main(){
	scanf("%d%d%lld",&n,&m,&rk);
	scanf("%s",s+1);
	init();
	For(i,1,n) For(j,i,n) q[++top]=pii(i,j-i+1);
	sort(q+1,q+top+1,cmp);
	//For(i,1,top) cout<<q[i].fi<<' '<<q[i].se<<endl;
	int l=1,r=top,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)>=rk)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	For(i,0,q[ans].se-1)
		printf("%c",s[q[ans].fi+i]);
}