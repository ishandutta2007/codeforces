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
pii a[200005];
pii vis[5000005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
	sort(a+1,a+n+1);
	for(int i=4;i<=n;i++){
		if(a[i].fi==a[i-1].fi&&a[i].fi==a[i-2].fi&&a[i].fi==a[i-3].fi&&a[i].fi==a[i-4].fi){
			printf("YES\n");
			printf("%d %d %d %d\n",a[i].se,a[i-1].se,a[i-2].se,a[i-3].se);
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int val=a[i].fi+a[j].fi;
			if(vis[val].fi&&a[i].se!=vis[val].fi&&a[i].se!=vis[val].se&&a[j].se!=vis[val].fi&&a[j].se!=vis[val].se){
				printf("YES\n");
				printf("%d %d %d %d\n",a[i].se,a[j].se,vis[val].fi,vis[val].se);
				return 0;
			}
			vis[val]=mp(a[i].se,a[j].se);
		}
	}
	printf("NO\n");
	return 0;
}