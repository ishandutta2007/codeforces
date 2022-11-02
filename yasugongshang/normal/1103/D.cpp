#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1000005,MM=11;
const ll inf=1e15;
ll pr[100],f[100],F[MM+2][1<<MM|2],G[MM+2][1<<MM|2];
ll a[N];
int m,b[N];
vector<int> ycl[1<<MM|2];
map<ll,vector<int> > M;
vector<int> dd[N];
inline bool cmp(int x,int y){
	return b[x]<b[y];
}
void gb(vector<int> &a,vector<int> &b){
	vector<int> c(a.size()+b.size()); 
	merge(a.begin(),a.end(),b.begin(),b.end(),c.begin(),cmp);
	/*for(auto i:a)wri(i); puts("");
	for(auto i:b)wri(i); puts("");
	for(auto i:c)wri(i); puts("");*/
	swap(a,c);
}
signed main(){
	int n=read(); ll k=read(),t=0;
	
	for(int i=1;i<=n;i++)t=__gcd(t,a[i]=read());
	for(int i=1;i<=n;i++)b[i]=read();
	for(ll i=2;i*i<=t;i++)if(t%i==0){
		pr[m++]=i;
		while(t%i==0)t/=i;
	}
	if(t>1)pr[m++]=t;
	if(m==0){
		puts("0"); return 0;
	}
	for(int i=1;i<=n;i++){
		ll zs=a[i];
		for(int j=0;j<m;j++)while(zs%pr[j]==0)zs/=pr[j];
		a[i]=a[i]/zs;
		M[a[i]].push_back(i);
	}
	for(auto &i:M){
		sort(i.second.begin(),i.second.end(),cmp); if(i.second.size()>m)i.second.resize(m);
		ll zs=i.first;
		for(int i=0;i<m;i++){
			f[i]=1; while(zs/f[i]%pr[i]==0)f[i]*=pr[i]; 
		}
		for(int j=1;j<(1<<m);j++){
			ll s=1;
			for(int k=0;k<m;k++)if(j>>k&1)s*=f[k];
			if(s<=k){gb(ycl[j],i.second); if(ycl[j].size()>m)ycl[j].resize(m);}
		}
	}
	for(int i=1;i<(1<<m);i++){
		for(auto j:ycl[i])dd[j].push_back(i);
	}
	for(int i=0;i<=m;i++){
		for(int j=1;j<(1<<m);j++)F[i][j]=G[i][j]=inf;
	}
	for(int i=1;i<=n;i++){
		for(auto j:dd[i]){
			for(int k=1;k<=m;k++){
				int zt=((1<<m)-1)^j;
				for(int l=zt;;l=(l-1)&zt){
					G[k][l|j]=min(G[k][l|j],F[k-1][l]+b[i]);
					if(l==0)break;
				}
			}
		}
		for(auto j:dd[i]){
			for(int k=1;k<=m;k++){
				int zt=((1<<m)-1)^j;
				for(int l=zt;;l=(l-1)&zt){
					F[k][l|j]=G[k][l|j];
					if(l==0)break;
				}
			}
		}
	}
	ll ans=inf;
	for(int i=1;i<=m;i++)ans=min(ans,F[i][(1<<m)-1]*i);
	if(ans==inf)puts("-1"); else cout<<ans<<endl;
}