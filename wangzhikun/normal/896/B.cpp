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

int n,m,c,cc;
int val[1010];

int main() {
	read(n);read(m);read(c);
	for(int i=0;i<m;i++){
		read(cc);
		if(cc<=(c+1)/2){
			
			for(int j=1;j<=n;j++){
				if(val[j]==0 || cc<val[j]){
					val[j] = cc;
					cout<<j<<endl;
					goto nxt;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(val[j]==0 || cc>val[j]){
					val[j] = cc;
					cout<<j<<endl;
					goto nxt;
				}
			}
		}
		nxt:;
		int ok = 1;
		for(int j=1;j<n;j++){
			if(val[j]>val[j+1])ok = 0;
		}
		for(int j=1;j<=n;j++)if(val[j] == 0)ok = 0;
		
		if(ok)return 0;
	}
	return 0;
}