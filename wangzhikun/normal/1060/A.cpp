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

int n,cnt =0;
char ch[200];
int main() {
	read(n);
	cin>>ch;
	for(int i=0;i<n;i++)cnt+=(ch[i] == '8');
	cout<<min(cnt,n/11)<<endl;
	return 0;
}