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

int main(){
	int T=readint();
	while(T--){
		n=readint();
		int max1=0,max2=0;
		for(int i=1;i<=n;i++){
			int x=readint();
			if(x>max1) max2=max1,max1=x;
			else chkmax(max2,x);
		}
		printf("%d\n",max1+max2);
	}
	return 0;
}