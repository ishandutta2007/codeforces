//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 100000
#define MOD 1000000007
using namespace std;

int N;

char inp[MN+1];
int c[4];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	scanf("%s",inp);
	for(int i=0;i<N;i++){
		if(inp[i]=='A'){
			c[0]++;
		}
		if(inp[i]=='G'){
			c[1]++;
		}
		if(inp[i]=='C'){
			c[2]++;
		}
		if(inp[i]=='T'){
			c[3]++;
		}
	}
	sort(c,c+4);
	int v=4;
	for(int i=2;i>=0;i--){
		if(c[i]!=c[i+1]){
			v=3-i;
			break;
		}
	}
	__int64 ans=1;
	for(int i=0;i<N;i++){
		ans*=v;
		ans%=MOD;
	}
	printf("%I64d",ans);
	return 0;
}
//*/