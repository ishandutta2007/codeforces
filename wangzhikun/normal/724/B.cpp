//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n,m,A[30][30],B[30][30],ok = 0;

int main(){
	read(n);read(m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)read(A[i][j]);
	for(int i=0;i<m;i++)for(int j=i;j<m;j++){
		memcpy(B,A,sizeof(A));
		for(int k=0;k<n;k++){
			if(i!=j)swap(B[k][i],B[k][j]);
		}
		int cok = 1;
		for(int k=0;k<n;k++){
			int accu = 0;
			for(int l=0;l<m;l++){
				if(B[k][l]!=l+1){
					accu+=1;
					swap(B[k][l],B[k][B[k][l]-1]);
				}
				if(B[k][l]!=l+1)accu+=1;
			}
			if(accu>1)cok = 0;
		}
		if(cok){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}