#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;
int n;
ll k,f[105];
void solve(){
	scanf("%d%lld",&n,&k);
	if (n<=62&&k>(1ll<<(n-1))) puts("-1");
	else{
		int p=max(n-62,1);
		For(i,1,p-1) printf("%d ",i);
		for (;p<=n;){
			int l=p;
			for (;;)
				if ((1ll<<max(0,n-l-1))>=k){
					Rep(i,l,p) printf("%d ",i);
					p=l+1; break;
				}
				else k-=1ll<<max(0,n-l-1),++l;
		}	
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}