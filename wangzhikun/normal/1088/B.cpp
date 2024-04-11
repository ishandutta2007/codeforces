#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}
int n,k,a[100010];
int main() {
	read(n);read(k);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	sort(a,a+n);
	int pre = 0;
	for(int i=0;i<n;i++){
		if(a[i]-pre && k){
			k--;
			cout<<a[i]-pre<<endl;
			pre = a[i];
		}
	}
	for(int i=0;i<k;i++)cout<<0<<endl;
	return 0;
}