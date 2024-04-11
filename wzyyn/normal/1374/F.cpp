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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=505;
int n,a[N],op[N*N],top;
void OPT(int x){
	assert(x<=n-2);
	swap(a[x],a[x+1]);
	swap(a[x],a[x+2]);
	op[++top]=x;
}
void SWAP(int x){
	OPT(x+1); OPT(x);
}
void mian(){
	top=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-3){
		int mnp=i;
		For(j,i+1,n) if (a[j]<a[mnp]) mnp=j;
		for (;mnp-2>=i;OPT(mnp-=2));
		if (mnp!=i) SWAP(i);
	}
	for (;a[n-2]>min(a[n-1],a[n]);OPT(n-2));
	if (a[n-1]>a[n]){
		if (a[n-2]!=a[n-1]&&a[n-1]!=a[n]&&a[n-2]!=a[n]){
			int p=-1;
			For(i,1,n-3) if (a[i]==a[i+1]) p=i;
			if (p==-1) return puts("-1"),void(0);
			for (;p+3<=n;SWAP(p),p+=2);
			for (;a[n-2]>min(a[n-1],a[n]);OPT(n-2));
		}
		else{
			int tmp=0;
			for (;(a[n-1]<a[n-2]||a[n]<a[n-1])&&tmp<=3;++tmp) OPT(n-2);
			if (a[n-1]<a[n-2]||a[n]<a[n-1]) return puts("-1"),void(0);
		}
	}
	//cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
	printf("%d\n",top);
	For(i,1,top) printf("%d ",op[i]);
	puts("");
	//For(i,1,n) cout<<a[i]<<' '; cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}