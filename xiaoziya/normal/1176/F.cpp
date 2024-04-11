#include<stdio.h>
#include<vector>
#include<algorithm>
#define int long long
#define inf 1000000000000000
using namespace std;
const int maxn=200005,maxk=11;
int T,n,ans;
int s[7]={0,1,1,1,2,2,3},t[7],r[7],f[maxn][maxk];
vector<int>v[4];
inline int cmp(int a,int b){
	return a>b;
}
signed main(){
	scanf("%lld",&T);
	for(int i=1;i<=9;i++)
		f[0][i]=-inf;
	for(int w=1;w<=T;w++){
		v[1].clear(),v[2].clear(),v[3].clear(),v[1].push_back(-inf),v[1].push_back(-inf),v[1].push_back(-inf),v[2].push_back(-inf),v[3].push_back(-inf);
		scanf("%lld",&n);
		for(int i=1,x,y;i<=n;i++)
			scanf("%lld%lld",&x,&y),v[x].push_back(y);
		sort(v[1].begin(),v[1].end(),cmp),sort(v[2].begin(),v[2].end(),cmp),sort(v[3].begin(),v[3].end(),cmp);
		t[0]=0,t[1]=v[1][0],t[2]=v[2][0],t[3]=v[3][0];
		t[4]=v[1][0]+v[1][1],t[5]=v[1][0]+v[2][0],t[6]=v[1][0]+v[1][1]+v[1][2];
		r[0]=0,r[1]=v[1][0]*2,r[2]=v[2][0]*2,r[3]=v[3][0]*2;
		r[4]=v[1][0]*2+v[1][1],r[5]=max(v[1][0],v[2][0])+v[1][0]+v[2][0],r[6]=v[1][0]*2+v[1][1]+v[1][2];
		for(int i=0;i<10;i++)
			f[w][i]=f[w-1][i];
		for(int i=0;i<10;i++)
			if(f[w-1][i]!=-inf)
				for(int j=1;j<=6;j++)
					if(t[j]>=0){
						int nxt=(i+s[j])%10;
						f[w][nxt]=max(f[w][nxt],f[w-1][i]+((i+s[j]>=10)? r[j]:t[j]));
					}
		int res=0;
		for(int i=0;i<10;i++)
			res=max(res,f[w][i]);
	}
	for(int i=0;i<10;i++)
		ans=max(ans,f[T][i]);
	printf("%lld\n",ans);
	return 0;
}