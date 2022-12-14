//*
#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
#define LIM 1200000
using namespace std;

int N;
int pchk[LIM+1];

vector<int> prime;

bool ispalin(int n){
	vector<int> dig;
	while(n){
		dig.push_back(n%10);
		n/=10;
	}
	for(int i=0;dig.size()-i-1<dig.size();i++){
		if(dig[dig.size()-i-1]!=dig[i])return false;
	}
	return true;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i;
	for(int i=2;i<=LIM;i++){
		if(!pchk[i])prime.push_back(i);
		for(long long j=(long long)i*i;j<=LIM;j+=i){
			pchk[j]=1;
		}
	}
	int p,q,pp=0;
	int c1=0,c2=0;
	scanf("%d%d",&p,&q);
	int ans=0;
	for(int i=1;i<=LIM;i++){
		if(pp!=prime.size() && prime[pp]==i)c1++,pp++;
		if(ispalin(i))c2++;
		if((long long)q*c1<=(long long)p*c2)ans=i;
	}
	if(!ans){
		puts("Palindromic tree is better than splay tree");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
//*/