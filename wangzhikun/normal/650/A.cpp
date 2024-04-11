#include <map>
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
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n;
ll ans= 0;
map< pii,int > Mp;
pii po[200020];
bool cmp1(pii a,pii b){
	return a.first<b.first;
}
bool cmp2(pii a,pii b){
	return a.second<b.second;
}

int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(po[i].first);
		read(po[i].second);
		ans-=Mp[po[i]];
		Mp[po[i]]+=1;
	}
	sort(po,po+n,cmp1);
	ll lp = -1;
	for(int i=0;i<n;i++){
		if(i == n-1 || po[i].first!=po[i+1].first){
			ans = ans+(i-lp)*(i-lp-1)/2;
			lp = i;
		}
	}
	sort(po,po+n,cmp2);
	lp = -1;
	for(int i=0;i<n;i++){
		if(i == n-1 || po[i].second!=po[i+1].second){
			ans = ans+(i-lp)*(i-lp-1)/2;
			lp = i;
		}
	}
	cout<<ans<<endl;
	return 0;
}