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
const int N=200005;
int n,a[N],ban[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (a[i]<a[i-1]||a[i]>i) return puts("-1"),0;
	For(i,1,n) ban[a[i]]=1;
	int pos=0;
	For(i,1,n)
		if (a[i]!=a[i-1]) cout<<a[i-1]<<' ',ban[a[i-1]]=1;
		else{
			for (;ban[pos];++pos);
			cout<<pos<<' '; ban[pos]=1;
		}
}