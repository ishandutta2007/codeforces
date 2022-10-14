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

ll n,q,m,w[20],num[5000] = {0},ans[5000][110] = {0},tans[5000][110] = {0},qans[5000] = {0};
char s[40];
int rd01(){
	int cn = 0;
	scanf("%s",&s);
	for(int i=0;i<n;i++)if(s[i] == '1')cn+=(1<<i);
	return cn;
}
int main(){
	read(n);read(q);read(m);
	for(int i=0;i<n;i++)read(w[i]);
	for(int i=0;i<q;i++){
		num[rd01()]+=1;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))qans[i]+=w[j];
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<(1<<n);j++){
			if(qans[i^j]>100)continue;
			ans[i][qans[i^j]]+=num[j];
		}
	}
	for(int i=0;i<(1<<n);i++){
		int cn = 0;
		for(int j=0;j<101;j++){
			cn+=ans[i][j];
			tans[i][j] = cn;
		}
	}
	for(int i=0;i<m;i++){
		int cc = rd01(),cb,cans = 0;
		read(cb);
		cout<<tans[cc][cb]<<endl;
	}
	return 0;
}