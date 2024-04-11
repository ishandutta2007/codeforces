#include<cstdio>
#include<algorithm>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 505

int n;

int sz[N],s[N];
pii a[N];

std::vector<int> ver;
inline int fnd(int u){
	int L=0,R=ver.size()-1,res=L-1;
	while(L<=R){
		int mid=(L+R)>>1;
		printf("1\n1\n%d\n",mid+1);
		for(int i=0;i<=mid;i++)
			printf("%d ",ver[i]);
		printf("\n%d\n",u);
		fflush(stdout);
		int tmp;
		scanf("%d",&tmp);
		if(tmp){
			res=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	int tmp=ver[res];
	ver.erase(ver.begin()+res);
	return tmp;
}

int fa[N];

int main(){
	scanf("%d",&n);
	s[1]=sz[1]=n;
	a[1]=mp(n,1);
	for(int i=2;i<=n;i++){
		printf("1\n1\n%d\n",n-1);
		for(int j=2;j<=n;j++)
			printf("%d ",j);
		printf("\n%d\n",i);
		fflush(stdout);
		scanf("%d",&sz[i]);
		a[i]=mp(sz[i],i);
		s[i]=sz[i];
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int u=a[i].sec;
		while(s[u]>1){
			int v=fnd(u);
			s[u]-=sz[v];
			fa[v]=u;
		}
		ver.push_back(u);
	}
	puts("ANSWER");
	for(int i=2;i<=n;i++)
		printf("%d %d\n",fa[i],i);
}