#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int vis[5005],n,x;
void solve(){
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	For(i,2,n){
		printf("? %d 1\n",i-1);
		For(j,1,i) printf("%d%c",j,j>=i-1?'\n':' ');
		fflush(stdout);
		scanf("%d",&x);
		if (x){
			int l=1,r=i-1;
			while (l<r){
				int mid=(l+r)/2;
				printf("? %d 1\n",mid-l+1);
				For(j,l,mid) printf("%d%c",j,j==mid?'\n':' ');
				printf("%d\n",i);
				fflush(stdout);
				scanf("%d",&x);
				if (x) r=mid;
				else l=mid+1;
			}
			vis[l]=vis[i]=1;
			For(j,i+1,n){
				printf("? 1 1\n%d\n%d\n",i,j);
				fflush(stdout);
				scanf("%d",&x);
				if (x) vis[j]=1;
			}
			break;
		}
	}
	int s=0;
	For(i,1,n) s+=(!vis[i]);
	printf("! %d ",s);
	For(i,1,n) if (!vis[i]) printf("%d ",i);
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}