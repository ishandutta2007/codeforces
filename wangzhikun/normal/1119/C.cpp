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

int n,m,a[520][520],b[520][520];
int main() {
	read(n);read(m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)read(a[i][j]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)read(b[i][j]);
	int ok = 1;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		if(a[i][j]!=b[i][j]){
			if(i == n-1 || j == m-1)ok = 0;
			a[i][j]^=1;
			a[i+1][j]^=1;
			a[i][j+1]^=1;
			a[i+1][j+1]^=1;
		}
	}
	if(ok){
		cout<<"Yes"<<endl;
	}else{
	
		cout<<"No"<<endl;
	}
	return 0;
}