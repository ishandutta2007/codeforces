#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int x,y;
bool is(int a){
	int s=sqrt(a);
	return s*s==a;
}
void solve(){
	scanf("%d%d",&x,&y);
	puts(x+y==0?"0":(is(x*x+y*y)?"1":"2"));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}