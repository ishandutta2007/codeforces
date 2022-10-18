#include<cstdio>
#include<algorithm>
#define pii std::pair<int,int>
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 100005

int T;

int n,m,x;

pii a[N];

int b[N];

int p[N],ans[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&x);
		for(int i=1;i<=m;i++)
			b[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].fir);
			a[i].sec=i;
		}
		std::sort(a+1,a+n+1);
		p[n+1]=0;
		for(int i=n,tmp=0,flg=1,cnt=0;i;i--){
			tmp+=flg;
			p[i]=tmp;
			b[p[i]]+=a[i].fir;
			if(++cnt==m){
				cnt=0;
				tmp+=flg;
				flg*=-1;
			}
		}
		int mx=0,mn=inf;
		for(int i=1;i<=m;i++){
			mx=std::max(mx,b[i]);
			mn=std::min(mn,b[i]);
		}
		if(mx-mn<=x){
			puts("YES");
			for(int i=1;i<=n;i++)
				ans[a[i].sec]=p[i];
			for(int i=1;i<=n;i++)
				printf("%d ",ans[i]);
			puts("");
		}
		else
			puts("NO");
	}
}