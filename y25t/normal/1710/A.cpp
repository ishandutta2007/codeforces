#include<bits/stdc++.h>
#define N 100005

int T;

int n,m,k,a[N];

inline bool chk(){
	long long tmp=0;
	int mx=0;
	for(int i=1;i<=k;i++){
		int x=a[i]/n;
		if(x>=2){
			if(m-tmp==1)
				return mx>2;
			tmp+=x;
		}
		mx=std::max(mx,x);
	}
	return tmp>=m;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+k+1,std::greater<int>());
		if(chk()){
			puts("Yes");
			continue;
		}
		std::swap(n,m);
		puts(chk()?"Yes":"No");
	}
}