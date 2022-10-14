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

const int N = 200020;
int n,m,reqr[30][N];
char str[N],str2[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(str+1);
	for(int i=0;i<26;i++){
		reqr[i][0] = 0;
		int csu = 0;
		for(int j=1;j<=n;j++){
			if(str[j] == 'a'+i){
				csu+=1;
				reqr[i][csu] = j;
			}
		}
	}
	cin>>m;
	for(int t=0;t<m;t++){
		cin>>str2;
		n = strlen(str2);
		int ans = 0;
		for(int i=0;i<26;i++){
			int csu = 0;
			for(int j=0;j<n;j++){
				if(str2[j] == 'a'+i){
					csu+=1;
				}
			}
			ans = max(ans,reqr[i][csu]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}