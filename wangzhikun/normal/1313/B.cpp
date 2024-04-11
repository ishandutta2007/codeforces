#include <bits/stdc++.h>
using namespace std;

#define set0(x) memset(x,0,sizeof(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}
#define int long long
int T,n,a,b;
ll gmin(ll a,ll b){return min(a,b);}

int calc(int a,int b,int A,int B){
	return gmin(b,B)+gmin(b-gmin(b,B)+a,A);
}
int getworst(){
	return calc(n-a,a-1,b-1,n-b)+1;
}

int getbest(){
	return n-calc(a-1+gmin(1,n-a),n-1-(a-1+gmin(1,n-a)),n-b,b-1);
}

signed main() {
	read(T);
	while(T--){
		cin>>n>>a>>b;
		if(a>b)swap(a,b);
		cout<<getbest()<<' ';
		cout<<getworst()<<endl;
	}
	return 0;
}