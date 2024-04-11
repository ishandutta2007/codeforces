#include<bits/stdc++.h>
#define vi std::vector<int>
#define N 805

int n;

vi V[N<<2];
int a[N<<2];

inline int qry1(int i,int l,int r,int x,int y){
	printf("? %d ",(r-l+1)<<1);
	for(int j=l;j<=r;j++) if(j!=i)
		printf("%d %d ",V[j][0],V[j][1]);
	printf("%d %d\n",x,y),fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int ans[N];
inline int qry2(int x,int y){
	printf("? %d ",n-1-(std::min(x,n-1-x)<<1));
	for(int i=1;i<=n;i++) if(i!=y&&(ans[i]==-1||ans[i]==x||ans[i]==n-1-x))
		printf("%d ",i);
	puts(""),fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline void sch(int x){
	int u=1,t=x;
	while(~a[u])
		u=u<<1|(a[u]^(t&1)),t>>=1;
	if(V[u].size()==1)
		return ans[V[u][0]]=x,void();
	for(auto i:V[u]) if(qry2(x,i)){
		ans[i]=x;
		while(V[u].size()>1){
			a[u]=0,u=u<<1|(a[u]^(t&1)),t>>=1;
			if(std::find(V[u].begin(),V[u].end(),i)==V[u].end())
				a[u>>1]=1,u^=1;
		}
		break;
	}
}

int main(){
	scanf("%d",&n);
	V[1].resize(n),std::iota(V[1].begin(),V[1].end(),1);
	int l=1,r=1;
	while(1){
		bool flg=0;
		for(int i=l;i<=r;i++)
			flg|=V[i].size()>2;
		if(!flg){
			for(int i=l;i<=r;i++) if(V[i].size()==2)
				V[i<<1].emplace_back(V[i][0]),V[i<<1|1].emplace_back(V[i][1]);
			break;
		}
		for(int i=l;i<=r;i++){
			int x=V[i].back();
			vi &A=V[i<<1],&B=V[i<<1|1];
			if(V[i].size()==2){
				A.emplace_back(V[i][0]),B.emplace_back(V[i][1]);
				continue;
			}
			for(auto y:V[i]) if(y!=x)
				(qry1(i,l,r,x,y)?A:B).emplace_back(y);
			if(A.size()!=B.size())
				(A.size()<B.size()?A:B).emplace_back(x);
			else
				(qry1(i,l,r,A[0],B[0])?B:A).emplace_back(x);
		}
		l=l<<1,r=r<<1|1;
	}
	memset(a,-1,sizeof(a)),memset(ans,-1,sizeof(ans));
	for(int i=0;i<n/2;i++)
		sch(i),sch(n-1-i);
	if(ans[1]>=n/2)
		for(int i=1;i<=n;i++)
			ans[i]=n-1-ans[i];
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]+1);
	puts(""),fflush(stdout);
}