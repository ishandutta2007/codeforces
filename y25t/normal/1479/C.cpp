#include<cstdio>
#include<vector>
#define N 32

int L,R;

int n;
bool f,flg[N];

struct Edge{
	int u,v,w;
};
std::vector<Edge> ans;

int main(){
	scanf("%d%d",&L,&R);
	if(L==1){
		f=1;
		L++;
	}
	int d=R-L+1;
	n=2;
	for(int i=0;i<=29;i++)
		if(d&(1<<i)){
			flg[i+2]=1;
			n=i+3;
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<i;j++)
			ans.push_back((Edge){j,i,j==1?1:(1<<(j-2))});
	if(f)
		ans.push_back((Edge){1,n,1});
	for(int i=1,tmp=L-1;i<n;i++)
		if(flg[i]){
			ans.push_back((Edge){i,n,tmp});
			tmp+=1<<(i-2);
		}
	puts("YES");
	printf("%d %d\n",n,ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].w);
}