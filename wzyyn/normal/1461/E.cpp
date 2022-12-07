#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

bool CMP(ll a,ll b,ll c){
	if (c<0) return 1;
	if (!a) return 0;
	return b>c/a;
}
ll k,l,r,t,x,y;
bool vis[1000005];
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);
	if (y<=x){
		if (k+y>r) k-=x,t--;
		if (CMP(x-y,t,k-l)) puts("No");
		else puts("Yes");
		return 0;
	}
	for (;;){
		//cout<<k<<' '<<l<<' '<<r<<' '<<t<<' '<<x<<' '<<y<<endl;
		if (vis[k%x])
			return puts("Yes"),0;
		vis[k%x]=1;
		ll rem=0;
		if (k+y<=r) rem=0;
		if (!CMP(x,t,k-l))
			return puts("Yes"),0;
		else rem=(k-(r-y)+x-1)/x;
		//cout<<rem<<endl;
		if (CMP(x,rem,k-l))
			return puts("No"),0;
		t-=rem; k-=rem*x;
		if (!t) return puts("Yes"),0;
		t--; k+=y-x;
		if (!t) return puts("Yes"),0;
	}
}