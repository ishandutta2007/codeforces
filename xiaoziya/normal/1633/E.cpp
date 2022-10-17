#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=305,maxn=55;
int n,m,nums,pilot,p,q,a,b,c;
int xx[maxm],yy[maxm],zz[maxm],num[maxm*maxm],dsu[maxn],id[maxm],slp[maxm*maxm];
long long all,ans;
long long res[maxm*maxm];
int find(int x){
	return dsu[x]==x? x:dsu[x]=find(dsu[x]);
}
inline int cmp(int a,int b){
	return abs(zz[a]-pilot)<abs(zz[b]-pilot)||(abs(zz[a]-pilot)==abs(zz[b]-pilot)&&zz[a]>zz[b]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&xx[i],&yy[i],&zz[i]),num[++nums]=zz[i],id[i]=i;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			num[++nums]=(zz[i]+zz[j]+1)/2;
	num[++nums]=0,sort(num+1,num+1+nums),nums=unique(num+1,num+1+nums)-num-1;
	for(int i=1;i<=nums;i++){
		pilot=num[i],sort(id+1,id+1+m,cmp);
		for(int j=1;j<=n;j++)
			dsu[j]=j;
		for(int j=1;j<=m;j++){
			int x=find(xx[id[j]]),y=find(yy[id[j]]);
			if(x!=y)
				dsu[x]=y,res[i]+=abs(num[i]-zz[id[j]]),slp[i]+=(zz[id[j]]<=num[i])? 1:-1;
		}
	}
	scanf("%d%d%d%d%d",&p,&q,&a,&b,&c);
	for(int i=1,x;i<=q;i++){
		if(i<=p)
			scanf("%d",&x);
		else x=(1ll*x*a+b)%c;
		int L=0,R=nums+1;
		while(L+1<R){
			int mid=(L+R)>>1;
			if(x>=num[mid])
				L=mid;
			else R=mid;
		}
		ans=res[L]+1ll*slp[L]*(x-num[L]);
		all^=ans;
	}
	printf("%lld\n",all);
	return 0;
}