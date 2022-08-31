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

const int cys=998244353;
int n;
ll d[1000005],s[1000005];

int main(){
	n=readint();
	d[0]=s[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+i;j<=n;j+=i)
			d[j]++;
	for(int i=1;i<=n;i++){
		d[i]=(d[i]+s[i-1])%cys;
		s[i]=(s[i-1]+d[i])%cys;
	}
	printf("%lld\n",d[n]);
	return 0;
}