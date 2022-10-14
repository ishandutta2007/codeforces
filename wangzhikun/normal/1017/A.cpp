// Author : WangZhikun
// Date   : 2018.08.08

#include <map>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll gmax(ll a,ll b){return a>b?a:b;}
ll gmin(ll a,ll b){return a<b?a:b;}
ll n,a[100010],s[100010];

int main(){
	read(n);
	int ans = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			read(a[i]);
		s[i]+=a[i];
		}
		if(s[i]>s[0])ans+=1;
	}
	cout<<ans<<endl;
	return 0;
}