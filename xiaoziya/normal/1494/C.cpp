#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,zas,fas,zbs,fbs,lans,rans;
int za[maxn],zb[maxn],fa[maxn],fb[maxn],pre[maxn],suf[maxn],a[maxn],b[maxn];
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		lans=rans=zas=fas=zbs=fbs=0,mp.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]),mp[a[i]]=1;
			if(a[i]<0)
				fa[++fas]=a[i];
			else za[++zas]=a[i];
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			if(b[i]<0)
				fb[++fbs]=b[i];
			else zb[++zbs]=b[i];
		}
		sort(fa+1,fa+1+fas),sort(za+1,za+1+zas),sort(fb+1,fb+1+fbs),sort(zb+1,zb+1+zbs);
		for(int i=1;i<=fbs;i++)
			pre[i]=pre[i-1]+(mp.count(fb[i])? 1:0);
		suf[zbs+1]=0;
		for(int i=zbs;i>=1;i--)
			suf[i]=suf[i+1]+(mp.count(zb[i])? 1:0);
		for(int i=fbs,j=fas;i>=1;i--){
			while(j>=1&&fa[j]>=fb[i])
				j--;
			int t=fas-j,L=i-1,R=fbs+1;
			while(L+1<R){
				int mid=(L+R)>>1;
				if(fb[mid]<=fb[i]+t-1)
					L=mid;
				else R=mid;
			}
			lans=max(lans,pre[i-1]+(L-i+1));
		}
		for(int i=1,j=1,k=1;i<=zbs;i++){
			while(j<=zas&&za[j]<=zb[i])
				j++;
			int t=j-1,L=0,R=i+1;
			while(L+1<R){
				int mid=(L+R)>>1;
				if(zb[mid]>=zb[i]-t+1)
					R=mid;
				else L=mid;
			}
			rans=max(rans,suf[i+1]+(i-R+1));
		}
		printf("%d\n",lans+rans);
	}
	return 0;
}