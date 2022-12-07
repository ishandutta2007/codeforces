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
const int N=1<<18;
int n,a[N],fa[N],id[N];
pii mn[N],smn[N],mat[N];
void UPD(int id,pii v){
	if (v>mn[id]) swap(mn[id],v);
	if (v.se!=mn[id].se) smn[id]=max(smn[id],v);
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	ll ans=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n+1) fa[i]=i;
	For(i,1,18){
		For(j,0,N-1) mn[j]=smn[j]=pii(-(1<<30),0);
		For(j,1,n+1) UPD(a[j],pii(a[j],get(j)));
		for (int d=1;d<N;d<<=1)
			for (int i=0;i<N;i+=d<<1)
				for (int j=0;j<d;j++){
					swap(mn[i|j],mn[i|j|d]);
					swap(smn[i|j],smn[i|j|d]);
					UPD(i|j,mn[i|j|d]);
					UPD(i|j,smn[i|j|d]);
				}
		For(j,1,n+1) id[j]=0;
		For(j,1,n+1){
			int x=get(j);
			mat[j]=(mn[a[j]].se==get(x)?smn[a[j]]:mn[a[j]]);
			if (a[j]+mat[j].fi>a[id[x]]+mat[id[x]].fi||!id[x]) id[x]=j;
		}
		For(j,1,n+1) if (get(j)==j){
			int x=id[j];
			if (!mat[x].se) continue;
			if (get(mat[x].se)==get(j)) continue;
			//cout<<"MAT "<<a[x]<<' '<<mat[x].fi<<' '<<j<<' '<<mat[x].se<<' '<<get(j)<<' '<<get(mat[x].se)<<endl;
			ans+=a[x]+mat[x].fi;
			fa[j]=get(mat[x].se);
		}
	} 
	For(i,1,n) ans-=a[i];
	printf("%lld\n",ans);
}