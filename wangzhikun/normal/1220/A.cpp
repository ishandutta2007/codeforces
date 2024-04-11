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

int n,cn = 0;
char cc[100010];
int main(){
	read(n);
	cin>>cc;
	for(int i=0;i<n;i++){
		if(cc[i] == 'n')cn++;
	}
	int c1 = cn,c2 = (n-cn*3)/4;
	while(c1--)cout<<1<<' ';
	while(c2--)cout<<0<<' ';
	return 0;
}