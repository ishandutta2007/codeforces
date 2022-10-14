#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

char s[500050],t[500050];
ll n,k;
int main() {
	read(n);read(k);
	scanf("%s",s);
	scanf("%s",t);
	ll ppos = 1,ans = 0;
	for(int i=0;i<n;i++){
		if(ppos<=k){
			if(ppos == 1){
				ppos = t[i]-s[i]+1;
			}else{
				ppos = (ppos-2)*2;
				ppos += t[i]-'a'+1;
				ppos += 'b'-s[i]+1;
			}
		}
		//cout<<min(ppos,k)<<endl;
		ans+=min(ppos,k);
	}
	cout<<ans<<endl;
	return 0;
}