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
const int N=1005;
int n,m,c;
int a[N],b[N];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	For(i,1,n) a[i]=c+1,b[i]=0;
	a[0]=0; b[n+1]=c+1;
	int p1=0,p2=n+1;
	For(i,1,m){
		int x;
		scanf("%d",&x);
		if (x<=c/2){
			int p=1;
			for (;p<=p1&&a[p]<=x;++p);
			p1=max(p1,p); a[p]=x;
			cout<<p<<endl;
		}
		else{
			int p=n;
			for (;p>=p2&&b[p]>=x;p--);
			p2=min(p2,p); b[p]=x;
			cout<<p<<endl;
		}
		if (p1+1==p2)
			return 0;
	}
	assert(0);
}