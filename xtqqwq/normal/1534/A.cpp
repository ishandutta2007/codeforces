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
char s[55][55],ans[55][55];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int pl=-1,fl=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]!='.'){
					int tmp=(s[i][j]=='R')^(i&1)^(j&1);
					if(pl<0) pl=tmp;
					else if(pl!=tmp) fl=1;
				}
			}
		}
		if(fl){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(pl<0) pl=0;
		for(int i=1;i<=n;i++) ans[i][m+1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(((i&1)^(j&1))==pl) ans[i][j]='W';
				else ans[i][j]='R';
			}
		}
		for(int i=1;i<=n;i++) puts(ans[i]+1);
	}
	return 0;
}