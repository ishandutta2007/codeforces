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

int n,a[1010];
int main() {
	read(n);for(int i=0;i<n;i++)read(a[i]);
	sort(a,a+n);
	int ans = 0;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			ans+=1;
			for(int j=i+1;j<n;j++)if(a[j]%a[i] == 0)a[j] = 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}