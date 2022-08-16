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

const int cys=1000000007;
int n;
int p[1000005],rem[5];
bool vis[1000005];
vector<int> v;

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int getans1(){
	int ans=0; bool fl=0;
	for(auto r:v){
		if(!fl&&r%3==1&&r>3){
			fl=1;
			ans+=r/3-1;
		}
		else{
			ans+=(r-1)/3;
			if(r%3) rem[r%3]++;
		}
	}
	if(!fl&&rem[2]>=2) rem[2]-=2,fl=1;
	if(!fl&&rem[2]>=1&&rem[1]>=2) ans++,rem[2]--,rem[1]-=2,fl=1;
	if(!fl&&rem[2]==0&&rem[1]>=4) ans+=2,rem[1]-=4,fl=1;
	if(!fl&&rem[1]==1) ans++,rem[1]=0,fl=1;
	int mina=min(rem[1],rem[2]);
	ans+=mina,rem[1]-=mina,rem[2]-=mina;
	ans+=rem[1]/3*2,rem[1]%=3;
	ans+=rem[2]/3*3,rem[2]%=3;
	return ans;
}

int getans2(){
	int ans=0; bool fl=0;
	for(auto r:v){
		ans+=(r-1)/3;
		if(r%3) rem[r%3]++;
	}
	if(!fl&&rem[2]>=2) rem[2]-=2,fl=1;
	if(!fl&&rem[2]>=1&&rem[1]>=2) ans++,rem[2]--,rem[1]-=2,fl=1;
	if(!fl&&rem[2]==0&&rem[1]>=4) ans+=2,rem[1]-=4,fl=1;
	if(!fl&&rem[1]==1) ans++,rem[1]=0,fl=1;
	int mina=min(rem[1],rem[2]);
	ans+=mina,rem[1]-=mina,rem[2]-=mina;
	ans+=rem[1]/3*2,rem[1]%=3;
	ans+=rem[2]/3*3,rem[2]%=3;
	return ans;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) p[i]=readint();
		int num=0;
		if(n%3==0) printf("%lld ",qpow(3,n/3)),num=0;
		else if(n%3==1) printf("%lld ",qpow(3,n/3-1)*4%cys),num=2;
		else printf("%lld ",qpow(3,n/3)*2%cys),num=1;
		v.clear();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
			int cnt=1;
			for(int j=p[i];j!=i;j=p[j]){
				vis[j]=1;
				cnt++;
			}
			v.pb(cnt);
		}
		rem[1]=rem[2]=0;
		if(!num){
			int ans=0;
			for(auto r:v){
				ans+=(r-1)/3;
				if(r%3) rem[r%3]++;
			}
			int mina=min(rem[1],rem[2]);
			ans+=mina,rem[1]-=mina,rem[2]-=mina;
			ans+=rem[1]/3*2,rem[1]%=3;
			ans+=rem[2]/3*3,rem[2]%=3;
			printf("%d\n",ans);
		}
		else if(num==1){
			int ans=0;
			for(auto r:v){
				ans+=(r-1)/3;
				if(r%3) rem[r%3]++;
			}
			int mina=min(rem[1],rem[2]);
			ans+=mina,rem[1]-=mina,rem[2]-=mina;
			ans+=rem[1]/3*2,rem[1]%=3;
			ans+=rem[2]/3*3,rem[2]%=3;
			if(rem[1]==2) ans++;
			printf("%d\n",ans);
		}
		else{
			printf("%d\n",min(getans1(),getans2()));
		}
	}
	return 0;
}