#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define ll long long
#define N 200005
#define M 65

int n,m,k;
std::vector<int> a[N];
ll b[N];

char s[M];

int cnt[M];

int p[M];
bool flg[M],flg2[M];
ll ans,ans2;
int sz,sz2;

int main(){
	srand(514);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='1'){
				a[i].push_back(j);
				b[i]|=1ll<<(j-1);
			}
	}
	while(1){
		for(int i=1;i<=m;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
			if((b[i]&ans)==ans)
				for(auto j:a[i])
					cnt[j]++;
		int o=0;
		for(int i=1;i<=m;i++)
			if(cnt[i]>=(n+1)/2&&!flg[i]){
				o=i;
				break;
			}
		if(!o)
			break;
		ans|=1ll<<(o-1);
		flg[o]=1;
		sz++;
	}
	for(int i=1;i<=m;i++)
		p[i]=i;
	int T=20;
	while(T--){
		std::random_shuffle(p+1,p+m+1);
		for(int i=1;i<=m;i++)
			flg2[i]=0;
		ans2=0;
		sz2=0;
		while(1){
			for(int i=1;i<=m;i++)
				cnt[i]=0;
			for(int i=1;i<=n;i++)
				if((b[i]&ans2)==ans2)
					for(auto j:a[i])
						cnt[j]++;
			int o=0;
			for(int i=1;i<=m;i++)
				if(cnt[p[i]]>=(n+1)/2&&!flg2[p[i]]){
					o=p[i];
					break;
				}
			if(!o)
				break;
			ans2|=1ll<<(o-1);
			flg2[o]=1;
			sz2++;
		}
		if(sz2>sz)
			std::swap(flg,flg2);
	}
	for(int i=1;i<=m;i++)
		putchar(flg[i]?'1':'0');
	puts("");
}