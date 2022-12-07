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
const int N=50005;
int n,a[N],b[N],S;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		b[i]=(a[i]-(a[i]&1))/2;
		S+=b[i];
	}
	For(i,1,n)
		if ((a[i]&1)&&S)
			++b[i],++S;
	For(i,1,n)
		printf("%d\n",b[i]);
	puts("");
}