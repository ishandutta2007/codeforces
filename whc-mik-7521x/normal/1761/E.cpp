#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int T,n,siz[N],deg[N],vl[N],mp[N][N];
int fa[N];
char s[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[find(y)]=find(x);}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){scanf("%s",s+1);for(int o=1;o<=n;o++)mp[i][o]=s[o]=='1';}
		for(int i=1;i<=n;i++)fa[i]=i,deg[i]=0,siz[i]=0,vl[i]=0;
		for(int i=1;i<=n;i++){
			for(int o=1;o<=n;o++)if(mp[i][o]){
				deg[i]++;
                unnion(i,o);
			}
		}
		for(int i=1;i<=n;i++){
			vl[find(i)]+=deg[i];
			siz[find(i)]++;
		}
        vector<int>p;
		for(int i=1;i<=n;i++)if(fa[i]==i)p.push_back(i);
		if(p.size()==1){puts("0");continue;}
		int pd=0;
		for(int i:p){
			if(siz[i]==1){printf("1\n%d\n",i);pd=1;break;}
		}
		if(pd)continue;
		for(int i:p){
			if(vl[i]!=siz[i]*(siz[i]-1)){
				int kk=i;
				for(int o=1;o<=n;o++)if(fa[o]==i&&deg[o]<deg[kk])kk=o;
				printf("1\n%d\n",kk);
				pd=1;
				break;
			}
		}
		if(pd)continue;
		if((int)p.size()>2){printf("2\n%d %d\n",p[0],p[1]);continue;}
        stable_sort(p.begin(),p.end(),[&](int k1,int k2){return siz[k1]<siz[k2];});
		printf("%d\n",siz[p[0]]);
		for(int i=1;i<=n;i++)if(fa[i]==p[0])printf("%d ",i);
        puts("");
	}
    return 0;
}