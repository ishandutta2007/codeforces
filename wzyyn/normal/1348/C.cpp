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
int n,k,cnt[30];
char s[100005];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,0,25) cnt[i]=0;
	scanf("%s",s+1);
	For(i,1,n) ++cnt[s[i]-'a'];
	bool flg=0;
	int rem=n;
	For(i,0,25) if (cnt[i]){
		if (cnt[i]>k||flg){
			if (cnt[i]==rem) cnt[i]=(cnt[i]/k)+(cnt[i]%k!=0);
			else if (!flg) cnt[i]-=k-1;
			For(j,i,25) For(k,1,cnt[j]) putchar('a'+j);
			break;
		}
		else if (cnt[i]<k){
			int rem=k,las=i;
			For(j,i,25) if (cnt[j]&&rem>0)
				rem-=cnt[j],las=j;
			putchar(las+'a');
			break;
		}
		else
			putchar(i+'a');
		flg=1; rem-=cnt[i];
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}