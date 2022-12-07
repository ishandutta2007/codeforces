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
const int N=3005;
int R,C,n,K,q[N];
int q1[15],q2[15],vis[N];
int pre[N],nxt[N];
vector<int> vec[N];
pii a[N];
ll ans;
int main(){
	scanf("%d%d%d%d",&R,&C,&n,&K);
	For(i,1,n) scanf("%d%d",&a[i].se,&a[i].fi);
	sort(a+1,a+n+1);
	For(i,1,n) q[i]=a[i].fi;
	For(i,1,n) vec[a[i].se].PB(i);
	q[0]=0; q[n+1]=C+1;
	For(i,1,R){
		memset(vis,0,sizeof(vis));
		For(j,i,R)
			For(k,0,vec[j].size()-1)
				vis[vec[j][k]]=1;
		int la=0; pre[0]=0;
		For(j,1,n) if (vis[j])
			nxt[la]=j,pre[j]=la,la=j;
		//printf("INFO %d %d\n",i,la);
		nxt[la]=nxt[n+1]=n+1; pre[n+1]=la;
		if (la==0) continue;
		//printf("INFO %d\n",i);
		int cnt=0;
		For(j,1,n) if (vis[j]){
			int x=j;
			For(k,1,K-1) x=nxt[x];
			//printf("INFO %d %d %d %d\n",j,x,q[j],q[pre[j]]);
			cnt+=(q[j]-q[pre[j]])*(C+1-q[x]);
		}
		Rep(j,R,i){
			ans+=cnt;
			//printf("INFO %d %d %d\n",i,j,cnt);
			For(k,0,vec[j].size()-1){
				int p=vec[j][k]; *q1=*q2=0;
				for (int x=p;x!=0  &&*q1<K;x=pre[x]) q1[++*q1]=x;
				for (int y=p;y!=n+1&&*q2<K;y=nxt[y]) q2[++*q2]=y;
				pre[nxt[p]]=pre[p]; nxt[pre[p]]=nxt[p];
				//printf("ERASE %d %d %d %d %d\n",i,j,p,*q1,*q2);
				For(l,1,*q1) if (K-l+1<=*q2)
					cnt-=(q[q1[l]]-q[pre[q1[l]]])*(q[nxt[q2[K-l+1]]]-q[q2[K-l+1]]);
			}
		}
	}
	printf("%lld\n",ans);
}