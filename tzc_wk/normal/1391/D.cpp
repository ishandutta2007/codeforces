#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read();
int a[1000005][4],dp[1000005][8];
signed main(){
	if(n>=4&&m>=4) return puts("-1"),0;
	if(n==1||m==1) return puts("0"),0;
	swap(n,m);
	fz(i,1,m) fz(j,1,n) scanf("%1d",&a[j][i]);
	fillbig(dp);
	for(int i=0;i<(1<<m);i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			if((i>>(j-1)&1)!=a[1][j]) sum++;
		}
		dp[1][i]=sum;
	}
	fz(i,2,n){
		for(int s=0;s<(1<<m);s++){
			for(int t=0;t<(1<<m);t++){
				int p[4]={0},q[4]={0};
				fz(j,1,m) p[j]=(s>>(j-1)&1);
				fz(j,1,m) q[j]=(t>>(j-1)&1);
				bool flg=1;
				fz(j,1,m-1){
					int sum=p[j]+q[j]+p[j+1]+q[j+1];
					if(sum%2==0) flg=0;
				}
				if(!flg) continue;
				int sum=0;
				fz(j,1,m) sum+=(p[j]!=a[i][j]);
				dp[i][s]=min(dp[i][s],dp[i-1][t]+sum);
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<(1<<m);i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}