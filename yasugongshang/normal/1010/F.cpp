#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define poly vector<int>
#define mp make_pair
#define PI pair<int,poly>
inline ll read(){
	ll x=0; bool pos=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')pos=0;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return pos?x:-x;
}
const int N=1<<18|2,M=N;
const int mod=998244353,G=3;
int sz[N],dep[N];
vector<int> v[N];
inline int ksm(int a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=(ll)ans*a%mod;
		a=(ll)a*a%mod;
	}
	return ans;
}
struct ffter{
	int wn[N],rev[N];
	void init(int n){
		int t=1,L=0;
		while(t<n){
			t<<=1; L++;
		}
		int w=ksm(G,(mod-1)/n);
		for(int i=wn[0]=1;i<n;i++){
			wn[i]=(ll)wn[i-1]*w%mod; rev[i]=rev[i>>1]>>1|((i&1)<<(L-1));
		}
	}
	void zheng(poly &a){
		for(auto &i:a)i=(i+mod)%mod;
	}
	void dft(poly &a){
		int n=a.size();
		zheng(a);
		for(int i=0;i<n;i++)if(rev[i]<i)swap(a[rev[i]],a[i]);
		//for(int i=0;i<n;i++)cout<<rev[i]<<" "<<i<<endl;
		for(int i=1;i<n;i<<=1){
			for(int j=0;j<n;j+=i<<1){
				for(int k=j,l=0;l<i;k++,l++){
					ll t=(ll)wn[l*(n/(i<<1))]*a[k+i]%mod;
					//cout<<l*(n/i)<<" "<<l<<" "<<(n/i)<<" "<<k<<" "<<k+i<<endl;
					a[k+i]=(a[k]<t)?a[k]-t+mod:a[k]-t; 
					a[k]=a[k]+t>=mod?a[k]+t-mod:a[k]+t;
				}
			}
		}
	}/*wn[i]=WN[i<<len]*/
	void idft(poly &a){
		int n=a.size();
		dft(a);
		reverse(a.begin()+1,a.end());
		int zs=ksm(n,mod-2);
		for(auto &i:a)i=(ll)i*zs%mod;
		//for(int i=0;i<n;i++)if(rev[i]<i)swap(a[rev[i]],a[i]);
	}
}T;
void FFT(poly &a,poly &b){
	int n=a.size()+b.size()-1;
	int len=1; while(len<n)len<<=1;
	T.init(len);
	a.resize(len); b.resize(len);
	T.dft(a); T.dft(b);
	for(int i=0;i<len;i++)a[i]=(ll)a[i]*b[i]%mod;
	T.idft(a);
	a.resize(n);
}
int n,son[N];
poly tr[M],Tr[M],dp[N],f[N];
void solve(int p);
void zy(poly &a,int len){
	a.resize(a.size()+len);
	for(int i=a.size()-1;i>=len;i--)a[i]=a[i-len]; for(int i=0;i<len;i++)a[i]=0;
}
void bao(int p,int son){
	for(auto i:v[p])if(dep[i]>dep[p]&&i!=son)solve(i);
}
poly get(int p,int son){
	priority_queue<PI> q; while(q.size())q.pop();
	for(auto i:v[p])if(dep[i]>dep[p]&&i!=son){
		q.push(mp(-dp[i].size(),dp[i]));
	}
	if(q.size()==0){
		poly jb(1); jb[0]=1; return jb;
	}
	while(q.size()>1){
		poly a=q.top().second; q.pop(); poly b=q.top().second; q.pop();
		FFT(a,b);
		q.push(mp(-a.size(),a));
	}
	poly jb=q.top().second; q.pop();
	return jb;
}
poly operator +(poly a,poly b){
	if(a.size()<b.size())swap(a,b);
	for(unsigned i=0;i<b.size();i++)a[i]=(a[i]+b[i])%mod;
	return a;
}
int TOT;
void bao(int l,int r,int nod){
	if(l==r){
		tr[nod]=f[l];
		if(r==TOT){Tr[nod]=tr[nod]; zy(Tr[nod],1);} else Tr[nod].resize(1);
		Tr[nod][0]=1;
		return;
	}
	int mid=(l+r)>>1;
	bao(l,mid,nod<<1); bao(mid+1,r,nod<<1|1); 
	tr[nod]=tr[nod<<1]; FFT(tr[nod],tr[nod<<1|1]);
	FFT(Tr[nod<<1|1],tr[nod<<1]); zy(Tr[nod<<1|1],mid-l+1);
	Tr[nod]=Tr[nod<<1]+Tr[nod<<1|1];
}/*Tr[nod],tr[nod]Ai*/
void solve(int p){
	int tot=0,jb=0;
	for(int i=p;i;i=son[i])bao(i,son[i]);
	for(int i=p;i;i=son[i]){f[++tot]=get(i,son[i]);  }
	for(int i=1;i<=tot;i++)jb+=f[i].size();
	//cout<<jb<<" "<<sz[p]<<" "<<endl;
	//for(int i=1;i<tot;i++)cout<<f[i].size()<<" "; puts("");
	TOT=tot;
	bao(1,tot,1); 
	dp[p]=Tr[1]; 
	//for(auto i:Tr[1])cout<<(i+mod)%mod<<" "; puts("");
}
void init(int p,int fa){
	sz[p]=1; dep[p]=dep[fa]+1;
	for(auto i:v[p])if(i!=fa){
		init(i,p); sz[p]+=sz[i];
		if(sz[i]>sz[son[p]])son[p]=i;
	}
}
int main(){
	//freopen("sanrd.in","r",stdin); freopen("sanrd.out","w",stdout);
	n=read(); int x=read()%mod;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		v[x].push_back(y); v[y].push_back(x);
	}
	init(1,0);
	solve(1);
	poly ans=dp[1];
	ans[0]--;
	int dq=1,Ans=0; 
	for(int i=1;i<=n;i++){
		if(i>1)dq=(ll)dq*(i+x-1)%mod*ksm(i-1,mod-2)%mod;
		Ans=(Ans+(ll)dq*ans[i])%mod;
	}
	cout<<(Ans+mod)%mod<<endl;
}
/*
10 10
1 2
2 5
2 3
3 6
3 4
4 7
5 8
8 9
9 10
*/