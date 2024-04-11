//  Created by  on 2018/8/19.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll n;
char s[200010];
int main() {
	cin>>s;
	n = strlen(s);
	for(int i=0;i<n;i++)s[i+n] = s[i];
	ll cl = 1,ml = 1;
	for(int i=1;i<n*2;i++){
		cl = (s[i] != s[i-1])?cl+1:1;
		ml = max(ml,cl);
	}
	cout<<min(ml,n)<<endl;
	return 0;
}