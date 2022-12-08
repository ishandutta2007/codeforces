#include<cstring>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define dep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
double f[1<<21];ll a[1<<21];
int n;char s[50][25];
int main() {
	scanf("%d",&n);rep(i,0,n)scanf("%s",s[i]);int m=strlen(s[0]);
	rep(i,0,n)rep(j,i+1,n){
		ll S=0;rep(k,0,m)if(s[i][k]==s[j][k])S|=1ll<<k;
		a[S]|=(ll)1<<i|(ll)1<<j;
	}
	dep(i,(1<<m)-1,0) {
		rep(j,0,m)if(i>>j&1)a[i^(1<<j)]|=a[i];
		int cnt=0;rep(j,0,m)if(!(i>>j&1))++cnt,f[i]+=f[i|(1<<j)];
		if(!cnt)continue;f[i]/=cnt;cnt=0;
		rep(j,0,n)if(a[i]>>j&1)++cnt;
		f[i]+=cnt/(double)n;
	}
	printf("%.9lf\n",f[0]);
	return 0;
}