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

int n,d;
int f[1005],siz[1005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint(); d=readint();
	for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	int x,y,cnt=0;
	for(int i=1;i<=d;i++){
		x=readint(); y=readint();
		int fx=getf(x),fy=getf(y);
		if(fx==fy) cnt++;
		else f[fx]=fy,siz[fy]+=siz[fx];
		vector<int> vec(0);
		for(int j=1;j<=n;j++) if(getf(j)==j) vec.pb(siz[j]);
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		if(cnt+1>vec.size()) printf("%d\n",i);
		else{
			int ans=0;
			for(int j=0;j<=cnt;j++) ans+=vec[j];
			printf("%d\n",ans-1);
		}
	}
	return 0;
}