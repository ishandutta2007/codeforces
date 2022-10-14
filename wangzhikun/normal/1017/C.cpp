// Author : WangZhikun
// Date   : 2018.08.08

#include <map>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll gmax(ll a,ll b){return a>b?a:b;}
ll gmin(ll a,ll b){return a<b?a:b;}

ll n;
int main(){
	read(n);
	int sqr = 0,minn = 10000000;
	for(int i=1;i<=n;i++){
		if(i+(n+i-1)/i<minn){
			minn = i+(n+i-1)/i;
			sqr = i;
		}
	}
	int stn = 0;
	for(int i=0;i<100000;i++)if(i*sqr+sqr>=n){
		stn = i;
		break;
	}
	for(int j=stn;j>=0;j--){
		for(int k=1;k<=sqr;k++){
			if(j*sqr+k<=n){
				cout<<j*sqr+k<<' ';
			}
		}
	}
	cout<<endl;
	return 0;
}