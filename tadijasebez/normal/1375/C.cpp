#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> p(n);
		rd(p);
		stack<int> st;
		st.push(p[0]);
		for(int i=1;i<n;i++){
			while(st.size()>1&&st.top()<p[i])st.pop();
			if(st.top()>p[i])st.push(p[i]);
		}
		if(st.size()==1)printf("YES\n");
		else printf("NO\n");
		/*vector<int> mn(n),mx(n);
		mn[0]=p[0];
		for(int i=1;i<n;i++)mn[i]=min(mn[i-1],p[i]);
		mx[n-1]=p[n-1];
		for(int i=n-2;i>=0;i--)mx[i]=max(mx[i+1],p[i]);
		bool ok=true;
		for(int i=1;i<n;i++)if(mn[i-1]>mx[i])ok=false;
		printf(ok?"YES\n":"NO\n");*/
	}
	return 0;
}