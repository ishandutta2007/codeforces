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
char s[200005];
int la[5];
double F(double ang,int n){
	double v1=0,v2=0,mx=0;
	For(i,1,n) v1+=sin(acos(-1)/n*i-ang);
	For(i,1,n) mx=max(mx,v2+=cos(acos(-1)/n*i-ang));
	return max(v1,2*mx-v2);
}
void solve(){
	int n;
	scanf("%d",&n);
	double L=0,R=acos(-1)/n;
	For(T,1,50){
		double mid=(L+R)/2;
		if (F(L,n)>F(R,n)) L=mid;
		else R=mid;
	}
	printf("%.10lf\n",F((L+R)/2,n));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}