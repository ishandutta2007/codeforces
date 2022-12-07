#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=200005;
int n,a[N];
int pr[N],su[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	pr[0]=0; su[n+1]=0;
	For(i,1,n) pr[i]=(pr[i-1]<0?-1:a[i]-pr[i-1]);
	Rep(i,n,1) su[i]=(su[i+1]<0?-1:a[i]-su[i+1]);
	if (pr[n]==0) puts("YES");
	else{
		For(i,1,n-1)
			if (pr[i-1]>=0&&su[i+2]>=0)
				if (pr[i-1]+a[i]==su[i+2]+a[i+1])
					if (pr[i-1]<=a[i+1]&&su[i+2]<=a[i])
						return puts("YES"),void(0);
		puts("NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}