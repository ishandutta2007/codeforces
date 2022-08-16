// xtqqwq
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

const int B=320,N=32000000;
int n,ans;
int a[100005],bk[64200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=-B;i<=B;i++){
		for(int j=1;j<=n;j++) bk[a[j]-j*i+N]++,chkmax(ans,bk[a[j]-j*i+N]);
		for(int j=1;j<=n;j++) bk[a[j]-j*i+N]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=min(n,i+B);j++) if((a[j]-a[i])%(j-i)==0) bk[(a[j]-a[i])/(j-i)+N]++,chkmax(ans,bk[(a[j]-a[i])/(j-i)+N]+1);
		for(int j=i+1;j<=min(n,i+B);j++) if((a[j]-a[i])%(j-i)==0) bk[(a[j]-a[i])/(j-i)+N]=0;
	}
	printf("%d\n",n-ans);
	return 0;
}