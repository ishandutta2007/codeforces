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
	scanf("%d%d%d",&n,&m,&k);
	memset(block, false, sizeof(block));
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		block[x]=true;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cost[i]);
	}
	
	if(block[0]){
		printf("-1\n");
		return 0;
	}
	int position=0;
	for(int i=0;i<n;i++){
		if(!block[i]){
			position = i;
		}
		prevpos[i]=position;
	}
	
	LL min=1e14;
	for(int step=1;step<=k;step++){
		LL count = 0, pos = 0;
		bool flag=true;
		//printf("hahaha\n");
		while(pos+step<n){
			int nextpos = prevpos[pos+step];
			if(nextpos<=pos){
				flag=false;
				break;
			}
			++count;
			pos = nextpos;
			//cout<<pos<<endl;
		}
		++count;
		
		if(flag){
			LL allcost = count*cost[step];
			if(allcost<min)min=allcost;
		}
	}
	if(min==1e14){
		printf("-1\n");
	}else{
		printf("%lld\n",min);
	}
	return 0;
}