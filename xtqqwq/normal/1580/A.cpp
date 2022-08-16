#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
char s[405][405];
int a[405][405],sum[405];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=s[i][j]=='1';
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]+=a[i][j-1];
		int ans=1<<30;
		for(int i=1;i<=m;i++){
			for(int j=i+3;j<=m;j++){
				for(int k=1;k<=n;k++) sum[k]=a[k][j-1]-a[k][i]+(s[k][i]=='0')+(s[k][j]=='0');
				for(int k=1;k<=n;k++) sum[k]+=sum[k-1];
				int mina=1<<30;
				for(int k=1;k<=n;k++){
					int tmp=j-i-1-(a[k][j-1]-a[k][i]);
					chkmin(ans,mina+sum[k-1]+tmp);
					if(k-3>=1) chkmin(mina,j-i-1-a[k-3][j-1]+a[k-3][i]-sum[k-3]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}