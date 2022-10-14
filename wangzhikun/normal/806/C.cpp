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

int n;
ll a[100010],cnt1[50],cnt2[50],cnt3[50];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		for(int j=0;j<40;j++){
			if(a[i] == (1ll<<j)){
				cnt1[j]++;
			}
			if((a[i]>= (1ll<<j)) && (a[i]<1ll<<(j+1))){
				cnt2[j]++;
			}
		}
	}
	int cnt = 0;
	for(int i=1;i<=cnt1[0];i++){
		int cc = i;
		set0(cnt3);
		//cout<<"cnt1 ";for(int j=0;j<40;j++)cout<<cnt1[j]<<' ';cout<<endl;
		for(int j=0;j<=40;j++){
			if(cnt1[j]<cc){
				cnt3[j-1]+=cc-cnt1[j];
				cc = cnt1[j];
			}
		}
		//cout<<"cnt2 ";for(int j=0;j<40;j++)cout<<cnt2[j]<<' ';cout<<endl;
		//cout<<"cnt3 ";for(int j=0;j<40;j++)cout<<cnt3[j]<<' ';cout<<endl;
		int workout = 0,subqz = 0,ok = 1;
		for(int j=40;j>=0;j--){
			subqz+=cnt3[j];
			workout+=cnt3[j];
			workout -= cnt2[j]-subqz;
			if(workout<0)ok = 0;
		}
		if(ok){
			cnt++;
			cout<<i<<' ';
		}
	}
	if(cnt == 0)cout<<-1;
	cout<<endl;
	return 0;
}