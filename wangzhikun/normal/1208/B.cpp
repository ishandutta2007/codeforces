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

int n,a[2010],b[2010],m,cnt[2010];

int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		b[i] = a[i];
	}
	sort(b,b+n);
	m = unique(b,b+n)-b+1;
	int dcn = 0;
	for(int i=0;i<n;i++){
		a[i] = lower_bound(b,b+m,a[i])-b+1;
		cnt[a[i]]+=1;
		if(cnt[a[i]] == 2){
			dcn +=1;
		}
	}
	int ans = 10000;
	if(dcn == 0)ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cnt[a[j]]--;
			if(cnt[a[j]] == 1)dcn--;
			if(dcn == 0)ans = min(ans,j-i+1);
		}
		for(int j=i;j<n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]] == 2)dcn++;
		}
	}
	cout<<ans<<endl;
	return 0;
}