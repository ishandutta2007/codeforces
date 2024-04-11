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
const int N=200005;
int n,m;
ull s1[N];
map<ull,ll> mp1,mp2;
int s2[N];
ll ans;
ull RND(){
	static ull A=43214621742181ull;
	static ull B=78197483241297ull;
	A^=(A<<1)^(B>>18);
	B^=(B>>7)^(A<<21);
	return A^B;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		int l,r;
		scanf("%d%d",&l,&r);
		ull tmp=RND();
		s1[l+1]^=tmp; s1[r+1]^=tmp;
		s2[l]++; s2[r+1]--;
	}
	For(i,1,m+1) s2[i]+=s2[i-1];
	For(i,1,m+1) s1[i]^=s1[i-1];
	For(i,1,m+1) s1[i]^=s1[i-1];
	For(i,1,m){
		++mp1[s1[i]];
		mp2[s1[i]]+=i-1;
		ans-=1ll*mp2[s1[i]];
		ans+=1ll*mp1[s1[i]]*i;
	}
	int l=0;
	For(i,1,m+1)
		if (i==m+1||s2[i]){
			For(j,1,l) ans-=1ll*j*(l-j+1);
			l=0;
		}
		else ++l;
	printf("%lld\n",ans);
}