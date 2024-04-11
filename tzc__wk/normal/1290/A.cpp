/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
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
int n,m,k,a[3505],mx[100005];
inline void solve(){
	cin>>n>>m>>k;
	k=min(m,k);
	memset(a,0,sizeof(a));
	memset(mx,0,sizeof(mx));
	fz(i,1,n)	a[i]=read();
	if(m==k){
		int ans=0;
		fz(i,1,k)	ans=max(ans,a[i]);
		fz(i,n-k+1,n)	ans=max(ans,a[i]);
		cout<<ans<<endl;
		return;
	}
	fz(i,1,m){
		mx[i]=max(a[i],a[i+n-m]);
	}
	multiset<int> st;
	fz(i,1,(n-k)-(n-m)){
		st.insert(mx[i]);
	}
	int l=1,r=((n-k)-(n-m));
	int ans=0;
	while(r<=n){
		ans=max(ans,*st.begin());
		st.erase(st.find(mx[l++]));
		r++;
		if(r==n+1)	break;
		st.insert(mx[r]);
	}
	cout<<ans<<endl;
}
int main(){
	int T=read();
	while(T--)	solve();
	return 0;
}