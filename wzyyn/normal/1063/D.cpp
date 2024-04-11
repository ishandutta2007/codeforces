#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
ll n,l,r,k;
void BF1(){
	ll len=(r-l+1+n)%n;
	if (len==0) len=n;
	Rep(i,n,0){
		ll rem=(k-1)%(i+n)+1;
		if (rem>=len&&rem<=len+min(1ll*i,len))
			if (i+n-rem>=n-len&&i+n-rem<=n-len+min(1ll*i,n-len))
				return printf("%d\n",i),void(0);
		rem=(k)%(i+n)+1;
		if (rem>len&&rem<=len+min(1ll*i,len))
			if (i+n-rem>=n-len&&i+n-rem<=n-len+min(1ll*i,n-len))
				return printf("%d\n",i),void(0);
	}
	puts("-1");
}
void BF2(){
	ll ans=-1;
	ll len=(r-l+1+n)%n;
	if (len==0) len=n;
	if (k>=len&&k<=2*len) ans=min(len,k-len+1)+n-len;
	For(rnd,1,(k+1)/n){
		ll rem=k-len-rnd*n;
		//cout<<rnd<<' '<<len<<' '<<rem<<endl;
		if (rem>=0&&rem<=rnd*n+len){
			ll s1=rem%rnd,s2=rem/rnd-s1;
			//cout<<"WORK "<<s1<<' '<<s2<<endl;
			if (s2>n-len){
				ll T=s2-(n-len);
				T=(T+rnd)/(rnd+1);
				s1+=T*rnd; s2-=T*(rnd+1);
			}
			//cout<<"WORK "<<s1<<' '<<s2<<endl;
			if (s1>=0&&s2>=0&&s1<=len&&s2<=n-len)
				ans=max(ans,s1+s2);
		}
		++rem;
		if (rem>=0&&rem<=rnd*n+len){
			ll s1=rem%rnd,s2=rem/rnd-s1;
			if (s2>n-len){
				ll T=s2-(n-len);
				T=(T+rnd)/(rnd+1);
				s1+=T*rnd; s2-=T*(rnd+1);
			}
			if (s1>0&&s2>=0&&s1<=len&&s2<=n-len)
				ans=max(ans,s1+s2);
		}
	}
	printf("%lld\n",ans);
}
/*
a*(rnd+1)+b*rnd= v

*/
int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	//BF1(); BF2();
	k/n>=n?BF1():BF2();
}