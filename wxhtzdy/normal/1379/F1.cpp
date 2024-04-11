#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmin(T&x,T y){return x>y?x=y,1:0;}
template<typename T> bool chkmax(T&x,T y){return x<y?x=y,1:0;}

int n,m,q,x[200005],y[200005],b[400005];

bool check(int t){
	for(int i=1;i<=2*m;i++) b[i]=1e9;
	for(int i=1;i<=t;i++) if(x[i]%2==1) b[y[i]]=min(b[y[i]],x[i]);
	for(int i=2;i<=2*m;i++) b[i]=min(b[i],b[i-1]);
	for(int i=1;i<=t;i++) if(x[i]%2==0&&b[y[i]]<=x[i]) return false;
	return true;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++) scanf("%d%d",&x[i],&y[i]);
	int l=1,r=q,p=0;
	while(l<=r){
		int m=(l+r)/2;
		if(check(m)) p=m,l=m+1; else r=m-1;
	}
	for(int i=1;i<=q;i++) puts(i<=p?"YES":"NO");
	return 0;
}