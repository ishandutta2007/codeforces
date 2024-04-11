#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 100105
#define K 10

int n,k,col[N];
char str[N];

std::vector<std::pair<int,int>> V[K][K];

std::vector<int> E[N];
inline void adde(int u,int v){
	E[u].emplace_back(v),E[v].emplace_back(u);
}

int dis[K][N];

int st[K<<2][N],top[K<<2];
inline void bfs(int s,int *d){
	d[s]=0,st[0][++top[0]]=s;
	for(int i=0;i<=k*4;i++)
		while(top[i]){
			int u=st[i][top[i]--];
			for(auto v:E[u]){
				int w=u>n||v>n?1:2;
				if(d[v]>d[u]+w)
					d[v]=d[u]+w,st[d[v]][++top[d[v]]]=v;
			}
		}
}

int a[N],f[K][1<<16];

long long cnt[K<<2];

int main(){
	scanf("%d%s",&n,str+1),k=8;
	for(int i=1;i<=n;i++){
		col[i]=str[i]-'a'+1;
		adde(col[i]+n,i);
		if(i>1)
			adde(i-1,i);
		for(int o=1;o<i&&o<=(k-1)*2;o++)
			V[col[i]][col[i-o]].emplace_back(i,i-o);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++)
		bfs(i+n,dis[i]);
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) if(dis[i][j]+1==dis[i][col[j]+n])
		a[j]|=1<<(i-1);
	for(int i=1;i<=k;i++){
		for(auto j:E[i+n])
			f[i][a[j]]++;
		for(int x=1;x<(1<<k);x<<=1) for(int y=0;y<(1<<k);y+=x<<1) for(int z=0;z<x;z++)
			f[i][x+y+z]+=f[i][y+z];
	}
	for(int i=1;i<=k;i++) if(E[i+n].size()) for(int j=1;j<=k;j++) if(E[j+n].size()){
		int t=E[j+n].size();
		if(i==j){
			cnt[2]+=1ll*t*(t-1);
			continue;
		}
		int mn=inf;
		for(int l=1;l<=k;l++)
			mn=std::min(mn,dis[i][l+n]+dis[j][l+n]);
		int s0=0,s1=0;
		for(int l=1;l<=k;l++){
			int tmp=dis[i][l+n]+dis[j][l+n];
			if(tmp==mn)
				s0|=1<<(l-1);
			else if(tmp==mn+2)
				s1|=1<<(l-1);
		}
		for(auto x:E[i+n]){
			int u=t-f[j][((1<<k)-1)^(a[x]&s0)],v=a[x]&s0?0:f[j][((1<<k)-1)^(s0|(a[x]&s1))],w=t-u-v;
			cnt[mn-2]+=u,cnt[mn+2]+=v,cnt[mn]+=w;
		}
		for(auto o:V[i][j]){
			int u,v;
			std::tie(u,v)=o;
			int tmp=a[u]&a[v]&s0?mn-2:!((a[u]|a[v])&s0)&&!(a[u]&a[v]&s1)?mn+2:mn;
			if(tmp>2*(u-v))
				cnt[tmp]-=2,cnt[2*(u-v)]+=2;
		}
	}
	for(int i=k<<2;i;i--) if(cnt[i])
		return printf("%d %lld\n",i>>1,cnt[i]>>1),0;
}