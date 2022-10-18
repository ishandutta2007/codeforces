#include<cstdio>
#include<algorithm>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 100005

int T;

int n;

inline int qry(int a,int b,int c){
	printf("? %d %d %d\n",a,b,c);
	fflush(stdout);
	static int res;
	scanf("%d",&res);
	return res;
}

std::vector<int> ver[N];

int p[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int a=0,b=0;
		for(int i=1;i<=13;i++)
			for(int j=i+1;j<=13;j++)
				for(int k=j+1;k<=13;k++)
					if(qry(i,j,k)<=(n-4)/6)
						a=i,b=j;
		int mx=0;
		for(int i=1;i<=n;i++)
			ver[i].clear();
		for(int i=1;i<=n;i++)
			if(i!=a&&i!=b){
				int tmp=qry(a,b,i);
				mx=std::max(mx,tmp);
				ver[tmp].push_back(i);
			}
		int x=ver[mx][0],y=ver[mx-1][0];
		if(ver[mx-1].size()>1&&qry(x,a,y)>qry(x,a,ver[mx-1][1]))
			y=ver[mx-1][1];
		p[x]=1,p[y]=2;
		for(int i=1;i<=n;i++)
			if(i!=x&&i!=y)
				p[i]=qry(x,y,i)+2;
		if(p[1]>p[2])
			for(int i=1;i<=n;i++)
				p[i]=n-p[i]+1;
		printf("! ");
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		puts("");
		fflush(stdout);
		int res;
		scanf("%d",&res);
	}
}