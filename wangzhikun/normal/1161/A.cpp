#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k,mi[100010],fi[100010];
int main() {
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int cc;
		cin>>cc;
		if(!mi[cc])mi[cc] = i;
		fi[cc] = i;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!mi[i])ans++;
	}
	for(int i=1;i<n;i++){
		if(!fi[i+1] || !mi[i] || fi[i+1]<=mi[i])ans++;
	}
	for(int i=2;i<=n;i++){
		if(!fi[i-1] || !mi[i] || fi[i-1]<=mi[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}