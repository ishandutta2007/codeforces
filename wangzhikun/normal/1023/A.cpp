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
int n,m,flg = 0,ans = 1,p1 = 0,p2 = 0;
char s[200010],t[200010];
int main(){
	cin>>n>>m;
	cin>>s>>t;
	for(int i=0;i<n;i++){
		if(s[i] == '*')flg = 1;
	}
	if(!flg){
		if(n!=m)ans =0 ;
		for(int i=0;i<n;i++)if(s[i]!=t[i])ans = 0;
	}else{
		while(s[p1]!='*'){
			if(s[p1]!=t[p1])ans = 0;
			p1+=1;
		}
		while(s[n-p2-1]!='*'){
			if(s[n-p2-1]!=t[m-p2-1]){
				ans = 0;
			}
			p2+=1;
		}
		if(p1+p2>m)ans = 0;
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}