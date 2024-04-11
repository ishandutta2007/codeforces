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
const int N=400005;
int a[N],lg[N],n,B;
int main(){
	scanf("%d%d",&n,&B);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) lg[i]=lg[i/2]+1;
	For(i,2,n) if ((1<<lg[i])<i) ++lg[i];
	sort(a+1,a+n+1);
	int l=1,cnt=0,ans=1<<30;
	For(r,1,n){
		if (r==1) cnt=1;
		else if (a[r]!=a[r-1]) ++cnt;
		for (;lg[cnt]*n>B*8;){
			if (l==r||a[l]!=a[l+1]) --cnt;
			++l;
		}
		ans=min(ans,n-(r-l+1));
	}
	printf("%d\n",ans);
}