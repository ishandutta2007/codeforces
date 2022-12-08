#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define Re(i,x) for (i=x.begin();i!=x.end();++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(i,a) for (int i=0;i<(int)a;++i)
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define POSIN(x,y) (x>=1&&x<=n&&y>=1&&y<=m)
#define clr(x) memset(x,0,sizeof x)
#define SZ(x) ((int)x.size())
#define TWO(x) (1<<(x))
#define mp make_pair
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
bool he[105];int pr[105],v[3000001],tot,L,R,p,n;
void dfs(int l,int x){
	if(l==0){v[++tot]=x;return;}
	for(;;){
		dfs(l-1,x);
		if(x>R/pr[l])break;
		x*=pr[l];
	}
}
bool can[3000010];int f[3000010],ans;
int main() {
	scanf("%d%d%d",&L,&R,&p);
	rep(i,2,p)for(int j=2;j*j<=i;++j)if(i%j==0)he[i]=1;
	rep(i,2,p)if(!he[i])pr[++n]=i;
	f[1]=0;dfs(n,1);sort(v+1,v+tot+1);can[1]=1;
	rep(i,2,tot)f[i]=100000000;
	rep(i,2,p){
		int l=1;
		rep(j,1,tot){
			while(l<tot && v[l]<v[j]*i)l++;
			if (v[l]==v[j]*i){
				f[l]=min(f[l],f[j]+1);
				if(f[l]+i<=p)can[l]=1;
			}
		}
	}
	rep(i,1,tot)if(v[i]>=L&&v[i]<=R&&can[i])++ans;
	printf("%d\n",ans);
	return 0;
}