// Author : WangZhikun
// Date   : 2018.08.16
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define popcnt __builtin_popcount
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll n,m,st[200010],stn = 0,dy[200010];
char s[200010];
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i] == '('){
			st[stn] = i;
			stn+=1;
		}else{
			dy[st[stn-1]] = i;
			dy[i] = st[stn-1];
			stn--;
		}
	}
	int po = 0,id = 0;
	while(id<(n-m)/2){
		if(s[po]!=' '){
			s[po] = ' ';
			s[dy[po]] = ' ';
			id+=1;
		}
		po+=1;
	}
	for(int i=0;i<n;i++){
		if(s[i]!=' ')cout<<s[i];
	}
	return 0;
}