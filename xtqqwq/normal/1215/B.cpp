#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,ans;
ll a[200005],cnt[20];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint()>0?0:1;
	for(int i=1;i<=n;i++) a[i]^=a[i-1];
	cnt[0]++;
	for(int i=1;i<=n;i++){
		ans+=cnt[a[i]];
		cnt[a[i]]++;
	}
	cout<<1ll*n*(n+1)/2-ans<<' '<<ans<<endl;
	return 0;
}