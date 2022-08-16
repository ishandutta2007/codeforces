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
int a[100005],nxt[100005];
vector<pii> v;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	int num=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) v.pb(mp(a[i-1],num)),num=1;
		else num++;
	}
	v.pb(mp(a[n],num));
	for(int i=v.size()-1;i>=0;i--){
		nxt[i]=nxt[i+1];
		if(v[i].se>=2) nxt[i]=v[i].fi;
	}
	int now0=0,now1=0,ans=0;
	for(int i=0;i<v.size();i++){
		if(v[i].se>=2){
			if(now0!=v[i].fi) now0=v[i].fi,ans++;
			if(now1!=v[i].fi) now1=v[i].fi,ans++;
		}
		else{
			if(v[i].fi==nxt[i]){
				if(now0!=v[i].fi) now0=v[i].fi,ans++;
				else if(now1!=v[i].fi) now1=v[i].fi,ans++;
			}
			else{
				if(now0==nxt[i]) now0=v[i].fi,ans++;
				else if(now1==nxt[i]) now1=v[i].fi,ans++;
				else if(now0!=v[i].fi) now0=v[i].fi,ans++;
				else if(now1!=v[i].fi) now1=v[i].fi,ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}