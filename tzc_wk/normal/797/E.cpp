#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int SQRT=316;
int n,qu,a[MAXN+5],blk_sz,ans[SQRT+2][MAXN+5];
int main(){
	scanf("%d",&n);blk_sz=(int)pow(n,0.5);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=blk_sz;i++) for(int j=n;j;j--){
		if(a[j]+j+i>n) ans[i][j]=1;
		else ans[i][j]=ans[i][a[j]+j+i]+1;
	} scanf("%d",&qu);
	while(qu--){
		int p,k;scanf("%d%d",&p,&k);
		if(k<=blk_sz) printf("%d\n",ans[k][p]);
		else{
			int ret=0;
			while(p<=n) ret++,p=p+a[p]+k;
			printf("%d\n",ret);
		}
	}
	return 0;
}