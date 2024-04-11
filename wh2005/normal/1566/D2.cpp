#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e3+9;
int T,n,m,a[N*N];

struct pp{int val,id;}p[N*N];
bool cmp(pp x,pp y){
	return x.val==y.val?(x.id<y.id):(x.val<y.val);
}

int b[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&a[(i-1)*m+j]);
		for(int i=1;i<=n*m;i++) p[i].val=a[i],p[i].id=i;
		ll ans=0;
		sort(p+1,p+n*m+1,cmp);
		for(int i=1;i<=n*m;i++) a[p[i].id]=i;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) b[i][j]=0;
		for(int i=1;i<=n*m;i++){
			int x=(a[i]-1)/m+1;int y=a[i]-m*(x-1);
//			printf("%d %d\n",x,y);
			for(int j=1;j<y;j++) ans+=b[x][j];
			b[x][y]=1;
		}
//		printf("%lld\n",ans);
		for(int l=1,r=1;l<=n*m;l=r+1){
			while(r<n*m&&p[r+1].val==p[l].val) ++r;
			ll cnt=0;
			for(int i=l;i<=r;i++){
				if(i!=l&&(i-1)%m==0) cnt=0;
				ans-=cnt;
				cnt++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}