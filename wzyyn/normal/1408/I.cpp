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
const int N=1<<16|5;
const int mo=998244353;
int n,k,c;
int fac[20],inv[20];
int vis[N*2],f[N]; 
map<vector<int>,int> mp;
int cnt[65536];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,18) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,18) inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,18) fac[i]=1ll*fac[i-1]*i%mo;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void work(int *res,int st,int T){
	int a[20],b[20],c[20],d[20];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	For(i,0,k) a[i]=(st&(1<<i)?mo-1:1);
	For(i,0,k) a[i]=1ll*a[i]*inv[i]%mo;
	For(i,1,k) b[i-1]=1ll*a[i]*i*T%mo; 
	c[0]=d[0]=1;
	For(i,1,k){
		int sum=0;
		For(j,0,i-1) sum=(sum+1ll*b[j]*d[i-1-j])%mo;
		c[i]=1ll*sum*inv[i]%mo*fac[i-1]%mo;
		int rem=c[i];
		//cout<<rem<<' '<<d[j]<<endl;
		For(j,0,i-1) rem=(rem+mo-1ll*d[j]*a[i-j]%mo)%mo;
		//cout<<i<<' '<<rem<<' '<<sum<<endl;
		d[i]=rem;
	}
	//For(i,0,k) cout<<c[i]<<' '; cout<<"INFO "<<endl;
	//For(i,1,k) c[i]=1ll*c[i]*inv[i]%mo;
	memset(d,0,sizeof(d));
	For(i,0,k) For(j,0,k-i)
		d[i+j]=(d[i+j]+1ll*res[i]*c[j])%mo;
	For(i,0,k) res[i]=d[i];
}
/*
(a^T)'=a^(T-1)*a'T
*/
int main(){
	init();
	scanf("%d%d%d",&n,&k,&c);
	int S=(1<<c)-1,sum=0;
	For(i,1,n){
		int x;
		vector<int> tmp;
		scanf("%d",&x);
		For(j,0,k) tmp.push_back(x^(x-j));
		++mp[tmp]; sum^=x;
	}
	For(i,0,S)
		cnt[i]=cnt[i/2]+(i&1);
	For(i,0,S){
		static int q[200],num[200];
		*q=0; *vis=0;
		for (auto j:mp){
			int st=0;
			For(p,0,k) if (cnt[i&j.fi[p]]&1) st|=1<<p;
			if (!vis[st]) vis[st]=++*q,q[*q]=st;
			num[vis[st]]+=j.se;
		}
		int res[20];
		For(j,0,k) res[j]=(j==0);
		For(j,1,*q) work(res,q[j],num[j]);//cout<<i<<' '<<q[j]<<' '<<num[j]<<endl;
		f[i]=1ll*res[k]*fac[k]%mo;
		//cout<<f[i]<<' ';
		For(j,1,*q) num[j]=vis[q[j]]=0;
	}
	For(i,0,c-1) For(j,0,S)
		if (!(j&(1<<i))){
			//cout<<j<<' '<<(j^(1<<i))<<endl;
			int x=f[j],y=f[j^(1<<i)];
			f[j]=(x+y)*1ll*(mo+1)/2%mo;
			f[j^(1<<i)]=(x+mo-y)*1ll*(mo+1)/2%mo;
		}
	int key=power(n,mo-1-k);
	For(j,0,S)
		printf("%d ",f[sum^j]*1ll*key%mo);
}
/*
65536
*/