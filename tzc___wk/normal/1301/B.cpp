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
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n,a[100005];
inline void solve(){
	n=read();
	fz(i,1,n)	a[i]=read();
	int ans=0;
	vector<int> v;
	fz(i,1,n-1){
		if(a[i]!=-1&&a[i+1]!=-1){
			ans=max(ans,abs(a[i]-a[i+1]));
		}
		else if(a[i]==-1&&a[i+1]==-1){
			continue;
		}
		else if(a[i]==-1){
			v.push_back(a[i+1]);
		}
		else{
			v.push_back(a[i]);
		}
	}
	if(v.size()==0){
		cout<<ans<<" "<<0<<endl;
		return;
	}
	sort(v.begin(),v.end());
	int mid=(v[0]+v.back())>>1;
	int anss=0;
	fz(i,1,n-1){
		if(a[i]!=-1&&a[i+1]!=-1){
			anss=max(anss,abs(a[i]-a[i+1]));
		}
		else if(a[i]==-1&&a[i+1]==-1){
			continue;
		}
		else if(a[i]==-1){
			anss=max(anss,abs(mid-a[i+1]));
		}
		else{
			anss=max(anss,abs(mid-a[i]));
		}
	}
	cout<<anss<<" "<<mid<<endl;
}
signed main(){
	int T=read();while(T--)	solve();
	return 0;
}