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

int n,a[110];
int main() {
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	int csum = a[1],sum = a[1],cnt = 0;
	for(int i=2;i<=n;i++){
		if(a[1]>=a[i]*2){
			csum+=a[i];
			cnt+=1;
		}
		sum+=a[i];
	}
	if(csum*2>sum){
		cout<<cnt+1<<endl;
		cout<<1<<' ';
		for(int i=2;i<=n;i++){
			if(a[1]>=a[i]*2){
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}