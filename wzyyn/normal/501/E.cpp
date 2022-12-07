#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,a[N],lim[N],sum[N],ans;
void count(int l,int r){
	For(i,1,n) lim[i]=sum[i];
	int len=r-l+1;
	For(i,1,len/2)
		if ((lim[a[r-i+1]]-=2)<0) return;
		else ++ans;
	if (len&1)
		if (--lim[a[r-len/2]]<0) return;
		else ++ans;
	Rep(i,len/2,1)
		if (a[l+i-1]!=a[r-i+1]) return;
		else ++ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int l=1,r=n,cnt=0;
	for (;l<=r&&a[l]==a[r];++l,--r);
	if (l>r) return printf("%lld\n",1ll*n*(n+1)/2),0;
	For(i,l,r) sum[a[i]]++;
	For(i,1,n) cnt+=(sum[i]&1);
	if (cnt>=2) return puts("0"),0;
	count(l,r);
	reverse(a+l,a+r+1);
	count(l,r);
	//if (1ll*(ans+1)*l==180850) cout<<ans<<' '<<l<<endl;
	printf("%lld\n",1ll*ans*l+1ll*l*l);
}
/*
7
2 3 3 3 3 2 3
*/