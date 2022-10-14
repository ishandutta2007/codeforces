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

int n,m,ispri[2020];
int main() {
	read(n);
	for(int i=2;i<=2000;i++){
		ispri[i] = 1;
		for(int j=2;j*j<=i;j++){
			if(i%j == 0)ispri[i] = 0;
		}
		//cout<<i<<' '<<ispri[i]<<endl;
	}
	
	for(int j=n;j<=n+n/2;j++){
		if(ispri[j]){
			cout<<j<<endl;
			for(int i=0;i<n;i++){
				cout<<i+1<<' '<<(i+1)%n + 1<<endl;
			}
			for(int i=0;i<j-n;i++){
				cout<<i+1<<' '<<i+(n/2)+1<<endl;
			}
			return 0;
		}
	}

	return 0;
}