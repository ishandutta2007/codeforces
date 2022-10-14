#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
char s[1010],t[1010];
bool iscon(char x){
	return x == 'a' ||  x == 'e' ||  x == 'i' ||  x == 'o' ||  x == 'u';
}
int main() {
	cin>>s>>t;
	int ans = 0;
	for(int i=0;i<1000;i++){
		if(iscon(s[i])^iscon(t[i]))ans = 1;
	}
	ans|=strlen(s)!=strlen(t);
	if(!ans)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}