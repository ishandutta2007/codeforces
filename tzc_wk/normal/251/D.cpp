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
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXB=63+2;
int n;ll a[MAXN],s=0;
bitset<MAXN> bt[MAXB];
int hi[MAXN],pos[MAXN],cur=0,ans[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),s^=a[i];
	for(int i=62;~i;i--) if(!(s>>i&1)){
		++cur;
		for(int j=1;j<=n;j++) if((a[j]>>i)&1) bt[cur][j]=1;
		bt[cur][n+1]=1;
//		for(int j=1;j<=n;j++) printf("%d ",(int)bt[cur][j]);printf("\n");
		for(int j=1;j<cur;j++) if(bt[cur][hi[j]]) bt[cur]^=bt[j];
		for(int j=1;j<=n;j++) if(bt[cur][j]){hi[cur]=j;break;}
//		for(int j=1;j<=n;j++) printf("%d ",(int)bt[cur][j]);printf("\n");
//		printf("%d\n",hi[cur]);
		if(!hi[cur]){bt[cur].reset();cur--;continue;}
		for(int j=1;j<cur;j++){
			if(bt[j][hi[cur]]) bt[j]^=bt[cur];
		}
	}
	for(int i=62;~i;i--) if(s>>i&1){
		++cur;
		for(int j=1;j<=n;j++) if((a[j]>>i)&1) bt[cur][j]=1;
		bt[cur][n+1]=0;
//		for(int j=1;j<=n;j++) printf("%d ",(int)bt[cur][j]);printf("\n");
		for(int j=1;j<cur;j++) if(bt[cur][hi[j]]) bt[cur]^=bt[j];
		for(int j=1;j<=n;j++) if(bt[cur][j]){hi[cur]=j;break;}
//		for(int j=1;j<=n;j++) printf("%d ",(int)bt[cur][j]);printf("\n");
//		printf("%d\n",hi[cur]);
		if(!hi[cur]){bt[cur].reset();cur--;continue;}
		for(int j=1;j<cur;j++){
			if(bt[j][hi[cur]]) bt[j]^=bt[cur];
		}
	}
	for(int i=1;i<=cur;i++) ans[hi[i]]=bt[i][n+1];
	for(int i=1;i<=n;i++) printf("%d ",2-ans[i]);
	return 0;
}
//