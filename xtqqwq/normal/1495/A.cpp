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
typedef long double ld;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,n1,n2;
ll a[100005],b[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		n1=n2=0;
		int x,y;
		for(int i=1;i<=n+n;i++){
			x=readint(); y=readint();
			if(!x) a[++n1]=abs(y);
			else b[++n2]=abs(x);
		}
		sort(a+1,a+n1+1);
		sort(b+1,b+n2+1);
		ld ans=0;
		for(int i=1;i<=n1;i++) ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.10Lf\n",ans);
	}
	return 0;
}