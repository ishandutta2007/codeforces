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

int T,n,a[300030];

vector<int> ocr[300030];

int main() {
	read(T);
	while(T--){
		read(n);
		int cmx = 0;
		for(int i=0;i<n;i++){
			read(a[i]);
			ocr[a[i]].push_back(i);
		}
		priority_queue<pii , vector<pii>, greater<pii>> Q;
		int cnt = 0,end = 0;
		for(int i=n;i>=1;i--){
			if(ocr[i].size() == 0)continue;
			cnt++;
			while(Q.size()>0 && Q.top().first< ocr[i][ocr[i].size()-1]){
				end = max(end,(int)Q.top().second);
				Q.pop();
			}
			Q.push(make_pair(ocr[i][0],cnt));
			cmx = max(cmx,cnt-end);
		}
		cout<<cnt-cmx<<endl;
		for(int i=1;i<=n;i++){
			ocr[i].clear();
		}
	}
	return 0;
}