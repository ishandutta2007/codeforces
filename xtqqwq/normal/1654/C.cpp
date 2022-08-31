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

int n;
map<ll,int> bk;

bool dfs(ll x){
	if(!x) return false;
	if(!bk[x]){
		if(!dfs(x/2)||!dfs(x-x/2)) return false;
		return true;
	}
	bk[x]--;
	return true;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		bk.clear();
		ll sum=0;
		for(int i=1;i<=n;i++){
			int x=readint();
			bk[x]++; sum+=x;
		}
		if(!dfs(sum)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}