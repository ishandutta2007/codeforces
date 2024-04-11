#include <bits/stdc++.h>
using namespace std;
const int N=1009;
int n,head[N],tot;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){
	g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int d[N];
int main() {
	memset(d,0,sizeof(d));
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		add(u,v);add(v,u);d[u]++,d[v]++;
	}int pos=1;
	cout.flush();
	int T=n/2;
	while(T--){
		int x=0,y=0;
		for(int i=1;i<=n;i++) {
			if(x&&y) break;
			if(d[i]==1){
				if(!x) x=i;
				else y=i;
			}
		}
		cout<<"?"<<" "<<x<<" "<<y<<endl;
	    cout.flush();
		int ans;scanf("%d",&ans);pos=ans;
		if(ans==x||ans==y) break;
		for(int i=head[x];i!=-1;i=g[i].nxt) d[g[i].to]--;
		for(int i=head[y];i!=-1;i=g[i].nxt) d[g[i].to]--;
		d[x]=0,d[y]=0;
	}
	printf("! %d\n",pos);
	return 0;
}