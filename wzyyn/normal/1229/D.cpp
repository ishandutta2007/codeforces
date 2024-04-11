#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=12000,M=220;
int a[M],b[M];
int tr1[N],tr2[M];
int tr[M][M],n,k,nd;
int q[M],T[M],top;
int vis[M],qq[M];
ll ans;
int gettr(int x,int y){
	Rep(i,k,1) a[i]=x%6,x/=6;
	Rep(i,k,1) b[i]=y%6,y/=6;
	int ans=0;
	For(i,1,k)
		ans=ans*6+b[a[i]];
	return tr1[ans];
}
void getid(int x,int hv){
	if (x>k){
		tr1[hv]=++nd;
		tr2[nd]=hv;
		return;
	}
	For(i,1,k) if (!vis[i]){
		vis[i]=1;
		getid(x+1,hv*6+i);
		vis[i]=0;
	}
}
void init(){
	getid(1,0);
	For(i,1,nd) For(j,1,nd)
		tr[i][j]=gettr(tr2[i],tr2[j]);
}
void work_SSSP(){
	For(i,1,nd) vis[i]=0;
	qq[0]=qq[1]=vis[1]=1;
	int tmp=0;
	ans+=T[1];
	For(i,1,top){
		int las=*qq;
		For(j,1,las)
			if (!vis[tr[qq[j]][q[i]]]){
				vis[tr[qq[j]][q[i]]]=1;
				qq[++*qq]=tr[qq[j]][q[i]];
			}
		if (*qq==las) continue;
		For(j,las+1,*qq) For(k,1,i)
			if (!vis[tr[qq[j]][q[k]]]){
				vis[tr[qq[j]][q[k]]]=1;
				qq[++*qq]=tr[qq[j]][q[k]];
			}
		ans+=T[i]*((*qq)-las);
		//printf("%d %d %d %d %lld\n",i,T[i],*qq,las,ans);
		q[++tmp]=q[i]; T[tmp]=T[i];
	}
	top=tmp;
}
int main(){
	scanf("%d%d",&n,&k);
	init();
	For(i,1,n){
		int x=0,y=0;
		For(j,1,k) scanf("%d",&y),x=x*6+y;
		x=tr1[x]; ++top;
		Rep(j,top,2){
			q[j]=q[j-1];
			T[j]=T[j-1];
		}
		q[1]=x;
		T[1]=i;
		//puts("233");
		work_SSSP();
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}