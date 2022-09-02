#include<cstdio>
#include<algorithm>
int n,p,res,a[50],b[50],pos[50];
void dfs(int u,int x,int sum){
	if(u>n){
		if(x==0&&sum%p==0&&*b>0){
			puts("Yes");
			printf("%d\n",*b);
			for(int i=1;i<=*b;++i)printf("%d ",b[i]);
			std::exit(0);
		}
		return;
	}
	dfs(u+1,x,sum);
	b[++*b]=pos[u];
	dfs(u+1,x^a[u],a[u]<10?(sum*10+a[u])%p:(sum*100+a[u])%p);
	--*b;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1,j=1;i<=n;++i,++j){
		int x;scanf("%d",&x);
		if(x>24){--i;--n;continue;}
		a[i]=x,pos[i]=j;
	}
	dfs(1,0,0);
	puts("No");
	return 0;
}