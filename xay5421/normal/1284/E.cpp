#include<bits/stdc++.h>
typedef long long ll;
const int N=10005;
int n,top,x[N],y[N],l[N],r[N],sum[N];ll ans;
struct P{int x,y,k1;}p[N];
int get(P k1){
	int x=k1.x,y=k1.y;
	if(x>0&&y>=0)return 0;
	if(x<=0&&y>0)return 1;
	if(x<0&&y<=0)return 2;
	if(x>=0&&y<0)return 3;
}
ll cross(P x,P y){return 1ll*x.x*y.y-1ll*x.y*y.x;}
bool cmp(P x,P y){return get(x)^get(y)?get(x)<get(y):cross(x,y)>0;}
ll C4(int x){return 1ll*x*(x-1)*(x-2)*(x-3)/24;}
ll C3(int x){return 1ll*x*(x-1)*(x-2)/6;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i){
		memset(l,0,sizeof(l)),memset(r,0,sizeof(r)),top=0;
		for(int j=1;j<=n;++j)if(j!=i)p[++top]=(P){x[j]-x[i],y[j]-y[i],j},p[++top]=(P){x[i]-x[j],y[i]-y[j],-j};
		std::sort(p+1,p+1+top,cmp);
		for(int j=1;j<=top;++j)p[top+j]=p[j];
		top*=2;
		for(int j=1;j<=top;++j){
			if(p[j].k1>0){
				if(!l[p[j].k1])l[p[j].k1]=j;
			}else if(p[j].k1<0){
				if(l[-p[j].k1]&&!r[-p[j].k1])r[-p[j].k1]=j;
			}
		}
		ans+=C4(n-1);
		for(int j=1;j<=top;++j)sum[j]=sum[j-1]+(p[j].k1>0);
		for(int j=1;j<=n;++j)if(i!=j){
			ans-=C3(sum[r[j]]-sum[l[j]]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}