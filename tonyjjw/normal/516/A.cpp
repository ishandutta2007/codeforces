//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int N;
int cnt[10];
char n[20];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	scanf("%s",n);
	for(int i=0;i<N;i++){
		int v=n[i]-'0';
		if(v<=1)continue;
		if(v<=3){
			cnt[v]+=1;
			continue;
		}
		if(v==4){
			cnt[2]+=2;
			cnt[3]+=1;
			continue;
		}
		if(v==5){
			cnt[5]+=1;
			continue;
		}
		if(v==6){
			cnt[5]+=1;
			cnt[3]+=1;
			continue;
		}
		if(v==7){
			cnt[7]+=1;
			continue;
		}
		if(v==8){
			cnt[7]+=1;
			cnt[2]+=3;
			continue;
		}
		if(v==9){
			cnt[7]+=1;
			cnt[3]+=2;
			cnt[2]+=1;
		}
	}
	for(int i=9;i>=2;i--){
		for(int j=0;j<cnt[i];j++)printf("%d",i);
	}
	return 0;
}
//*/