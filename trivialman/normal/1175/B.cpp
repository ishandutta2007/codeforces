#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	LL n,ans;
};
int n,x;
char s[10];
stack<dat> stk;

int main(){
	//freopen("test.in","r",stdin);
	
	scanf("%d",&n);
	stk.push({1,0});
	
	rep(i,1,n){
		scanf("%s",&s);
		if(s[0]=='f'){
			scanf("%d",&x);
			stk.push({x,0});
		}else if(s[0]=='a'){
			stk.top().ans++;
		}else{
			dat x = stk.top();
			stk.pop();
			LL y = x.n * x.ans;
			//cout<<i<<" "<<x.n<<" "<<x.ans<<" "<<y<<endl;
			if(y>=(1ll<<32)){
				printf("OVERFLOW!!!");
				return 0;
			}
			stk.top().ans += y;
		}
	}
	if(stk.top().ans>=(1ll<<32)){
		printf("OVERFLOW!!!");
		return 0;
	}
	printf("%lld\n",stk.top().ans);
	return 0;
}