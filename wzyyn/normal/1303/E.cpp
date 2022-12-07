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
const int N=404;
char s[N],t[N];
int n,m,f[2][N][N];
void UPD(int &x,int y){
	x<y?x=y:233;
}
void solve(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	if (n<m) return puts("NO"),void(0);
	t[m+1]='z'+1;
	For(i,0,m+1) For(j,0,m+1)
		f[0][i][j]=f[1][i][j]=-1;
	For(i,1,m+1) f[0][1][i]=i;
	For(i,1,n){
		int now=(i&1),pre=now^1;
		For(j,1,m+1) For(k,j,m+1)
			if (f[pre][j][k]!=-1){
				int val=f[pre][j][k]; f[pre][j][k]=-1;
				//cout<<i-1<<' '<<j<<' '<<k<<' '<<val<<endl;
				UPD(f[now][j][k],val+(t[val]==s[i]));
				if (s[i]==t[j]&&j!=k) UPD(f[now][j+1][k],val);
			}
	}
	bool fl=0;
	For(i,1,m+1)
		if (f[n&1][i][i]==m+1)
			fl=1;
	puts(fl?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}
/*
f[i][j][k]
ijk 
*/