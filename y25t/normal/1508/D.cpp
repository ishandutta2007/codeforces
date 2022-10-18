#include<bits/stdc++.h>
#define N 2005

int n,a[N],x[N],y[N];

int p[N],m;

int f[N];
inline int fnd(int i){
	return f[i]?f[i]=fnd(f[i]):i;
}
inline bool mrg(int i,int j){
	int fx=fnd(i),fy=fnd(j);
	if(fx==fy)
		return 0;
	f[fx]=fy;
	return 1;
}

std::vector<std::pair<int,int> > ans;
inline void op(int i,int j){
	ans.push_back(std::make_pair(i,j));
	std::swap(a[i],a[j]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&a[i]);
		if(a[i]!=i)
			p[++m]=i;
		mrg(i,a[i]);
	}
	if(!m){
		puts("0");
		return 0;
	}
	std::sort(p+1,p+m+1,[&](int i,int j){
		return y[i]<y[j];
	});
	for(int i=m;i;i--)
		x[p[i]]-=x[p[1]],y[p[i]]-=y[p[1]];
	std::sort(p+2,p+m+1,[&](int i,int j){
		return 1ll*x[i]*y[j]-1ll*y[i]*x[j]>0;
	});
	for(int i=2;i<m;i++)
		if(mrg(p[i],p[i+1]))
			op(p[i],p[i+1]);
	while(a[p[1]]!=p[1])
		op(p[1],a[p[1]]);
	printf("%d\n",ans.size());
	for(auto x:ans)
		printf("%d %d\n",x.first,x.second);
}