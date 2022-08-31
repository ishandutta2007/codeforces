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
bool vis[1005];

int main(){
	n=readint();
	int mina=1<<30,x=0;
	for(int i=1;i<=n;i++) if(chkmin(mina,(n-1)/i+i)) x=i;
	if(n<=3) return printf("0\n"),0;
	while(1){
		vector<int> now(0);
		for(int i=1;i<n;i++){
			if(!vis[i]&&i%x!=0) vis[i]=1,now.pb(i);
			if(now.size()==x) break;
		}
		if(now.size()<x) return printf("0\n"),0;
		printf("%d ",now.size());
		for(auto r:now) printf("%d ",r);
		printf("\n");
		fflush(stdout);
		int tmp=readint();
		for(int i=tmp;i<=tmp+now.size()-1;i++) vis[(i-1)%n+1]=0;
	}
	return 0;
}