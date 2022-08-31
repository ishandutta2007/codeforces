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

int x,y;

int main(){
	int T=readint();
	while(T--){
		x=readint(); y=readint();
		if(x==y) printf("%d\n",x);
		else if(x>y) printf("%d\n",x+y);
		else{
			int tmp=y/x;
			if(!(tmp&1)) tmp--;
			printf("%lld\n",(y+1ll*tmp*x)/2);
		}
	}
	return 0;
}