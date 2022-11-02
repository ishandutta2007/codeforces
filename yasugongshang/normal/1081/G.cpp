#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
int ycl[N],tong[N],mod,inv;
void solve(int l,int r,int dep){
	if(l==r||dep==1){
		tong[r-l+1]++; return;
	}
	int mid=(l+r)>>1;
	solve(l,mid,dep-1); solve(mid+1,r,dep-1);
}
ll get(ll len){
	return len*(len-1)/2%mod*inv%mod;
}
inline ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int n,k;
ll get(ll a,ll b){
	if(a+b>n)return 0;
	ll ans=0;
	for(int i=1;i<=a;i++){
		ans=(ans+inv*b-ycl[i+b]+ycl[i])%mod; //cout<<a<<" "<<b<<" "<<inv*b<<" "<<ycl[i+b]-ycl[i]-ksm(3,mod-2)<<endl;
	}
//	cout<<ans<<" "<<ksm(2,mod-2)+ksm(3,mod-2)<<" "<<ycl[1+b]-ycl[1]<<endl;
	return (ans+mod)%mod;
}
int main(){
	cin>>n>>k>>mod; inv=(mod+1)/2;ycl[1]=1;
	for(int i=2;i<=n;i++)ycl[i]=mod-(ll)ycl[mod%i]*(mod/i)%mod;
	for(int i=2;i<=n;i++)ycl[i]=(ycl[i-1]+ycl[i])%mod;
	solve(1,n,k);
	//cout<<(get(1,2))%mod<<endl; return 0;
	for(int i=1;i<=n;i++)if(tong[i]){
		cout<<(get(i)*tong[i]+get(i+1)*tong[i+1]+get(i,i+1)*tong[i]%mod*tong[i+1]+
		tong[i]*(tong[i]-1)/2%mod*get(i,i)+tong[i+1]*(tong[i+1]-1)/2%mod*get(i+1,i+1))%mod<<endl;
		return 0;
	}
}
/*
1/2-1/(i+j)
*/