#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,k,d,a[200005],cnt[1000005];
inline void solve(){
	n=read();k=read();d=read();
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int cur=0;
	for(int i=1;i<=d;i++){
		if(cnt[a[i]]==0)	cur++;
		cnt[a[i]]++;
	}
	int curl=1,curr=d;
	int ans=cur;
	while(curr<n){
		cnt[a[curl]]--;
		if(cnt[a[curl]]==0)	cur--;
		curl++;
		curr++;
		cnt[a[curr]]++;
		if(cnt[a[curr]]==1)	cur++;
		ans=min(ans,cur);
	}
	print(ans);eoln;
}
int main(){
	int T=read();
	while(T--)	solve();
	return 0;
}