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
int x,k,n,Q,nd,val[10],sp[500];
int cnt[256],id[256];
map<int,int> mp;
struct mat{
	ll a[75][75];
	mat(){
		memset(a,30,sizeof(a));
	}
	mat operator *(const mat &b)const{
		mat ans;
		For(i,1,nd) For(j,1,nd) For(k,1,nd)
			ans.a[i][j]=min(ans.a[i][j],a[i][k]+b.a[k][j]);
		return ans;
	}
}ans,tr;
mat power(mat a,int b){
	mat ans;
	For(i,1,nd) ans.a[i][i]=0;
	for (;b;b/=2,a=a*a)
		if (b&1) ans=ans*a;
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d%d",&x,&k,&n,&Q);
	For(i,1,k) scanf("%d",&val[i]);
	For(i,0,(1<<k)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<k)-1) if (cnt[i]==x) id[i]=++nd;
	For(i,0,(1<<k)-1) if (id[i])
		if (!(i&1)) tr.a[id[i]][id[i/2]]=0;
		else For(j,1,k)	if (!(i&(1<<j))) tr.a[id[i]][id[(i+(1<<j))/2]]=val[j];
	For(i,1,Q){
		int x,v;
		scanf("%d%d",&x,&v);
		For(j,1,k) sp[++*sp]=max(0,x-j);
		mp[x]=v;
	}
	sp[++*sp]=n-x+1; sp[++*sp]=0;
	sort(sp+1,sp+*sp+1);
	*sp=unique(sp+1,sp+*sp+1)-sp-1;
	for (;sp[*sp]!=n-x+1;--*sp);
	mat ans;
	ans.a[1][id[(1<<x)-1]]=0;
	For(p,2,*sp){
		ans=ans*power(tr,sp[p]-sp[p-1]-1);
		if (p==*sp) break;
		mat ttmp;
		For(i,0,(1<<k)-1) if (id[i])
			if (!(i&1)) ttmp.a[id[i]][id[i/2]]=0;
			else For(j,1,k)	if (!(i&(1<<j))) ttmp.a[id[i]][id[(i+(1<<j))/2]]=val[j]+mp[sp[p]+j];
		ans=ans*ttmp;
	}
	ll res=ans.a[1][id[(1<<x)-1]];
	printf("%lld\n",res);
}