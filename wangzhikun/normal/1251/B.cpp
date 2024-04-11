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

int T;
int main() {
	read(T);
	while(T--){
		int n;
		read(n);
		int cnt[2] = {0},cntr = 0;
		for(int i=0;i<n;i++){
			char cs[110];
			cin>>cs;
			int m = strlen(cs);
			if(m%2 == 1)cntr++;
			for(int j=0;j<m;j++)cnt[cs[j]-'0']++;
		}
		if(cnt[0]%2 == 1 && cnt[1]%2 == 1 && cntr==0){
			cout<<n-1<<endl;
			
		}else{
			cout<<n<<endl;
		}
	}
	return 0;
}