#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1000005;
int n,W,a[N],q[N];
ll b[N],c[N];
int main(){
	scanf("%d%d",&n,&W);
	For(i,1,n){
		int cnt;
		scanf("%d",&cnt);
		For(j,1,cnt) scanf("%d",&a[j]);
		if (2*cnt<=W){
			int mx=0;
			For(j,1,cnt){
				mx=max(mx,a[j]);
				b[j]+=mx;
			}
			mx=0;
			For(j,1,cnt){
				mx=max(mx,a[cnt-j+1]);
				b[W-j+1]+=mx;
			}
			c[cnt+1]+=mx;
			c[W-cnt+1]-=mx;
		}
		else{
			a[0]=0;
			For(j,cnt+1,W) a[j]=0;
			int h=0,t=1,len=W-cnt; q[1]=0;
			For(j,1,W){
				if (q[h+1]<j-len) ++h;
				for (;h<t&&a[q[t]]<=a[j];t--);
				q[++t]=j;
				//printf("%d ",q[h+1]);
				b[j]+=a[q[h+1]];
			}
		}
	}
	For(i,1,W){
		c[i]+=c[i-1];
		printf("%lld ",b[i]+c[i]);
	}
}