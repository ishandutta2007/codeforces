/*
Contest: Educational Codeforces Round 92
Problem: Codeforces 1389B
Author: tzc_wk
Time: 2020.7.29
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,k,z,a[100005],vis[100005];
inline void solve(){
	cin>>n>>k>>z;
	fz(i,1,n) a[i]=read();
	multiset<int> st;
	int ans=0;
	fz(i,0,z){
		fill0(vis);
		if(1+k-i-i<=0)	continue;
		int t=k-i-i+1+1,sum=0;
		fz(j,1,t-1){
			sum+=a[j];
		}
		fz(j,1,i){
			int mx=-0x3f3f3f3f,ind=0;
			fz(f,2,t){
				mx=max(mx,a[f]+a[f-1]);
			}
			sum+=mx;
		}
//		cout<<i<<" "<<sum<<endl;
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}
/*
1
10 9 5
9 9 10 1 1 1 1 1 1 1
*/