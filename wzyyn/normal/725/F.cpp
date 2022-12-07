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
int n,q[N];
ll ans;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a+b>c+d){
			ans+=a-b;
			ans+=c-d;
			q[++*q]=a+b;
			q[++*q]=c+d;
		}
		else if (a>d) ans+=2*(a-d);
		else if (b>c) ans-=2*(b-c);
	}
	sort(q+1,q+*q+1);
	reverse(q+1,q+*q+1);
	For(i,1,*q) i&1?ans+=q[i]:ans-=q[i];
	printf("%lld",ans/2); 
}