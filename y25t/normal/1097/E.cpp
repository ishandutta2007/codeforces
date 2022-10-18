#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N];

bool b[N];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,int d){
	for(;x<=n;x+=lb(x))
		t[x]=std::max(t[x],d);
}
inline int sum(int x){
	int res=0;
	for(;x;x-=lb(x))
		res=std::max(res,t[x]);
	return res;
}

int f[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			b[i]=0;
		std::vector<std::vector<int>> ans;
		int m=n;
		while(m){
			int k=0;
			while((k+1)*(k+2)/2<=m)
				k++;
			for(int i=1;i<=n;i++)
				t[i]=0;
			std::vector<int> A;
			int o=0;
			for(int i=1;i<=n;i++) if(!b[i]){
				add(a[i],f[i]=sum(a[i])+1);
				if(f[i]>f[o])
					o=i;
			}
			if(f[o]<=k){
				while(m){
					A.clear();
					o=0;
					for(int i=1;i<=n;i++) if(!b[i]&&(!o||a[i]<a[o]))
						o=i,A.push_back(i),b[i]=1,m--;
					ans.push_back(A);
				}
				break;
			}
			A.push_back(o),b[o]=1,m--;
			for(int i=o-1;i;i--) if(!b[i]&&a[i]<a[o]&&f[i]==f[o]-1)
				o=i,A.push_back(i),b[i]=1,m--;
			std::reverse(A.begin(),A.end());
			ans.push_back(A);
		}
		printf("%d\n",(int)ans.size());
		for(auto &x:ans){
			printf("%d ",(int)x.size());
			for(auto y:x)
				printf("%d ",a[y]);
			puts("");
		}
	}
}