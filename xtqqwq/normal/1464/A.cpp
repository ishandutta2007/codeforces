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
int a[100005],vis[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=vis[i]=0;
		int ans=0,x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			a[x]=y;
			if(x!=y) ans++;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]||a[i]==i) continue;
			vis[i]=1;
			bool fl=1;
			for(int j=a[i];j!=i;j=a[j]){
				if(!j){
					fl=0;
					break;
				}
				vis[j]=1;
			}
			if(fl) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}