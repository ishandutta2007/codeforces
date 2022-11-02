#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int mod=10007,N=205;
poly mo,X,F[N],G[N],a;
int mn,m,n,dp[2][N][N][N];
char s[N];
int ans1,ans2,sum[N][N],Sum[N][N],SUM[N][N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void mul(poly &a,poly &b){
	poly c(a.size()+b.size()-1);
	For(i,0,a.size()-1){
		For(j,0,b.size()-1){
			c[i+j]+=a[i]*b[j];
		}
	}
	for(auto &i:c)i%=mod;
	swap(a,c);
}
void mul(poly &a,poly b,poly &mo){
	poly c; swap(a,c);
	mul(c,b);
	ll inv=ksm(mo[mo.size()-1],mod-2);
	Rep(i,c.size()-1,mo.size()-1){
		c[i]=(c[i]%mod+mod)%mod; ll xs=c[i]*inv%mod;
		For(j,0,mo.size()-1){
			c[i-j]-=xs*mo[mo.size()-j-1]; 
		}
	}
	if(c.size()>mo.size())c.resize(mo.size());
	For(i,0,c.size()-1)c[i]=(c[i]%mod+mod)%mod;
	swap(a,c);
}
ll chu(int x,int y,int nn,int bo){
	if(nn<0)return 0;  
	poly dts=F[x]; mul(dts,G[y]); if(bo)mul(dts,a);
	For(i,1,dts.size()-1)dts[i]=mod-dts[i];
	int meiju=X.size()-1+nn-mn;
	static int dp[N<<1]; memset(dp,0,sizeof(dp));
	dp[0]=1;
	For(i,1,meiju){
		int me=min(i,(int)dts.size()-1);
		ll sum=0;
		For(j,1,me)sum+=dp[i-j]*dts[j];
		dp[i]=sum%mod;
	}
	ll ans=0;
	For(i,0,X.size()-1)ans+=X[i]*dp[i+nn-mn];
	//if(nn==mn)cout<<ans%mod<<endl;
	//for(auto i:dts)wri(i); puts("zygay");
	//cout<<nn<<" "<<X.size()-1<<" fjzzq"<<endl;
	//For(i,0,X.size()-1)cout<<dp[i+nn-mn]<<" "; puts("");
	//cout<<"zhu "<<ans<<" "<<x<<" "<<y<<" fjzqz "<<nn<<" "<<mn<<endl; //exit(0);
	return ans%mod;
}
bool check(int l,int r){
	return r>m||s[l]==s[r];
}
inline void add(int &a,int b){
	a=a+b>=mod?a+b-mod:a+b;
}
int main(){
	scanf("%s",s+1);
	m=strlen(s+1); n=read();
	dp[1][m][0][0]=1;
	For(i,1,m+1){int zyk=i&1;
		if(i<=m){
			Rep(j,m,i){
				int sum=i-1+m-j;
				For(k,0,sum)For(l,0,sum-k)if(dp[zyk][j][k][l]){
					int kk=k,LL=l; if(check(i,j+1))kk++; else LL++;
					if(j==m||s[i]!=s[j+1])add(dp[zyk^1][j][kk][LL],dp[zyk][j][k][l]);
					//cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j+1]<<" "<<dp[3][2][2][1]<<endl;
					if(s[i]!=s[j])add(dp[zyk][j-1][kk][LL],dp[zyk][j][k][l]);
					else add(dp[zyk^1][j-1][kk][LL],dp[zyk][j][k][l]);
				}
			}
		}
		For(k,0,m)For(l,0,m-k){
			if((m+n)&1){
				int kk=k,LL=l;
				if(check(i,i+1))kk++; else LL++;
				add(sum[kk][LL],dp[zyk][i][k][l]);
				//if(dp[i][i][k][l])cout<<i<<" "<<i<<" "<<k<<" "<<l<<" "<<dp[i][i][k][l]<<endl;
			}
			if(i>m){
				if((n+m)&1)dp[zyk][i-1][k][l]=dp[zyk][i-1][k][l]*26%mod;
				add(SUM[k][l],dp[zyk][i-1][k][l]); continue;
			}
			int kk=k+1,LL=l;
			//if(dp[i][i-1][k][l])cout<<dp[i][i-1][k][l]<<" "<<i<<" "<<i-1<<" "<<k<<" "<<l<<endl;
			if((n+m)&1)dp[zyk][i-1][k][l]=dp[zyk][i-1][k][l]*25%mod;//pan i>m
			add(Sum[kk][LL],dp[zyk][i-1][k][l]);
		}
		memset(dp[zyk],0,sizeof(dp[zyk]));
	}
	mo.pb(1); a.resize(2);
	For(i,0,m){
		a[0]=1; a[1]=mod-25;
		mul(mo,a);
		a[1]=mod-24;
		mul(mo,a);
	}
	poly zs; a[0]=1;  a[1]=mod-26; mul(mo,a);
	reverse(mo.begin(),mo.end());
	//for(auto i:mo)wri(i); puts("");
	//cout<<mo.size()<<endl;
	zs.pb(0); zs.pb(1); X.pb(1);
	mn=max(0,(n-m)/2);//puts("zhu");
	for(int b=mn;b;b>>=1){
		if(b&1)mul(X,zs,mo);
		mul(zs,zs,mo);
	}
	//For(i,0,m+1)For(j,0,m+1)if(Sum[i][j])cout<<i<<" "<<j<<" "<<Sum[i][j]<<endl;
	//For(i,0,m+1)For(j,0,m+1)if(sum[i][j])cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
	a[0]=1; a[1]=mod-25;
	F[0].pb(1); G[0]=F[0]; 
	For(i,1,m+1){F[i]=F[i-1]; mul(F[i],a);} a[1]=mod-24;
	For(i,1,m+1){G[i]=G[i-1]; mul(G[i],a);} a[1]=mod-26;
	For(i,0,m+1)For(j,0,m+1){
		if(Sum[i][j]&&n-(2*(i+j-1)-m)>=0){
			//cout<<Sum[i][j]<<" "<<i<<" "<<j<<" "<<chu(i,j,(n-(2*(i+j-1)-m))/2,0)<<" "<<(n-(2*(i+j-1)-m))/2<<endl;
			ans1=(ans1+Sum[i][j]*chu(i,j,(n-(2*(i+j-1)-m))/2,0))%mod;
		}
	}
	For(i,0,m+1)For(j,0,m+1){
		if(sum[i][j]&&n-(2*(i+j-1)-m-1)>=0){
			ans2=(ans2+sum[i][j]*chu(i,j,(n-(2*(i+j)-m-1))/2,0))%mod;
			//cout<<sum[i][j]<<" "<<i<<" "<<j<<" "<<chu(i,j,(n-(2*(i+j)-m-1))/2,0)<<endl;
		}
	}//cout<<ans2<<endl;
	For(i,0,m+1)For(j,0,m+1){
		if(SUM[i][j]&&n>=m){
			//cout<<i<<" zyy "<<j<<endl;
			ans2=(ans2+SUM[i][j]*chu(i,j,(n-m)/2,1))%mod;
			//cout<<sum[i][j]<<" "<<i<<" "<<j<<" "<<chu(i,j,(n-(2*(i+j)-m-1))/2)<<endl;
		}
	}
	//cout<<ans1<<" fjzzq "<<ans2<<endl;
	cout<<(ans1+ans2)%mod<<endl;
}
/*
bcabc
10


*/