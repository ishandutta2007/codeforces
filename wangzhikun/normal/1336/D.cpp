#include <bits/stdc++.h>
using namespace std;
#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> VI;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

ll diff1[110],diff2[110];
ll n,a,b,na,nb;
int ans[110];
map<ll,int> Mp;
int main() {
	read(n);
	read(a,b);
	for(int i=3;i<=n+10;i++){
		Mp[i*(i-1)*(i-2)/6-(i-1)*(i-2)*(i-3)/6] = i-1;
	}
	for(int i=1;i<=n;i++){
		int cq =i == n?1:i;
		cout<<"+ "<<cq<<endl;
		cout.flush();
		read(na,nb);
		diff1[i] = na-a;
		diff2[i] = nb-b;
		if(diff1[i]){
			ans[cq] = Mp[diff1[i]]-(i == n);
		}
		a = na;
		b = nb;
	}
	if(!ans[2] && !ans[3]){
		if(diff2[n] == 1 || diff2[n] == 4){
			ans[2] = ans[3] = sqrt(diff2[n])-1;
		}else{
			if(diff2[2])ans[2] = 0,ans[3] = 1;
			else ans[2] = 1,ans[3] = 0;
		}
	}else{
		if(ans[2])ans[3] = diff2[1]/ans[2];
		else ans[2] = diff2[1]/ans[3];
	}
	cout<<"! "<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' ';
	for(int i=4;i<=n-1;i++){
		if(!ans[i]) ans[i] = diff2[i-1]>(ans[i-2]+1)*(ans[i-3]+1);
		cout<<ans[i]<<" ";
	}
	cout<<(diff2[n-1]-(ans[n-2]+1)*(ans[n-3]+1))/(ans[n-2]+1)<<endl;
	return 0;
}











/*
*/