#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
char s[1000005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		scanf("%s",s+1);
		int x=0,y=0,mnx=0,mxx=0,mny=0,mxy=0;
		for(int i=1;i<=strlen(s+1);i++){
			if(s[i]=='U') x--;
			if(s[i]=='D') x++;
			if(s[i]=='L') y--;
			if(s[i]=='R') y++;
			int dx=max(mxx,x)-min(mnx,x);
			int dy=max(mxy,y)-min(mny,y);
			if(dx>=n||dy>=m) break;
			mnx=min(mnx,x); mxx=max(mxx,x);
			mny=min(mny,y); mxy=max(mxy,y);
		}
		printf("%d %d\n",-mnx+1,-mny+1);
	}
	return 0;
}