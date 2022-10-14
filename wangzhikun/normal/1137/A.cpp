#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
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
const int N = 1010;
int n,m,a[N][N],h[N][N],s[N][N],toth[N],tots[N],ans = 0;;
int main() {
	read(n);read(m);
	//cout<<m<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			read(a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		vector<int> cc;
		for(int j=0;j<m;j++)cc.push_back(a[i][j]);
		sort(cc.begin(),cc.end());
		int cm = unique(cc.begin(),cc.end())-cc.begin();
		toth[i] = cm;
		for(int j=0;j<m;j++) h[i][j] = lower_bound(cc.begin(),cc.begin()+cm,a[i][j])-cc.begin()+1;
	}
	for(int i=0;i<m;i++){
		vector<int> cc;
		for(int j=0;j<n;j++)cc.push_back(a[j][i]);
		sort(cc.begin(),cc.end());
		int cm = unique(cc.begin(),cc.end())-cc.begin();
		tots[i] = cm;
		for(int j=0;j<n;j++) s[j][i] = lower_bound(cc.begin(),cc.begin()+cm,a[j][i])-cc.begin()+1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int ans = max(toth[i],tots[j]);
			if(h[i][j]>s[i][j]){
				ans = max(ans,tots[j]-s[i][j]+h[i][j]);
			}else{
				ans = max(ans,toth[i]-h[i][j]+s[i][j]);
			}
			cout<<ans<<' ';
		}cout<<endl;
	}
	//cout<<ans<<endl;
	return 0;
}