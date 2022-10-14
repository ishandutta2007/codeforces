//  Created by  on 2018/8/19.

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
ll n,buc[200] = {0};
char s[100010];
int main() {
	read(n);
	if(n == 1){
		cout<<"Yes"<<endl;
		return 0;
	}
	cin>>s;
	int ans = 0;
	for(int i=0;i<n;i++){
		buc[s[i]]+=1;
		if(buc[s[i]]>1)ans = 1;
	}if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}