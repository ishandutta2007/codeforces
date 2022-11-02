#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
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
const int N=100005,inf=1e9+7;
int n,m,arr[N],a[N],b[N],f[N],g[N],ab[N];
multiset<int> S;
void solve(int dq,int pos,int de){
	if(!dq)return; //cout<<dq<<" "<<pos<<" "<<a[pos]<<" "<<de<<endl;
	if(a[pos]>=0){
		solve(dq-1,g[pos],a[pos]);
	}else{
		S.erase(S.find(a[pos]=b[lower_bound(b+1,b+m+1,de)-b-1]));
		Rep(i,pos-1,0)if(f[i]==dq-1&&a[i]>=0&&a[i]<a[pos]){
			solve(dq-1,i,a[pos]); return;
		}
		Rep(i,pos-1,0)if(a[i]<0){solve(dq-1,i,a[pos]); return ;}
	}
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	m=read();
	For(i,1,m)S.insert(b[i]=read());
	sort(b+1,b+m+1);
	int len=1;
	For(i,1,n)if(a[i]>=0){
		int t=lower_bound(arr+1,arr+len,a[i])-arr;
		if(t==len)arr[len++]=a[i];
		else arr[t]=a[i];
		ab[t]=i;
		f[i]=t; g[i]=ab[t-1];
	}else{
		int pos=len-1;
		//cout<<arr[len-1]<<" "<<b[2]<<endl;
		Rep(j,m,1){
			while(arr[pos]>=b[j])pos--;
			arr[pos+1]=b[j]; ab[pos+1]=i; if(pos==len-1)len++;
		}
		f[i]=len-1;
	}
	int ans=len-1; //cout<<ans<<endl;
	Rep(i,n,1)if(f[i]==len-1){
		solve(ans,i,inf);
		For(j,1,n)if(a[j]>=0)wri(a[j]); else {wri(*S.begin()); S.erase(S.begin());}
		return 0;
	}
}