#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define M 1000005

int n,m,a[N];

int pr[M],_pr;
bool npr[M];
inline void si(int x){
	for(int i=2;i<=x;i++){
		if(!npr[i])
			pr[++_pr]=i;
		for(int j=1;j<=_pr&&i*pr[j]<=x;j++){
			npr[i*pr[j]]=1;
			if(i%pr[j]==0)
				continue;
		}
	}
}

std::vector<int> d[N],e[N];

int f[M];
inline int fnd(int x){
	return f[x]?f[x]=fnd(f[x]):x;
}
inline void mrg(int x,int y){
	int fx=fnd(x),fy=fnd(y);
	if(fx==fy)
		return;
	f[fx]=fy;
}

std::unordered_map<ll,int> vis;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	si(1000001);
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=_pr&&pr[j]*pr[j]<=x;j++)
			if(x%pr[j]==0){
				d[i].push_back(pr[j]);
				while(x%pr[j]==0)
					x/=pr[j];
			}
		if(x>1)
			d[i].push_back(x);
		for(auto j:d[i])
			mrg(d[i][0],j);
		e[i]=d[i];
		x=a[i]+1;
		for(int j=1;j<=_pr&&pr[j]*pr[j]<=x;j++)
			if(x%pr[j]==0){
				e[i].push_back(pr[j]);
				while(x%pr[j]==0)
					x/=pr[j];
			}
		if(x>1)
			e[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
		for(auto j:e[i])
			for(auto k:e[i])
				vis[1ll*fnd(j)*fnd(k)]=1;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		bool flg=0,ff=0;
		for(auto i:d[x])
			for(auto j:d[y]){
				if(fnd(i)==fnd(j))
					flg=1;
				if(vis[1ll*fnd(i)*fnd(j)])
					ff=1;
			}
		if(flg)
			puts("0");
		else if(ff)
			puts("1");
		else
			puts("2");
	}
}