#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	int p, d, d2;
};
vector<dat> ps[N];
int n,x,y,ans=0,p[N],a[N];
vector<int> g[N];

void dfs(int x,int fa){
	vector<dat> p1 = ps[x];
	for(auto u:g[x])if(u!=fa){
		dfs(u,x);
		for(auto &y:p1){
			for(auto z:ps[u])if(y.p==z.p){
				//cout<<"!!!"<<x<<" "<<u<<" "<<y.p<<endl;
				if(z.d + 1 > y.d){
					y.d2 = y.d;
					y.d = z.d + 1;
				}else if(z.d + 1 > y.d2){
					y.d2 = z.d + 1;
				}
				break;
			}
		}
	}
	for(auto y:p1){
		//cout<<x<<" "<<a[x]<<" "<<y.p<<" "<<y.d<<" "<<y.d2<<endl;
		ans = max(ans, y.d + y.d2 + 1);
	}
	ps[x] = p1;
}

int main(){
	//freopen("test.in","r",stdin);
	rep(i,2,2e5){
		int j;
		for(j=2;j*j<=i;++j)if(i%j==0)break;
		p[i] = (j*j<=i) ? j : i;
	}
	
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",a+i);
		int x = a[i], last = 0;
		while(x>1){
			if(p[x]!=last) ps[i].PB({p[x],0,0});
			last = p[x], x /= p[x];
		}
		//for(auto x:ps[i])cout<<x<<" ";cout<<endl;
	}
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		g[x].PB(y), g[y].PB(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}