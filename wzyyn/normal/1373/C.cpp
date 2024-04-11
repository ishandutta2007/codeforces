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
const int N=1000005;
char s[N];
int las[N*2];
void mian(){
	scanf("%s",s+1);
	int v=N,mn=N,n=strlen(s+1);
	For(i,v-n,v) las[i]=0;
	For(i,1,n){
		s[i]=='-'?--v:++v;
		mn=min(mn,v);
		if (!las[v]&&v<N) las[v]=i;
	}
	ll ans=n;
	For(i,mn,N) ans+=las[i];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}