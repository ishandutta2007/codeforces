//  Created by WangZhikun on 2018/10/4.

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))

using namespace std;
typedef long long ll;

template <typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,l[100010],r[100010],ans = 0;
int main() {
	read(n);
	for(int i=0;i<n;i++){
	read(l[i]);read(r[i]);
	}
	sort(l,l+n);
	sort(r,r+n);
	for(int i=0;i<n;i++){
		ans+=max(l[i],r[i]);
	}
	ans+=n;
	cout<<ans<<endl;
	return 0;
}