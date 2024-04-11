#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100005

int T;

int n,m;
std::vector<int> a[N];

int p[N];
inline bool cmp(int x,int y){
	return a[x].size()<a[y].size();
}

int cnt[N],ans[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int k;
			scanf("%d",&k);
			a[i].resize(k);
			for(int j=0;j<k;j++)
				scanf("%d",&a[i][j]);
			p[i]=i;
		}
		std::sort(p+1,p+m+1,cmp);
		for(int i=1;i<=n;i++)
			cnt[i]=0;
		bool flg=1;
		for(int i=1;i<=m;i++){
			bool f=0;
			for(auto x:a[p[i]])
				if(cnt[x]!=(m-1)/2+1){
					ans[p[i]]=x;
					cnt[x]++;
					f=1;
					break;
				}
			if(!f)
				flg=0;
		}
		if(!flg)
			puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=m;i++)
				printf("%d ",ans[i]);
			puts("");
		}
	}
}