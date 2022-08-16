#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353,B=330;
int n;
int a[100005],d[100005][331],f[100005][331];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(a[i],B);j++){
				int k=(a[i]+j-1)/j;
				d[i][j]=(d[i-1][min(a[i-1],a[i]/k)]+1ll*i*(k-1))%cys;
			}
			for(int k=1;k<=min(a[i],B);k++){
				int val=a[i]/k;
				if(i==1) f[i][k]=k-1;
				else{
					int t=(a[i-1]+val-1)/val;
					if(val<=B) f[i][k]=(d[i-1][min(val,a[i-1])]+1ll*i*(k-1))%cys;
					else f[i][k]=(f[i-1][t]+1ll*i*(k-1))%cys;
				}
//				cout<<"test "<<i<<' '<<k<<' '<<f[i][k]<<endl;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans=(ans+f[i][1])%cys;
		printf("%lld\n",ans);
	}
	return 0;
}