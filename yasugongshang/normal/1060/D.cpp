#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const int N=100005;
int n;
ll ans,vis[N];
PI a[N],q[N];
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].first=read(); a[i].second=read(); 
	}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++)q[i]=mp(a[i].second,i);
	sort(&q[1],&q[n+1]);
	for(int i=1;i<=n;i++)if(!vis[i]){
		for(int j=q[i].second;;j=q[j].second){vis[j]=1; ans+=max(a[q[j].second].first,q[q[j].second].first); if(j==i)break; }
	}
	cout<<ans+n<<endl;
}