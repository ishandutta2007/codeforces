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
int p[4005],a[4005],d[4005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n+n;i++) p[i]=readint();
		for(int i=1;i<=n+n;i++) a[i]=max(a[i-1],p[i]);
		int lst=n+n+1;
		vector<int> v(0);
		for(int i=n+n;i>=1;i--){
			if(a[i]==p[i]){
				v.pb(lst-i);
				lst=i;
			}
		}
		memset(d,0,sizeof(d));
		d[0]=1;
		for(auto r:v)
			for(int i=n-r;i>=0;i--) d[i+r]|=d[i];
		if(d[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}