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
const int N=2000005;
char s[N],t[N];
int l[N],n,m;
void manacher(){
	int p1=1,p2=1; l[1]=0;
	
	For(i,2,m-1){
		int v=(i>p2?0:min(l[2*p1-i],p2-i));
		for (;t[i-v]==t[i+v];++v);
		l[i]=--v;
		if (i+l[i]>=p2) p2=i+l[i],p1=i;
	}
	t[m+1]=0;
	/*printf("%s\n",t+1);
	For(i,1,m) printf("%d ",l[i]);
	puts("");*/
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1); m=0;
	For(i,1,n){
		t[++m]='#';
		t[++m]=s[i];
	}
	t[++m]='@';
	t[1]='!';
	manacher();
	int len=1;
	int alen=0,al=0,ar=0;
	for (;len<=n&&s[len]==s[n-len+1];++len);
	--len;
	//cout<<len<<endl;
	if (len>=n){
		printf("%s\n",s+1);
		return;
	}
	For(i,2,m-1){
		int pl=(i-l[i]+1)/2;
		int pr=(i+l[i])/2;
		//cout<<pl<<' '<<pr<<endl;
		if (pl>pr) continue;
		if (pl<=len+1){
			int nl=pr,nr=n-pl+2;
			if (nl+(n-nr+1)>=alen&&nl<nr)
				alen=nl+(n-nr+1),al=nl,ar=nr;
		}
		if (pr>=n-len){
			int nr=pl,nl=n-pr;
			if (nl+(n-nr+1)>=alen&&nl<nr)
				alen=nl+(n-nr+1),al=nl,ar=nr;
		}
		
		//cout<<alen<<' '<<al<<' '<<ar<<endl;
	}
	For(i,1,n)
		if (i<=al||i>=ar)
			putchar(s[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}