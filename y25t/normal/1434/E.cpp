#include<cstdio>
#include<algorithm>
#define N 100005
#define B 450

int T;

int n,a[N];

struct dsu{
	int f[N],val[N];
	
	inline void cl(){
		for(int i=1;i<=n;i++)
			f[i]=val[i]=0;
	}
	inline int fnd(int x){
		return f[x]?f[x]=fnd(f[x]):x;
	}
	inline void uni(int l,int r,int c){
		if(!l)
			l++;
//		printf("*%d %d %d\n",l,r,c);
		for(int i=fnd(l);i<r;i=f[i]=fnd(i+1))
			val[i]=c;
	}
}g[B];

int f[B],sg[N];
bool vis[N];

int ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<B;i++)
			g[i].cl();
		for(int i=0;i<B;i++)
			f[i]=N;
//		f[n][0]=N;
		g[1].uni(1,n,n);
		sg[n]=1;
		for(int i=n-1;i;i--){
			for(int j=1;g[j].val[i];j++){
//				printf("&%d %d %d\n",i,j,g[j].val[i]);
				f[j+1]=std::min(f[j],a[g[j].val[i]]-a[i]-1);
				sg[i]=j+1;
			}
//			printf("^%d %d\n",i,sg[i]);
//			for(int j=1;j<=sg[i];j++)
//				printf("%d ",f[j]);
//			puts("");
			for(int j=sg[i],r=i,l;j;j--){
				l=std::lower_bound(a+1,a+n+1,a[i]-f[j])-a;
				g[j].uni(l,r,i);
				r=l;
			}
		}
//		for(int i=0;i<B;i++)
//			vis[i]=0;
//		for(int i=1;i<=n;i++)
//			vis[sg[i]]=1;
		int tmp=1;
		for(int i=1;i<=n;i++)
			tmp=std::max(tmp,sg[i]);
//		printf("%d\n",tmp);
		ans^=tmp;
	}
	puts(ans?"YES":"NO");
}