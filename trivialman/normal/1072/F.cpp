#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int INF = 1e9;
const int N = 1e6+10;

int p[N], id[N], dist[310][510], fac[15], p1[]={0,2,3,5,7,11,13,17,19,23};
int t,x,y,cnt=0,z;

int small(int x, int fac[], int &m){
	for(m=1;x>1;++m){
		int y=p[x];
		for(fac[m]=0;x%y==0;x/=y)++fac[m];
	}
	sort(fac+1,fac+m);--m;
	int res=1;
	rep(i,1,m)rep(j,1,fac[i])res*=p1[m+1-i];
	return res;
}

void getdist(int nfac, int fac[], int dist[]){
	rep(i,nfac+1,10)fac[i]=0;
	int x[510],y[510];
	rep(i,1,510)x[i]=INF;
	x[1]=0;
	rep(i,1,10){
		rep(j,1,500)y[j]=INF;
		rep(j,1,500)rep(k,1,500/j)y[j*k]=min(y[j*k],x[k]+abs(fac[i]-j+1));
		swap(x,y);
	}
	rep(i,1,500)dist[i]=x[i];
}

int main(){
	rep(i,1,1e6)p[i]=i;
	rep(i,2,1e6)if(p[i]==i){
		for(int j=i+i;j<=1e6;j+=i)p[j]=i; 
	}
	rep(i,1,1e6){
		int nfac;
		x = small(i, fac, nfac);
		if(x==i){
			id[i]=++cnt;
			getdist(nfac,fac,dist[cnt]);
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		int ans = INF;
		x = small(x, fac, z); y = small(y, fac, z);
		rep(i,1,500) ans = min(ans, dist[id[x]][i]+dist[id[y]][i]);
		printf("%d\n",ans);
	}
}