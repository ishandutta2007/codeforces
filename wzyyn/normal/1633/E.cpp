#include<bits/stdc++.h>

using namespace std;

const int N=305;
int n,m,ex[N],ey[N],ev[N];
long long k1[N*N],k2[N*N];
int op[N*N],fa[N];

int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void solve(int id){
	int v=op[id];
	for (int i=1;i<=m;i++)
		for (int j=i;j>=2;j--){
			int v1=abs(v-ev[j-1]);
			int v2=abs(v-ev[j]);
			if (v1>v2||(v1==v2&&ev[j-1]>ev[j])){
				swap(ex[j-1],ex[j]);
				swap(ey[j-1],ey[j]);
				swap(ev[j-1],ev[j]);
			}
			else
				break;
		}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int x=get(ex[i]),y=get(ey[i]);
		if (x!=y){
			fa[x]=y;
			if (ev[i]>=v)
				k1[id]--,k2[id]+=ev[i];
			else
				k1[id]++,k2[id]-=ev[i];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&ex[i],&ey[i],&ev[i]);
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (ev[j]<ev[i]){
				swap(ex[i],ex[j]);
				swap(ey[i],ey[j]);
				swap(ev[i],ev[j]);
			}
	for (int i=1;i<=m;i++)
		op[++*op]=ev[i];
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			op[++*op]=(ev[i]+ev[j])/2;
	op[++*op]=1<<30;
	op[++*op]=-1;
	sort(op+1,op+*op+1);
	*op=unique(op+1,op+*op+1)-op-1;
	for (int i=2;i<=*op;i++) solve(i);
	int p,k,a,b,c,v;
	long long ans=0;
	scanf("%d%d%d%d%d",&p,&k,&a,&b,&c);
	for (int i=1;i<=p;i++){
		scanf("%d",&v);
		int x=lower_bound(op+1,op+*op+1,v)-op;
		ans^=(1ll*k1[x]*v+k2[x]);
		//if (i==1) cout<<ans<<endl;
	}
	for (int i=p+1;i<=k;i++){
		v=(1ll*v*a+b)%c;
		int x=lower_bound(op+1,op+*op+1,v)-op;
		ans^=(1ll*k1[x]*v+k2[x]);
		//if (i<=4) cout<<ans<<endl;
	}
	cout<<ans<<endl;
}