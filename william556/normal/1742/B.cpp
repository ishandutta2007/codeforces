#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
void solve(){
	map<int,int> mp;
	int n=in(),flag=1;
	while(n--){
		int x=in();
		if(mp[x])flag=0;
		mp[x]=1;
	}
	puts(flag?"YES":"NO");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}