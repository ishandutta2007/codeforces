#include<cstdio>
#include<set>
#include<vector>
#define N 500005

int T;

int n,m;

std::set<int> s,g[N],h[N],f[N];
int fa[N];

std::vector<int> v1,v2;
int p[N],q[N];

inline void dfs(int u){
	s.erase(u);
	int v=0;
	while(1){
		std::set<int>::iterator it=s.upper_bound(v);
		if(it==s.end())
			break;
		v=*it;
		if(g[u].count(v))
			continue;
		h[u].insert(v);
		h[v].insert(u);
//		printf("!%d %d\n",u,v);
		dfs(v);
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].insert(v);
			g[v].insert(u);
		}
		for(int i=1;i<=n;i++)
			s.insert(i);
		while(s.size())
			dfs(*s.begin());
		for(int i=1;i<=n;i++)
			s.insert(i);
		while(s.size()){
			int u=*s.begin();
			s.erase(u);
//			printf("^%d\n",u);
			if(!h[u].size()){
				v1.push_back(u);
				v2.push_back(u);
			}
			bool flg=0;
			for(std::set<int>::iterator it=h[u].begin();it!=h[u].end();it++){
				int v=*it;
				if(s.count(v)){
					flg=1;
					fa[v]=u;
					f[u].insert(v);
					s.erase(v);
//					printf("+%d %d\n",u,v);
				}	
			}
			if(!flg){
				int v=*h[u].begin(),w=fa[v];
				if(!w){
					fa[u]=v;
					f[v].insert(u);
				}
				else if(f[w].size()==1){
					fa[w]=fa[u]=v;
					fa[v]=0;
					f[w].erase(v);
					f[v].insert(w);
					f[v].insert(u);
//					printf("-%d %d\n",w,v);
//					printf("+%d %d\n",v,w);
//					printf("+%d %d\n",v,u);
				}
				else{
					fa[v]=u;
					f[w].erase(v);
					f[u].insert(v);
//					printf("-%d %d\n",w,v);
//					printf("+%d %d\n",u,v);
				}
			}
//		printf("(%d)\n",s.count(12));
//		for(int i=1;i<=n;i++)
//			printf("%d ",fa[i]);
//		puts("");
		}
		for(int i=1;i<=n;i++)
			if(f[i].size()){
				v1.push_back(i);
//				printf("&%d\n",i);
				for(std::set<int>::iterator it=f[i].begin();it!=f[i].end();it++){
//					printf("%d ",*it);
					v1.push_back(*it);
					v2.push_back(*it);
				}
//				puts("");
				v2.push_back(i);
			}
		for(int i=0;i<n;i++)
//			printf("%d ",v1[i]),
			p[v1[i]]=i+1;
//		puts("");
		for(int i=0;i<n;i++)
//			printf("%d ",v2[i]),
			q[v2[i]]=i+1;
//		puts("");
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		puts("");
		for(int i=1;i<=n;i++)
			printf("%d ",q[i]);
		puts("");
		v1.clear();
		v2.clear();
		for(int i=1;i<=n;i++){
			fa[i]=0;
			g[i].clear();
			h[i].clear();
			f[i].clear();
		}
	}
}