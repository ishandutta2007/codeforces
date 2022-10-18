#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200005

int T;

int n,l,r;

int cnt[2][N];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			cnt[0][i]=cnt[1][i]=0;
		scanf("%d%d%d",&n,&l,&r);
		for(int i=1;i<=l;i++){
			int x;
			scanf("%d",&x);
			cnt[0][x]++;
		}
		for(int i=1;i<=r;i++){
			int x;
			scanf("%d",&x);
			cnt[1][x]++;
		}
		for(int i=1;i<=n;i++){
			int tmp=std::min(cnt[0][i],cnt[1][i]);
			cnt[0][i]-=tmp;
			cnt[1][i]-=tmp;
			l-=tmp;
			r-=tmp;
		}
		if(l==r){
			printf("%d\n",l);
			continue;
		}
		int o=l<r,d=(o?r-l:l-r)/2;
		int ans=(l+r)/2+d;
		for(int i=1;i<=n;i++){
			int tmp=std::min(d,cnt[o][i]/2);
			ans-=tmp;
			d-=tmp;
		}
		printf("%d\n",ans);
	}
}