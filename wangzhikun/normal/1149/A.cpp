#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,a[200020],sum[3] = {0},isnpri[200020] = {0},ans =0;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		sum[a[i]]+=1;
	}
	if(sum[2]){
		sum[2]-=1;
		cout<<"2 ";
	}
	if(sum[1]){
		sum[1]-=1;
		cout<<"1 ";
	}
	while(sum[2]){
		sum[2]-=1;
		cout<<"2 ";
	}
	while(sum[1]){
		sum[1]-=1;
		cout<<"1 ";
	}
	cout<<endl;
	return 0;
}