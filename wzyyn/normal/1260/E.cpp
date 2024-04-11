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
int n,nn,a[300005];
priority_queue<int,vector<int>,greater<int> > Q;
ll ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (a[n]==-1) return puts("0"),0;
	ans=a[n]; nn=n/2; n--;
	for (;nn;nn>>=1){
		For(i,1,nn){
			if (a[n]>0) Q.push(a[n]);
			else For(j,1,20) Q.push(0);
			--n;
		}
		ans+=Q.top();
		Q.pop();
	}
	printf("%lld\n",ans);
}