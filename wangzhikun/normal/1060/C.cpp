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

ll n,m,a[2020],b[2020],sua[2020] = {0},sub[2020] = {0},mx[2020],my[2020],x;
int main() {
	memset(mx, 7, sizeof(mx));
	memset(my, 7, sizeof(my));
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		sua[i] = sua[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		read(b[i]);
		sub[i] = sub[i-1]+b[i];
	}
	read(x);
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			my[j-i] = min(my[j-i],sua[j]-sua[i]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=1+i;j<=m;j++){
			mx[j-i] = min(mx[j-i],sub[j]-sub[i]);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(my[i]*mx[j]<=x)ans = max(ans,i*j);
	cout<<ans<<endl;
	return 0;
}