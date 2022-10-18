#include<cstdio>
#include<algorithm>
#define N 20005
#define K 31
#define W 15

int n,m;

int a[N];

int lg[N],mx[N][W];
inline int mxx(int x,int y){
	return x+a[x]>y+a[y]?x:y;
}
inline int qry(int x,int y){
	int k=lg[y-x+1];
	return mxx(mx[x][k],mx[y-(1<<k)+1][k]);
}

int f[N][K][W];

int s[K],t[K];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		mx[i][0]=i;
	for(int j=1;j<W;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
			mx[i][j]=mxx(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<K;j++)
			f[i][j][0]=std::min(n,i+a[i]+j);
	for(int j=1;j<W;j++)
		for(int i=1;i<=n;i++)
			for(int x=0;x<K;x++)
				for(int y=0;x+y<K;y++)
					f[i][x+y][j]=std::max(f[i][x+y][j],f[qry(i,f[i][x][j-1])][y][j-1]);
	while(m--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(l==r){
			puts("0");
			continue;
		}
		for(int i=0;i<=k;i++)
			s[i]=t[i]=l;
		int ans=0;
		for(int j=W-1;j>=0;j--){
			for(int i=0;i<=k;i++)
				t[i]=s[i];
			for(int x=0;x<=k;x++)
				for(int y=0;x+y<=k;y++)
					t[x+y]=std::max(t[x+y],f[qry(l,s[x])][y][j]);
			bool flg=0;
			for(int i=0;i<=k;i++)
				if(t[i]>=r)
					flg=1;
			if(flg)
				continue;
			ans+=(1<<j);
			for(int i=0;i<=k;i++)
				s[i]=t[i];
		}
		printf("%d\n",ans+1);
	}
}