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
int n,k;
ll a[200005];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll ans1=0,ans2=1;
	for(int i=n-k+1;i<=n;i++) ans1+=i;
	int lst=-1;
	for(int i=1;i<=n;i++){
		if(a[i]>=n-k+1){
			if(lst==-1) lst=i;
			else{
				ans2=ans2*(i-lst)%cys;
				lst=i;
			}
		}
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}