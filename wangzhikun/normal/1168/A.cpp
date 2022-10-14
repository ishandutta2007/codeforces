#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,m,a[300030];
int main() {
	read(n);read(m);
	for(int i=0;i<n;i++)read(a[i]);
	int l=-1,r = m;
	while(l+1!=r){
		int mid = (l+r)/2,ok = 1;
		int clw = 0;
		for(int i=0;i<n;i++){
			if(a[i]<clw && clw-a[i]>mid)ok = 0;
			if(a[i]>clw && clw+m-a[i]>mid){
				clw = a[i];
			}
		}
		//cout<<l<<' '<<r<<' '<<mid<<' '<<ok<<endl;
		if(ok){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout<<r<<endl;
	return 0;
}