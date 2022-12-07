#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
const int mo=1000000007;
int n,a[N];
long long s;

int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int rate=1,ss=1;
	for (int i=2;i<=n;i++){
		if (a[i]==a[i-1])
			++ss;
		else
			ss=1;
		rate=1ll*rate*power(ss,mo-2)%mo;
	}
	
	for (int i=1;i<=n;i++)
		s+=a[i];
	if (s%n){
		puts("0");
		return 0;
	}
	
	s/=n;
	int s0=0,s1=0,s2=0;
	for (int i=1;i<=n;i++)
		if (a[i]<s) ++s0;
		else if (a[i]==s) ++s1;
		else ++s2;
	
	if (s0<=1||s2<=1){
		int ans=1;
		for (int i=1;i<=n;i++)
			ans=1ll*ans*i%mo;
		printf("%d\n",1ll*ans*rate%mo);
	}
	else{
		int ans=2;
		for (int i=1;i<=s2;i++)
			ans=1ll*ans*i%mo;
		for (int i=1;i<=s0;i++)
			ans=1ll*ans*i%mo;
		for (int i=1;i<=s1;i++)
			ans=1ll*ans*(s0+s2+i)%mo;
		printf("%d\n",1ll*ans*rate%mo);
	}
}