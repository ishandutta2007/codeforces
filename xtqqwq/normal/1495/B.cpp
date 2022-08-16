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

int n;
int a[100005],b[100005],c[100005],tb[100005],tc[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	b[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) b[i]=b[i-1]+1;
		else b[i]=1;
	}
	c[n]=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]) c[i]=c[i+1]+1;
		else c[i]=1;
	}
	tb[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]) tb[i]=tb[i-1]+1;
		else tb[i]=1;
	}
	tc[n]=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]) tc[i]=tc[i+1]+1;
		else tc[i]=1;
	}
	int maxa=0;
	for(int i=1;i<=n;i++) chkmax(maxa,max(b[i],c[i]));
	vector<int> vb(0),vc(0);
	for(int i=1;i<=n;i++) if(tb[i]==maxa) vb.pb(i);
	for(int i=1;i<=n;i++) if(tc[i]==maxa) vc.pb(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]==c[i]&&b[i]==maxa&&b[i]%2==1){
			if(vb.size()==1&&vc.size()==1) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}