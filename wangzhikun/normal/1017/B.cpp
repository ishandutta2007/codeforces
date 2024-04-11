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

ll n;
char s1[100010],s2[100010];
int main(){
	read(n);
	ll ans = 0;
	cin>>s1>>s2;
	int su[2][2] = {0};
	for(int i=n-1;i>0;i--){
		su[(s1[i] == '1')][(s2[i] == '1')]+=1;
	}
	for(int i=0;i<n;i++){
		if(s1[i] == '1' && s2[i] == '0')ans+=su[0][0]+su[0][1];
		if(s1[i] == '1' && s2[i] == '1')ans+=su[0][0];
		if(s1[i] == '0' && s2[i] == '0')ans+=su[1][0]+su[1][1];
		if(s1[i] == '0' && s2[i] == '1')ans+=su[1][0];
		su[(s1[i+1] == '1')][(s2[i+1] == '1')]-=1;
	}
	cout<<ans<<endl;
	return 0;
}