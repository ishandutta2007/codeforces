#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using LL=long long;
const int N=500005;
int n,m,a[N],match[N];
pair<int,int>b[N];
LL ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	rd(n);
	rep(i,1,n)rd(a[i]),ans+=a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[i]==a[j])++j;
		b[++m]={a[i],j-i};
	}
	int sum=0;
	rep(i,1,m){
		int val,cnt;
		tie(val,cnt)=b[i];
		int rem=min(sum-SZ(q)*2,cnt);
		vector<int>tmp;
		rep(j,1,rem)tmp.pb(val);
		rem=min(sum,cnt)-rem;
		for(int j=1;j<=rem;j+=2){
			LL cur=q.top();
			q.pop();
			if(cur<val){
				tmp.pb(val);
				if(j+1<=rem){
					tmp.pb(val);
				}
			}else{
				tmp.pb(cur);
				if(j+1<=rem&&val*2-cur>0)tmp.pb(val*2-cur);
			}
		}
		for(auto&x:tmp)q.push(x);
		sum+=cnt;
	}
	while(!q.empty())ans-=q.top(),q.pop();
	printf("%lld\n",ans);
	return 0;
}