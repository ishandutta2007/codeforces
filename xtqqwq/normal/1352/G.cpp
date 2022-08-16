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

int main(){
	int T=readint();
	while(T--){
		n=readint();
		if(n==1){
			printf("1\n");
			continue;
		}
		if(n<=3){
			printf("-1\n");
			continue;
		}
		if(n==4){
			printf("3 1 4 2\n");
			continue;
		}
		if(!(n&1)){
			for(int i=1;i<=n;i+=2) printf("%d ",i);
			printf("%d %d %d ",n-4,n,n-2);
			for(int i=n-6;i>=1;i-=2) printf("%d ",i);
			printf("\n");
		}
		else{
			for(int i=1;i<=n;i+=2) printf("%d ",i);
			printf("%d %d ",n-3,n-1);
			for(int i=n-5;i>=1;i-=2) printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}