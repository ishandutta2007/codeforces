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
int n,a[20],ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) For(j,0,4) if (i+(1<<j)-1<=n&&(i-1)%(1<<j)==0){
		int flag=0;
		For(k,i+1,i+(1<<j)-1) if (a[k]<a[k-1]) flag=1;
		if (!flag) ans=max(ans,1<<j);
	}
	printf("%d\n",ans);
}