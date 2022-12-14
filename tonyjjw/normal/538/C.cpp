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

int N,M;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int a,b,oa,ob;
	int ans=0;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		if(i==0){
			ans=a+b-1;
		}
		else{
			if(ob<b){
				if(b-ob>a-oa){
					puts("IMPOSSIBLE");
					return 0;
				}
				if(ans<b+((a-oa)-(b-ob))/2){
					ans=b+((a-oa)-(b-ob))/2;
				}
			}
			else{
				if(ob-b>a-oa){
					puts("IMPOSSIBLE");
					return 0;
				}
				if(ans<ob+((a-oa)-(ob-b))/2){
					ans=ob+((a-oa)-(ob-b))/2;
				}
			}
		}
		oa=a,ob=b;
		if(i==M-1){
			if(ans<b+N-a)ans=b+N-a;
		}
	}
	printf("%d",ans);
	return 0;
}
//*/