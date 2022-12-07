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
const int mo=1000000007;
int n,m;
char s[1005];
ll a[1005];
int f[1005][1005];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%s",s+1);
		For(j,1,n)
			if (s[j]=='1')
				a[j]|=1ll<<i;
	}
	f[1][1]=1;
	For(i,2,1000) For(j,1,i)
		f[i][j]=(1ll*j*f[i-1][j]+f[i-1][j-1])%mo;
	sort(a+1,a+n+1);
	int la=1,ans=1;
	For(i,2,n+1)
		if (a[i]==a[i-1]&&i!=n+1) ++la;
		else{
			int s=0;
			For(j,1,la) s=(s+f[la][j])%mo;
			ans=1ll*ans*s%mo;
			la=1;
		}
	cout<<ans<<endl;
}