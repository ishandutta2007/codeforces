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
const int N=1000005;
int n,m;
int cnt[8],a[N];
int f[2][8];
char s[N];
int main(){
	scanf("%d%d",&n,&m);
	if (min(n,m)>=4) return puts("-1"),0;
	if (min(n,m)==1) return puts("0"),0;
	cnt[0]=0; cnt[1]=1; cnt[2]=1; cnt[3]=2;
	cnt[4]=1; cnt[5]=2; cnt[6]=2; cnt[7]=3;
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m) if (s[j]=='1')
			if (n<m) a[j]|=1<<(i-1);
			else a[i]|=(1<<(j-1));
	}
	//cout<<a[1]<<' '<<a[2]<<' '<<a[3]<<endl;
	if (n>m) swap(n,m);
	int pre=0,suf=1;
	For(i,0,(1<<n)-1) f[pre][i]=cnt[a[1]^i];
	For(i,2,m){
		memset(f[suf],30,sizeof(f[suf]));
		For(j,0,(1<<n)-1) For(k,0,(1<<n)-1){
			if ((cnt[j&3]+cnt[k&3])%2==0) continue;
			if ((cnt[j&6]+cnt[k&6])%2==0&&n==3) continue;
			f[suf][k]=min(f[suf][k],f[pre][j]+cnt[a[i]^k]);
		}
		swap(pre,suf);
		//For(j,0,(1<<n)-1) cout<<f[pre][j]<<' '; cout<<endl;
	}
	int ans=1<<30;
	For(i,0,(1<<n)-1) ans=min(ans,f[pre][i]);
	cout<<ans<<endl;
}