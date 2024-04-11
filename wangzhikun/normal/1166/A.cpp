#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,a = 0,b = 0;
int cnt[100] = {0};
char ch[1000];
int c(int x){
	return x*(x-1)/2;
}
int main() {
	read(n);
	for(int i=0;i<n;i++){
		cin>>ch;
		cnt[ch[0]-'a']++;
	}
	int ans = 0;
	for(int i=0;i<26;i++){
		ans+=c(cnt[i]/2)+c(cnt[i]-(cnt[i]/2));
	}
	cout<<ans<<endl;
	return 0;
}