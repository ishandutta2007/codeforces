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
char cch[2020];
void solve(){
	cin>>cch;
	int cn = strlen(cch);
	int cs = 0,cs2 = 0,cs3 = 0;
	for(int j=0;j<cn;j++){
		cs+=cch[j]-'0';
		if((cch[j]-'0')%2 == 0)cs2 += 1;
		if((cch[j]=='0'))cs3 += 1;
	}
	if(cs%3 == 0 && cs3 >= 1 && cs2>1){
		cout<<"red\n";
	}else{
		cout<<"cyan\n";
	}
}
int main() {
	read(n);
	while(n--){
		solve();
	}
	return 0;
}