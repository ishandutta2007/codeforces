#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int maxn=500005,maxt=maxn*31;
int n,S,ans,V,tot,nds;
int a[maxn],ok[maxn],vis[maxn],val[maxn],chd[maxt][2],ed[maxt];
map<int,int>mp;
vector<int>v[maxn];
int main(){
	scanf("%d%d",&n,&S),V=1;
	if(S==0){
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d%c",i,i==n? '\n':' ');
		return 0;
	}
	for(int i=30;i>=0;i--)
		if((S>>i)&1){
			V=(1<<i);
			break;
		}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x),a[i]=x;
		if(mp.count(x/V)==0)
			mp[x/V]=++tot,val[tot]=x/V;
		v[mp[x/V]].push_back(i);
	}
	for(int i=1;i<=tot;i++){
		if(vis[i])
			continue;
		int c=val[i]^1;
		if(mp.count(c)){
			int j=mp[c];
			if(vis[j])
				continue;
//			printf("i=%d j=%d val=%d val=%d\n",i,j,val[i],val[j]);
			nds=1;
			for(int k=0;k<v[i].size();k++){
				int x=a[v[i][k]],now=1;
				for(int p=30;p>=0;p--){
					int r=(x>>p)&1;
					if(chd[now][r]==0)
						chd[now][r]=++nds;
					now=chd[now][r];
				}
				ed[now]=v[i][k];
			}
			int flg=0,rec=0;
			for(int k=0;k<v[j].size();k++){
				int x=a[v[j][k]],now=1,res=0;
				for(int p=30;p>=0;p--){
					int r=(x>>p)&1;
					if(chd[now][r^1])
						now=chd[now][r^1],res|=(1<<p);
					else now=chd[now][r];
				}
				if(ed[now]&&res>=S){
					flg=v[j][k],rec=ed[now];
//					printf("flg=%d rec=%d res=%d\n",flg,rec,res);
					break;
				}
			}
			for(int k=1;k<=nds;k++)
				chd[k][0]=chd[k][1]=ed[k]=0;
			if(flg==0)
				ok[v[i][0]]=1;
			else ok[flg]=ok[rec]=1;
			vis[i]=vis[j]=1;
		}
	}
	for(int i=1;i<=tot;i++)
		if(vis[i]==0)
			ok[v[i][0]]=1;
	for(int i=1;i<=n;i++)
		ans+=ok[i];
	if(ans<2){
		puts("-1");
		return 0;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(ok[i])
			printf("%d ",i);
	puts("");
	return 0;
}