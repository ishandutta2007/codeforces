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
const int N=500005;
char s[N];
int x[N],y[N],n;
int cnt[N],rk[N],SA[N];
int lg[N],st[N][20];
int cmp(int i,int j,int k){
	return y[i]!=y[j]||(i+k>n?-1:y[i+k])!=(j+k>n?-1:y[j+k]);
}
void build_SA(){
	int m=26;
	For(i,1,n) cnt[x[i]=s[i]-'a'+1]++;
	For(i,1,m) cnt[i]+=cnt[i-1];
	Rep(i,n,1) SA[cnt[x[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int p=0;
		For(i,n-k+1,n) y[++p]=i;
		For(i,1,n) if (SA[i]>k) y[++p]=SA[i]-k;
		For(i,1,m) cnt[i]=0;
		For(i,1,n) cnt[x[i]]++;
		For(i,1,m) cnt[i]+=cnt[i-1];
		Rep(i,n,1) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=x[SA[1]]=1;
		For(i,2,n) x[SA[i]]=(m+=cmp(SA[i],SA[i-1],k));
	}
	For(i,1,n) rk[SA[i]]=i;
	//For(i,1,n) cout<<rk[i]<<' '; cout<<endl;
	int p=0;
	For(i,1,n) if (rk[i]!=1){
		p-=(p!=0);
		for (;s[i+p]==s[SA[rk[i]-1]+p];++p);
		st[rk[i]][0]=p;
	}
	//For(i,1,n) cout<<st[i][0]<<' '; cout<<endl;
	For(i,2,n) lg[i]=lg[i/2]+1;
	For(i,1,18) For(j,1,n-(1<<i)+1)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
}
int nn,t[N*4];
int f[N],ans;
void build_tr(){
	for (nn=1;nn<=n+1;nn<<=1);
	For(i,1,2*nn-1) t[i]=-(1<<30);
}
void change(int x,int v){
	//cout<<"C"<<' '<<x<<' '<<v<<endl; 
	x+=nn;
	for (;x;x>>=1) t[x]=max(t[x],v);
}
int ask(int l,int r){
	int ans=-(1<<30);
	l+=nn-1; r+=nn+1;
	for (;l^r^1;l>>=1,r>>=1){
		if (!(l&1)) ans=max(ans,t[l^1]);
		if (r&1)	ans=max(ans,t[r^1]);
	}
	return ans;
}
bool check(int p,int func){
	int pl=rk[p],pr=rk[p];
	Rep(i,18,0){
		if (pl>(1<<i)&&st[pl-(1<<i)+1][i]>=func-1) pl-=(1<<i);
		if (pr+(1<<i)<=n&&st[pr+1][i]>=func-1) pr+=(1<<i);
	}
	//cout<<p<<' '<<pl<<' '<<pr<<' '<<func<<endl;
	if (ask(pl,pr)>=func-1) return 1;
	pl=rk[p+1]; pr=rk[p+1];
	Rep(i,18,0){
		if (pl>(1<<i)&&st[pl-(1<<i)+1][i]>=func-1) pl-=(1<<i);
		if (pr+(1<<i)<=n&&st[pr+1][i]>=func-1) pr+=(1<<i);
	}
	//cout<<p+1<<' '<<pl<<' '<<pr<<' '<<func<<endl;
	if (ask(pl,pr)>=func-1) return 1;
	return 0;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%s",&n,s+1);
	build_SA();
	int func=0;
	build_tr(); 
	Rep(i,n,1){
		func++;
		for (;func>1&&!check(i,func);--func)
			if (i+func-1<=n) change(rk[i+func-1],f[i+func-1]);
		//if (i+func<=n)
		//cout<<i<<' '<<func<<endl;
		f[i]=func;
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
}