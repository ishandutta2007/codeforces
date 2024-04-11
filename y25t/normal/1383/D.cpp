#include<cstdio>
#include<algorithm>
#include<vector>
#define N 255

int n,m,a[N][N];

bool r[N*N],c[N*N];

std::vector<int> u,v;

int ans[N][N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=1;j<=m;j++)
			tmp=std::max(tmp,a[i][j]);
		r[tmp]=1;
	}
	for(int i=1;i<=m;i++){
		int tmp=0;
		for(int j=1;j<=n;j++)
			tmp=std::max(tmp,a[j][i]);
		c[tmp]=1;
	}
	for(int i=1;i<=n*m;i++)
		if(r[i]||c[i])
			u.push_back(i);
		else
			v.push_back(i);
	std::sort(u.begin(),u.end());
	std::sort(v.begin(),v.end());
	for(int i=u.size()-1,x=0,y=0;i>=0;i--){
		if(r[u[i]])
			x++;
		if(c[u[i]])
			y++;
		ans[x][y]=u[i];
		if(r[u[i]])
			for(int j=y-1;j;j--){
				ans[x][j]=v.back();
				v.pop_back();
			}
		if(c[u[i]])
			for(int j=x-1;j;j--){
				ans[j][y]=v.back();
				v.pop_back();
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
}