#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n,p,cnt,t[N];
priority_queue<pll,vector<pll>,greater<pll> > Q;
priority_queue<int,vector<int>,greater<int> > S;
ll ans[N],T;
int main(){
	scanf("%d%d",&n,&p);
	For(i,1,n){
		scanf("%d",&t[i]);
		Q.push(pll(t[i],i-n));
	}
	int now=n+1;
	while (!Q.empty()){
		pll x=Q.top(); Q.pop();
		T=max(T,x.fi);
		if (x.se<=0){
			x.se+=n;
			if (now>x.se){
				++cnt;
				now=x.se;
				Q.push(pll(T+=p,x.se));
			}
			else
				S.push(x.se);
		}
		else{
			ans[x.se]=x.fi;
			if (!--cnt){
				if (S.empty()) now=n+1;
				else{
					++cnt;
					now=S.top();
					Q.push(pll(T+=p,now));
					S.pop();
				}
			}
		}
	}
	For(i,1,n)
		printf("%lld ",ans[i]);
}