#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
int t[N],fl[N],n,C,D;
ll ans;
char s[N];
int main(){
	scanf("%d%d%d",&n,&C,&D);
	For(i,1,n){
		scanf("%d%s",&t[i],s+1);
		t[i]*=C; fl[i]=(s[1]=='P');
	}
	scanf("%d",&t[n+1]);
	t[n+1]*=C; fl[n+1]=-1;
	ll ans=1ll*D*n,s=0;
	int las=t[n+1];
	Rep(i,n,1){
		if (fl[i]==fl[i+1])
			s+=min(D,las-t[i+1]);
		else{
			s+=las-t[i+1];
			las=t[i+1];
		}
		ans=min(ans,las-t[i]+1ll*D*(i-1)+s);
	}
	printf("%lld\n",ans);
}