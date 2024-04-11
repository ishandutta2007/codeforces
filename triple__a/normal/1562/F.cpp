#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int maxn=107;
// const int mod=1e9+7;
int n;
int a[maxn][maxn],ans[100007];
vi small[370];
 
mt19937 rng(time(NULL)); // don't hack, pls!
 
int query(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	int u;
	cin>>u;
    // u=x*y/__gcd(x,y);
	return u;
}
 
void solve_brute(){
	int mx=0;
	for (int i=1;i<=n;++i){
		for (int j=1;j<i;++j){
			a[i][j]=a[j][i]=query(i,j);
			mx=max(mx,a[i][j]);
		}
	}
	int r=(sqrt(4*mx+1)+1)/2, l=r-n+1;
// 	cout<<l<<" "<<r<<endl;
	for (int i=l;i<=r;++i){
		map<int,int> hii;
		hii.clear();
		for (int j=l;j<=r;++j){
			if (j==i) continue;
			hii[i*j/__gcd(i,j)]++;
		}
		for (int j=1;j<=n;++j){
			map<int,int> tmp;
			tmp.clear();
			for (int k=1;k<=n;++k){
				if (j==k) continue;
				tmp[a[j][k]]++;
			}
			bool ok=1;
			for (auto c:hii){
				if (tmp[c.F]!=c.S) ok=0; 
			}
			if (ok) ans[j]=i;
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;++i) cout<<ans[i]<<" ";
	cout<<endl;
 
}
struct expower{
    ull mod_mul(ull a,ull b,ull M) {
        ll ret=a*b-M*ull(ld(a)* ld(b)/ld(M));
        return ret+M*(ret<0)-M*(ret>=(ll)M);
    }
    ull mod_pow(ull b,ull e,ull mod) {
        ull ans=1;
        for (; e; b=mod_mul(b,b,mod), e/=2)
            if (e&1) ans=mod_mul(ans,b,mod);
        return ans%mod;
    }
}expower;
 
 
bool is_prime(ull n){ 
    if (n<2||n%6%4!=1) return n-2<2;
    ull A[]={2,325,9375,28178,450775,9780504,1795265022},
    s=__builtin_ctzll(n-1), d = n >> s;
    for (auto a:A){
        ull p=expower.mod_pow(a,d,n),i=s;
        while (p!=1&&p!=n-1&&a%n&&i--)
            p=expower.mod_mul(p,p,n);
        if (p!=n-1&&i!=s) return 0;
    }
    return 1;
}
 
void solve_smart(){
	int mx=-1, cx=0, cy=0;
	for (int i=1;i<=1000;++i){
		int x=rng()%n, y=rng()%n;
		while (x==y) x=rng()%n, y=rng()%n;
		x++, y++;
		int ret=query(x,y);
		if (ret>mx) cx=x, cy=y, mx=ret;
	}
	int mxprime=-1, pos=-1;
	for (int i=1;i<=1650;++i){
		int x=rng()%n+1;
		while (x==cx||x==cy) x=rng()%n+1;
		int ret1=query(cx,x), ret2=query(cy,x);
		__int128_t ans=ret1;
		ans=ans*ret2;
		int sqr=ans/mx, pm=sqrt(sqr);
		if (pm*pm!=sqr||!is_prime(pm)) continue;
		if (mxprime<pm) mxprime=pm, pos=x;
	}
	if (mxprime==-1){
		while (1){
			cout<<":(";
		}
	}
	// cout<<mxprime<<endl;
	ans[pos]=mxprime;
	for (int i=1;i<=350;++i) small[i].clear();
	for (int i=1;i<=n;++i){
		if (i==pos) continue;
		int x=query(i,pos);
		ans[i]=x/mxprime;
// 		cout<<i<<" "<<x<<endl;
		if (ans[i]<=350){
			small[ans[i]].pb(i);
		}
	}
	int mxpos=-1;
	for (int i=1;i<=n;++i){
		if (i==pos) continue;
		if (mxpos==-1||ans[mxpos]<ans[i]) mxpos=i;
	}
	assert(mxpos!=-1);
	for (int i=1;i<=350;++i){
		if (sz(small[i])>=3){
			while (1){
				cout<<":(";
			}
		}
		for (auto c:small[i]){
		    if (c==mxpos) continue;
			int q=query(c,mxpos);
			if (__gcd(q,mxprime)==mxprime) ans[c]*=mxprime;
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;++i) cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _;
	cin>>_;
    // _=1;
	while (_--){
		cin>>n;
        // n=100;
		if (n<=100) solve_brute();
		else solve_smart();
	}
	return 0;
}