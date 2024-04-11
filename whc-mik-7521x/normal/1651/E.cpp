#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,vis[N],in[N],l[N],r[N],fa[N],sizl[N],sizr[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
long long ans;
int solve(int x){return sizl[x]<sizr[x]?l[x]*(n-r[x]+1):0;}
int main(){
	scanf("%d",&n);
    vector<int>to[N];
	for(int i=1;i<=n*2;++i){
        int x,y;
		scanf("%d%d",&x,&y);
        to[x].push_back(y-n);
	}
	for(int i=1;i<=n;++i)if(to[i][0]>to[i][1])swap(to[i][0],to[i][1]);
	for(int i=1;i<=n;++i){
		long long res=0;
		for(int o=1;o<=n;++o)fa[o]=l[o]=r[o]=o,sizl[o]=0,sizr[o]=1;
		for(int o=i;o<=n;++o){
			int x=find(to[o][0]),y=find(to[o][1]);
			if(x==y){
                res+=solve(x);
                ++sizl[x];
                res-=solve(x);
            }
			else{
				res+=solve(x);
                res+=solve(y);
                fa[y]=x;
				sizl[x]+=sizl[y]+1;
                sizr[x]+=sizr[y];
				l[x]=min(l[x],l[y])
                ;r[x]=max(r[x],r[y]);
                res-=solve(x);
			}
			ans+=res;
		}
	}
	printf("%lld",ans);
	return 0;
}