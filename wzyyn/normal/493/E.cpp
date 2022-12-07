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
ll x,y,z;
int main(){
	scanf("%lld%lld%lld",&x,&y,&z);
	if (x==1&&y==1&&z==1) return puts("inf"),0;
	if (x==y&&y==z) return puts("2"),0;
	if (y==z) return puts("1"),0;
	if (y==1) return puts("0"),0;
	ll Z=z,Y=y,fl=0;
	for (;Z;Z/=y,Y/=x)
		if ((Y-=Z%y)<0||Y%x) fl=1;
	//cout<<Z<<' '<<Y<<endl;
	if (!fl&&!Y) return puts("1"),0;
	if (x!=1) return puts("0"),0;
	if (z==1) return puts("0"),0;
	for (;z%y==0;z/=y);
	puts(z!=1?"0":"1");
}