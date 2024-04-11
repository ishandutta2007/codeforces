#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
const int L=20;
int n,a[N],cnt[N][L],jmp[N][L],pref[N];
int Xor(int l,int r){return pref[r]^pref[l-1];}
int And(int l,int r){int ans=0;for(int i=0;i<L;i++)if(cnt[r][i]-cnt[l-1][i]==r-l+1)ans+=(1<<i);return ans;}
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		pref[i]=pref[i-1]^a[i];
		for(int j=0;j<L;j++)cnt[i][j]=cnt[i-1][j]+((a[i]&(1<<j))>0?1:0);
	}
	for(int i=n;i>=1;i--)for(int j=0;j<L;j++){
		if(i==n||!(a[i+1]&(1<<j)))jmp[i][j]=i;
		else jmp[i][j]=jmp[i+1][j];
	}
	int ans=0;
	for(int j=0;j<L;j++)for(int i=1;i<=n;i++)if(a[i]&(1<<j)){
		int nxt=jmp[i][j];
		if(nxt%2==i%2)nxt--;
		for(int ch=-6;ch<=0;ch+=2)if(nxt+ch>=i&&nxt+ch<=n&&And(i,nxt+ch)>Xor(i,nxt+ch))ans=max(ans,nxt+ch-i+1);
	}
	printf("%i",ans);
	return 0;
}