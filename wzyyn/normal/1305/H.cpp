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
int n,m,x,Q;
int l[N],r[N],lim[N];
int vQ[N],vC[N];
ll Sum;
void GG(){
	puts("-1 -1");
	exit(0);
}
void init(){
	ll tmp=Sum;
	For(i,1,n) tmp-=l[i];
	if (tmp<0) GG();
	static int S[N];
	memset(S,0,sizeof(S));
	For(i,1,n) ++S[l[i]+1],--S[r[i]+1];
	For(i,1,m) S[i]+=S[i-1];
	int p=1;
	for (;tmp>S[p]&&p<=m;tmp-=S[p++]);
	if (p>m) GG();
	For(i,1,n) vQ[i]=max(l[i],min(p-1,r[i]));
	For(i,1,n) if (vQ[i]==p-1&&r[i]>=p&&tmp) ++vQ[i],--tmp;
	sort(vQ+1,vQ+n+1);
}


int check2(int len,int val){
	For(i,0,m+1) l[i]=0,r[i]=n;
	For(i,1,m) if (lim[i]!=-1){
		l[i]=max(l[i],lim[i]);
		r[i]=min(r[i],lim[i]);
	}
	For(i,1,len){
		l[i]=max(l[i],val);
		r[i]=min(r[i],val);
	}
	For(i,1,m+1) r[i]=min(r[i],r[i-1]);
	Rep(i,m,0) l[i]=max(l[i],l[i+1]);
	//For(i,0,m+1) cout<<l[i]<<' '<<r[i]<<endl;
	//printf("CHECK2 %d %d\n",len,val);
	For(i,0,m+1) assert(l[i]<=r[i]);
	ll tmp=Sum;
	For(i,1,m) tmp-=l[i];
	if (tmp<0) return 1;
	For(i,1,m) tmp-=r[i]-l[i];
	//cout<<"val "<<tmp<<endl;
	if (tmp>0) return -1;
	return 0;
}
bool check1(int len,int val){
	int v=-1;
	For(i,1,len) v=max(v,lim[i]);
	int L=max(0,val),R=(v==-1?n:v),ans=-1;
	For(i,1,m) L=max(L,lim[i]);
	For(i,1,len) if (lim[i]!=-1) R=min(R,lim[i]);
	while (L<=R){
		int mid=(L+R)/2;
		int res=check2(len,mid);
		if (res==0) ans=mid,R=mid-1;
		else (res<0?L=mid+1:R=mid-1);
	}
	//cout<<"CHECK1 "<<len<<' '<<ans<<' '<<val<<' '<<L<<' '<<R<<endl;
	if (ans==-1) return 0;
	check2(len,ans);
	static int S[N];
	memset(S,0,sizeof(S));
	ll tmp=Sum;
	For(i,1,m) tmp-=l[i];
	For(i,1,m) ++S[l[i]+1],--S[r[i]+1];
	For(i,1,n) S[i]+=S[i-1];
	int p=1;
	for (;tmp>S[p]&&p<=n;tmp-=S[p++]);
	For(i,1,m) vC[i]=max(l[i],min(p-1,r[i]));
	For(i,1,m) if (vC[i]==p-1&&r[i]>=p&&tmp) --tmp,++vC[i];
	sort(vC+1,vC+m+1);
	reverse(vC+1,vC+m+1);
	//For(i,1,m) cout<<vC[i]<<' '; cout<<endl;
	ll S1=0,S2=0; p=0;
	For(i,1,n){
		for (;p<m&&vC[p+1]==n-i+1;++p);
		S1+=vQ[i]; S2+=p;
		if (S1<S2) return 0;
	}
	return 1;
	//sort(vQ+1,vC+m+1);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d%d",&l[i],&r[i]);
	For(i,0,m+1) lim[i]=-1;
	scanf("%d",&Q);
	For(i,1,Q) scanf("%d",&x),scanf("%d",&lim[x]);
	scanf("%lld",&Sum);
	init();
	//For(i,1,n) cout<<vQ[i]<<' '; cout<<endl;
	if (!check1(1,-1)) GG();
	int l=2,r=m,ans1=1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check1(mid,-1))
			ans1=mid,l=mid+1;
		else r=mid-1;
	}
	int ans2=0; l=0,r=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (check1(ans1,mid))
			ans2=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",ans1,ans2);
}