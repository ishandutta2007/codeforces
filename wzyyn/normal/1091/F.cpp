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
const int N=100005;
int n;
ll L[N];
char s[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&L[i]);
	scanf("%s",s+1);
	bool flag=0;
	ll T=0,MP=0,grass=0;
	For(i,1,n){
		if (s[i]=='L'){
			T+=L[i]; MP-=L[i];
			if (MP<0) T-=(flag?3:5)*MP,MP=0;
		}
		else if (s[i]=='W')
			flag=1,MP+=L[i],T+=3*L[i];
		else MP+=L[i],T+=5*L[i],grass+=2*L[i];
		grass=min(grass,MP);
	}
	if (MP){
		T-=grass*2;
		T-=MP-grass;
	}
	printf("%lld\n",T);
}