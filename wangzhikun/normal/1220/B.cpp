#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) cerr<<#x<<'='<<x<<endl

template<typename T> void read(T &x){
	x = 0;char cc = getchar();int f = 1;
	while(!isdigit(cc)){if(cc == '-')f*=-1;cc = getchar();}
	while(isdigit(cc)){x = x*10+cc-48;cc = getchar();}
	x*=f;
}

int n;

ll a[1010][1010];

int main(){
	
	read(n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j == i)continue;
			for(int k=1;k<=n;k++){
				if(k == i || k == j)continue;
				cout<<(ll)sqrt(a[i][j]*a[i][k]/a[j][k])<<' ';
				goto nxt;
			}
		}
		nxt:;
	}
	cout<<endl;
	return 0;
}