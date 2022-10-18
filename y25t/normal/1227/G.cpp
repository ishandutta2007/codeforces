#include<cstdio>
#include<algorithm>
#define N 1005

int n,a[N];

int p[N];

int m,ans[N][N];
inline bool cmp(int x,int y){
	return std::max(a[x],m-a[x])>std::max(a[y],m-a[y]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m=std::max(m,a[i]);
	}
	m++;
	for(int i=1;i<=n;i++)
		p[i]=i;
	std::sort(p+1,p+n+1,cmp);
	int s=1,t=m;
	for(int i=1;i<=n;i++){
		int x=a[p[i]],y=std::max(x,m-x);
//		printf("$%d %d %d %d %d\n",p[i],x,y,s,t);
		for(int k=1;k<=m;k++)
			ans[k][p[i]]=(x!=y);
		if(!t){
			for(int k=1;k<=y;k++)
				ans[k][p[i]]=(x==y);
			continue;
		}
		if(y>=t-1){
			for(int k=1;k<=y-(t-1);k++)
				ans[m-k+1][p[i]]=(x==y);
			for(int k=1;k<=t-1;k++)
				ans[k][p[i]]=(x==y);
			t--;
		}
		else{
			s=std::min(s,m-y+1);
			for(int k=1;k<=y;k++)
				ans[s+k-1][p[i]]=(x==y);
			s++;
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			printf("%d",ans[i][j]);
		puts("");
	}
}