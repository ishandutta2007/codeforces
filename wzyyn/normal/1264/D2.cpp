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
const int mo=998244353;
const int N=1000005;
char s[N];
int n,ans;
int fac[N],inv[N];
int S1[N],S2[N];
int c[N],b[N],a[N];
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,n) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo;
	For(i,1,n) a[i]=a[i-1]+(s[i]=='?');
	For(i,1,n) b[i]=b[i-1]+(s[i]=='(');
	For(i,1,n) c[i]=c[i-1]+(s[i]==')');
	For(i,0,n) S1[i+1]=(S1[i]+C(a[n],i))%mo;
	For(i,0,n) S2[i+1]=(S2[i]+C(a[n]-1,i))%mo;
	For(i,1,n) if (s[i]!=')'){
		int sum=b[i-1]+1-(c[n]-c[i])-(a[n]-a[i]);
		ans=(ans+(s[i]=='?'?S2[max(-sum+1,0)]:S1[max(-sum+1,0)]))%mo;
	}
	printf("%d\n",ans);
}