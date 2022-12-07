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
ll a[5];
int main(){
	For(i,1,3)
		scanf("%lld",&a[i]);
	puts("First");
	int las=-1;
	for (;;){
		int imx=1,imn=1;
		For(i,2,3){
			if (a[i]>a[imx]) imx=i;
			if (a[i]<a[imn]) imn=i;
		}
		int imid=6-imx-imn;
		if (las==imx&&a[imx]-a[imid]==a[imid]-a[imn])
			return printf("%lld",a[imx]-a[imid]),0;
		ll v=3*max(max(a[1],a[2]),a[3])-a[1]-a[2]-a[3];
		cout<<v<<endl;
		cin>>las;
		a[las]+=v;
	}
}
/*
a b c
2c-b-a

2c-b b c
*/