//  Created by  on 2018/8/18.

#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll T,n;
char s[100010];
int main() {
	read(T);
	while(T--){
		read(n);
		cin>>s;
		int ans = 1;
		for(int i=0;i<n/2;i++){
			if(!(s[i] == s[n-i-1] || abs(s[i]-s[n-i-1]) == 2))ans = 0;
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}