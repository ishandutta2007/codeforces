#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10
#define M 105

int T;

int n,m,a[N][M];

int mx[M];

int id[M];
inline bool cmp(int x,int y){
	return mx[x]>mx[y];
}

int ans;

int solve(){
	memset(a,0,sizeof(a));
	memset(mx,0,sizeof(mx));
	memset(id,0,sizeof(id));
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			mx[j]=std::max(mx[j],a[i][j]);
		}
	for(int i=1;i<=m;i++)
		id[i]=i;
	std::sort(id+1,id+m+1,cmp);
	if(n==1)for(int i1=1;i1<=n;i1++){
		int tmp=0;
		for(int i=1;i<=n;i++){
			int ttmp=0;
			ttmp=std::max(ttmp,a[(i+i1)%n+1][id[1]]);
			tmp+=ttmp;
		}
		ans=std::max(ans,tmp);
	}
	if(n==2)for(int i1=1;i1<=n;i1++)for(int i2=1;i2<=n;i2++){
		int tmp=0;
		for(int i=1;i<=n;i++){
			int ttmp=0;
			ttmp=std::max(ttmp,a[(i+i1)%n+1][id[1]]);
			ttmp=std::max(ttmp,a[(i+i2)%n+1][id[2]]);
			tmp+=ttmp;
		}
		ans=std::max(ans,tmp);
	}
	if(n==3)for(int i1=1;i1<=n;i1++)for(int i2=1;i2<=n;i2++)for(int i3=1;i3<=n;i3++){
		int tmp=0;
		for(int i=1;i<=n;i++){
			int ttmp=0;
			ttmp=std::max(ttmp,a[(i+i1)%n+1][id[1]]);
			ttmp=std::max(ttmp,a[(i+i2)%n+1][id[2]]);
			ttmp=std::max(ttmp,a[(i+i3)%n+1][id[3]]);
			tmp+=ttmp;
		}
		ans=std::max(ans,tmp);
	}
	if(n==4)for(int i1=1;i1<=n;i1++)for(int i2=1;i2<=n;i2++)for(int i3=1;i3<=n;i3++)for(int i4=1;i4<=n;i4++){
		int tmp=0;
		for(int i=1;i<=n;i++){
			int ttmp=0;
			ttmp=std::max(ttmp,a[(i+i1)%n+1][id[1]]);
			ttmp=std::max(ttmp,a[(i+i2)%n+1][id[2]]);
			ttmp=std::max(ttmp,a[(i+i3)%n+1][id[3]]);
			ttmp=std::max(ttmp,a[(i+i4)%n+1][id[4]]);
			tmp+=ttmp;
		}
		ans=std::max(ans,tmp);
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--)
		solve();
}