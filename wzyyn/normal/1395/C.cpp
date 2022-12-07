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

const int N=205;
int n,m,a[N],b[N];
bool check(int v){
	For(i,1,n){
		int fl=0;
		For(j,1,m)
			if ((a[i]&b[j]&v)==(a[i]&b[j]))
				fl=1;
		if (!fl) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	int v=511;
	Rep(i,8,0) if (check(v-(1<<i))) v-=(1<<i);
	cout<<v<<endl;
}