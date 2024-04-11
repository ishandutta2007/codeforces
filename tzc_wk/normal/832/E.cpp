#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MAXM=500+5;
const int MAXN=500+5;
const int MAXQ=300+5;
const int MAXK=800+5;
const int P=5;
const int MOD=1e9+7;
int n,m,q,a[MAXN][MAXK];
int inv[P],ans=1;
char buf[MAXM];
int main(){
	for(int i=0;i<P;i++) inv[i]=i*i*i%P;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",buf+1);
		for(int j=1;j<=m;j++)
			a[j][i]=buf[j]-'a';
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%s",buf+1);
		for(int j=1;j<=m;j++)
			a[j][i+n]=buf[j]-'a';
	}
	int cur=1,r=0;
	for(int i=1;i<=m&&cur<=n;i++){
		while(cur<=n){
			int t=i;
			for(int j=i+1;j<=m;j++) if(a[j][cur]) t=j;
			for(int j=1;j<=n+q;j++) swap(a[i][j],a[t][j]);
			if(a[i][cur]) break;cur++;
		}
		if(cur==n+1) break;
		for(int j=cur+1;j<=n+q;j++) a[i][j]=a[i][j]*inv[a[i][cur]]%P;
		a[i][cur]=1;
		for(int j=i+1;j<=m;j++){
			for(int k=cur+1;k<=n+q;k++){
				a[j][k]-=a[j][cur]*a[i][k]%P;
				if(a[j][k]<0) a[j][k]+=P;
			} a[j][cur]=0;
		}
		r++;
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n+q;j++) printf("%d ",a[i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=n-r;i++) ans=ans*5ll%MOD;
	for(int i=1;i<=q;i++){
		int x=ans;
		for(int j=1;j<=m;j++){
			bool flg=1;
			for(int k=1;k<=n;k++) flg&=(a[j][k]==0);
			flg&=(a[j][n+i]>0);
			if(flg) x=0;
		}
		printf("%d\n",x);
	}
	return 0;
}