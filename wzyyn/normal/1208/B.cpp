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
const int N=2005;
int n,ans,a[N],b[N],cnt[N];
int main(){
	ans=1<<30;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	For(i,1,n) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	For(i,0,n){
		bool flag=0;
		For(j,1,n) cnt[j]=0;
		For(j,1,i) if (++cnt[a[j]]==2) flag=1;
		if (flag) break;
		int pr=n;
		for (;pr>0;pr--)
			if (++cnt[a[pr]]==2){
				ans=min(ans,pr-i);
				break;
			}
	}
	printf("%d\n",ans);
}