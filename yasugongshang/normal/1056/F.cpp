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
const ld inf=1e100;
const int N=105;
int n;
pair<int,int> a[N];
ld dp[N][N][N*10];
ld f[N],c,T;
int main(){
	int Tc=read();
	for(int i=0;i<=10;i++)dp[0][1][i]=inf;
	while(Tc--){
		n=read();
		cin>>c>>T;
		for(int i=1;i<=n;i++){
			a[i].first=read(); a[i].second=read();
		}
		sort(&a[1],&a[n+1]);reverse(&a[1],&a[n+1]);
		f[0]=1;
		for(int i=1;i<=n;i++)f[i]=f[i-1]*0.9;
		for(int i=1;i<=n;i++){//cout<<a[i].first<<" cqz "<<a[i].second<<endl;
			for(int j=1;j<=i;j++){
				ld x=a[i].first/f[j];
				for(int k=0;k<a[i].second;k++)dp[i][j][k]=(i==j||k>(i-1)*10)?inf:dp[i-1][j][k];
				for(int k=a[i].second;k<=j*10;k++){
					if(j==i||k>j*10)dp[i][j][k]=(k-a[i].second>(j-1)*10)?inf:dp[i-1][j-1][k-a[i].second]+x;
					else dp[i][j][k]=min((k-a[i].second<=(j-1)*10)?(dp[i-1][j-1][k-a[i].second]+x):inf,dp[i-1][j][k]);
					//if(i==3&&j==1&&k==6)cout<<i<<" "<<j<<" "<<k<<" "<<dp[i-1][j-1][k-a[i].second]<<" "<<dp[i][j][k]<<" "<<dp[i-1][j][k]<<endl;
				}
			}
		}
		//cout<<dp[3][1][6]<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int k=0;k<=i*10;k++){
				ld TT=dp[n][i][k]; if(TT>=inf)continue;
				ld l=0,r=T,mn=inf; 
				for(int i=1;i<=100;i++){
					ld len=(r-l)/3;
					ld lmid=l+len,rmid=r-len;
					ld ans1=TT/(1+c*lmid)+lmid,ans2=TT/(1+c*rmid)+rmid;
					mn=min(mn,min(ans1,ans2));
					if(ans1<ans2)r=rmid; else l=lmid;
				}
				//if(k==7)cout<<mn<<" "<<i*10<<" "<<T<<" "<<TT<<endl;
				if(mn+i*10<=T)ans=max(ans,k);
			}
		}
		cout<<ans<<endl;
	}
}
/*
TT/(1+Cx)+x
*/