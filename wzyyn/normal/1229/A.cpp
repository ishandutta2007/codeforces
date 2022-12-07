#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=7005;
int n,v[N];
ll a[N],b[N],q[N],ans;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]),b[i]=a[i];
	For(i,1,n) scanf("%d",&v[i]);
	sort(b+1,b+n+1);
	For(i,2,n) if (b[i]==b[i-1]) q[++*q]=b[i];
	For(i,1,n){
		bool flag=0;
		For(j,1,*q) if ((q[j]&a[i])==a[i])
			flag=1;
		if (flag) ans+=v[i];
	}
	printf("%lld\n",ans);
}