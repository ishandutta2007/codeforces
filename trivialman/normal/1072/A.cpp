#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 1000010
#define LL long long

int n,m,k;
bool block[N];
LL cost[N],prevpos[N]; 

int main(){
	cin>>n>>m>>k;
	int ans=0;
	for(int i=0;i<k;i++){
		ans+=2*(n+m-8*i-2);
	}
	cout<<ans<<endl;
	return 0;
}