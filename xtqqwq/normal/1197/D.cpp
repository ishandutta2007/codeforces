#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,k,ans;
ll a[300005],s[300005],cnt[10],b[10][300005],lb[10][300005];

ll ask(int l,int r){
	ll maxa=-1ll<<60;
	for(int i=l;i<=r;i++) maxa=max(maxa,s[i]);
	return maxa;
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),s[i]=s[i-1]+a[i];
	for(int i=0;i<m;i++){
		if(i) b[i][++cnt[i]]=s[i]-k,lb[i][cnt[i]]=ask(1,i)-k;
		int j=i;
		for(j=i;j+m<n;j+=m) b[i][++cnt[i]]=s[j+m]-s[j]-k,lb[i][cnt[i]]=ask(j+1,j+m)-k*cnt[i];
		b[i][++cnt[i]]=s[n]-s[j]-k,lb[i][cnt[i]]=ask(j+1,n)-k*cnt[i];
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<=cnt[i];j++) b[i][j]+=b[i][j-1];
		ll mina=0;
		for(int j=1;j<=cnt[i];j++){
			ans=max(ans,lb[i][j]-mina);
			mina=min(mina,b[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}