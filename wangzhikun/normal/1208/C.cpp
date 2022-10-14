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
int main() {
	int n,ans[1010][1010];
	read(n);
	for(int i=0;i<n;i+=4)
		for(int j=0;j<n;j+=4){
			for(int ii = i;ii<i+4;ii++)
				for(int jj = j;jj<j+4;jj++){
					ans[ii][jj] = ((i/4)*(n/4)+j/4)*16+(ii-i)*4+(jj-j);
				}
		}
	for(int i=0;i<n;i+=1){
		int c1 = 0,c2 = 0;
		for(int j=0;j<n;j+=1){
			c1^=ans[i][j];
			c2^=ans[j][i];
			cout<<ans[i][j]<<' ';
		}
		if(c1!=0 || c2!=0)cout<<"no"<<endl;
		cout<<endl;
	}
	return 0;
}