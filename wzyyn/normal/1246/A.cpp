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
#define y1 fdhjksa
using namespace std;
int n,p,ans;
int main(){
	ans=1<<30;
	scanf("%d%d",&n,&p);
	For(i,0,30){
		int nn=n-i*p;
		if (nn<0) continue;
		int sum=0;
		For(j,0,30)
			sum+=(nn>>j)&1;
		if (nn>=i&&sum<=i)
			return printf("%d\n",i),0;
	}
	puts("-1");
}