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

int n,c[10005];
ll a[1000005];
ll b[10005],ans;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int rnd(){
	int x=0;
	For(i,1,9) x=x*10+rand()%10;
	return x;
}
void check(int x){
	*b=0;
	for (int i=1;1ll*i*i<=a[x];i++)
		if (a[x]%i==0){
			b[++*b]=i;
			b[++*b]=a[x]/i;
		}
	sort(b+1,b+*b+1);
	*b=unique(b+1,b+*b+1)-b-1;
	memset(c,0,sizeof(c));
	For(i,1,n) ++c[lower_bound(b+1,b+*b+1,gcd(a[x],a[i]))-b];
	Rep(i,*b,1) if (ans<b[i]){
		int sum=0;
		For(j,i,*b) if (b[j]%b[i]==0) sum+=c[j];
		if (sum*2>=n){
			ans=max(ans,b[i]);
			break;
		}
	}
}
int main(){
	srand(time(NULL));
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,10) check(rnd()%n+1);
	printf("%lld\n",ans);
}