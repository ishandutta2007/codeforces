#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 10007;
int u[maxn];
int p[maxn];
bool fl[maxn];
int n;

int main(){
	memset(u,0,sizeof(u));
	memset(fl,1,sizeof(fl));
	cin>>n;
	for (int i=2;i<=n;++i){
		cin>>p[i];
		fl[p[i]]=0;
	}
	for (int i=2;i<=n;++i){
		u[p[i]]+=fl[i];
	}
	for (int i=1;i<=n;++i){
		if (!fl[i]&&u[i]<3){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
	return 0;
}