#include<cstdio>
#define N 1005

int n,p[N],q[N];

bool vis[N];

int f[N],s,t;

int a[N][N];

int main(){
	scanf("%d",&n);
	bool flg=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]!=i)
			flg=0;
		q[p[i]]=i;
	}
	if(flg){
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				putchar('.');
			puts("");
		}
		return 0;
	}
	for(int x=q[n];x!=n;x=q[x]){
		vis[x]=1;
		s++;
	}
	for(int x=n,y=q[x];s;s--,x=y,y=q[x]){
		if(x<y)
			a[s][x]=a[s][y]=-1;
		else
			a[s][x]=a[s][y]=1;
	}
	t=n;
	for(int i=1;i<n;i++)
		if(!vis[i]){
			if(p[i]==i)
				continue;
			f[i]=a[t][i]=1;
			for(int x=i,y=p[x];;x=y,y=p[x]){
				vis[x]=1;
				if(y>x){
					if(f[x]==1)
						f[y]=a[t][y]=1;
					else{
						a[t--][i]=-1;
						f[y]=a[t][i]=a[t][y]=1;
					}
				}
				else{
					if(f[x]==-1)
						f[y]=a[t][y]=-1;
					else{
						a[t--][n]=1;
						f[y]=a[t][n]=a[t][y]=-1;
					}
				}
				if(y==i)
					break;
			}
						t--;
		}
	printf("%d\n",n-1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			putchar(a[i][j]?(a[i][j]==1?'/':'\\'):'.');
		puts("");
	}
}