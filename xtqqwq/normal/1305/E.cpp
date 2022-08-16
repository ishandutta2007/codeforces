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

int n,m,ncnt;
int ans[5005];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++){
		if(m<=(i-1)/2){
			ans[i]=i-1+i-m*2;
			for(int j=i+1;j<=n;j++) ans[j]=1e9-(n-j)*(n*10+1);
			m=0;
			break;
		}
		else ans[i]=i,m-=(i-1)/2;
	}
	if(m>0) return printf("-1\n"),0;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}