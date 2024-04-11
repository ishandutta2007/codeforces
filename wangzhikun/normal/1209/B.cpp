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

int n,a[110],b[110],ans = 0;
char st[110];
int main() {
	read(n);
	cin>>st;
	for(int i=0;i<n;i++){
		read(b[i]);
		read(a[i]);
	}
	for(int j=0;j<n;j++){
		ans+=st[j]-'0';
	}
	for(int i=1;i<1000;i++){
		int cu = 0;
		for(int j=0;j<n;j++){
			if(i>=a[j] && (i-a[j])%b[j] == 0){
				st[j] = ((st[j]-'0')^1)+'0';
			}
			cu+=st[j]-'0';
		}
		//cout<<st<<endl;
		ans = max(ans,cu);
	}
	cout<<ans<<endl;
	return 0;
}