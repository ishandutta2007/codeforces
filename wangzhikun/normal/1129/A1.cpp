#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int n,m,a,b,num[5050],mi[5050];
int main() {
	memset(mi,7,sizeof(mi));
	read(n);read(m);
	for(int i=0;i<m;i++){
		read(a);read(b);
		num[a]+=1;
		mi[a] = min(mi[a],(b+n-a)%n);
	}
	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int j=1;j<=n;j++){
			if(num[j])ans = max(ans,(num[j]-1)*n+(j+n-i)%n+mi[j]);
		}
		cout<<ans<<' ';
	}
	cout<<endl;
	return 0;
}