#include<bits/stdc++.h>

int T;

#define W 30
int n,cnt[W]; 

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<W;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			for(int j=0;j<W;j++)
				cnt[j]+=(x>>j)&1;
		}
		int tmp=0;
		for(int i=0;i<W;i++)
			tmp=std::__gcd(cnt[i],tmp);
		for(int i=1;i<=n;i++)
			if(tmp%i==0)
				printf("%d ",i);
		puts("");
	}
}