#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define B 1000

int n,m;
ll a[N],s[N];
int b[N][3],p[N];

std::vector<int> X,Y,V[N];
int col[N],id[N],tot,q[N],cnt[B<<1][B<<1];
ll A[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	scanf("%d",&m);
	for(int r=1,l=1;r<=m;r++){
		scanf("%d%d%d",&b[r][0],&b[r][1],&b[r][2]);
		if(r<m&&r%B)
			continue;
		X.clear(),Y.clear();
		for(int i=l;i<=r;i++)
			if(b[i][0]==1)
				X.push_back(b[i][1]-1),X.push_back(b[i][2]);
			else{
				Y.push_back(b[i][1]);
				if(b[i][0]==3)
					Y.push_back(b[i][2]);
			}
		std::sort(X.begin(),X.end()),X.erase(std::unique(X.begin(),X.end()),X.end());
		std::sort(Y.begin(),Y.end()),Y.erase(std::unique(Y.begin(),Y.end()),Y.end());
		memset(id,-1,sizeof(id)),tot=0;
		for(auto u:Y)
			id[u]=tot++;
		memset(col,0,sizeof(col));
		for(auto u:Y){
			std::vector<int> U;
			for(int v=p[u];;v=p[v]){
				U.push_back(v);
				if(~id[v]){
					q[u]=v;
					for(auto w:U)
						col[w]=v;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++) if(col[i])
			V[col[i]].push_back(i);
		memset(cnt,0,sizeof(cnt));
		for(auto u:Y)
			for(int i=0,j=-1;i<(int)X.size();i++){
				while(j+1<(int)V[u].size()&&V[u][j+1]<=X[i])
					j++;
				cnt[id[u]][i]=j;
			}
		for(auto u:Y)
			A[u]=0;
		for(int i=l;i<=r;i++){
			int op=b[i][0],x=b[i][1],y=b[i][2];
			if(op==1){
				ll res=s[y]-s[x-1];
				x=std::lower_bound(X.begin(),X.end(),x-1)-X.begin();
				y=std::lower_bound(X.begin(),X.end(),y)-X.begin();
				for(auto u:Y)
					res+=A[u]*(cnt[id[u]][y]-cnt[id[u]][x]);
				printf("%lld\n",res);
			}
			else if(op==2){
				A[x]+=y;
				for(int z=q[x];z!=x;z=q[z])
					A[z]+=y;
			}
			else
				std::swap(q[x],q[y]),std::swap(p[x],p[y]);
		}
		for(auto u:Y)
			for(auto i:V[u])
				a[i]+=A[u];
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(auto u:Y)
			std::vector<int>().swap(V[u]);
		l=r+1;
	}
}