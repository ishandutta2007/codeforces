#include<cstdio>
#include<cstdlib>
#define maxn 100005
#define maxn2 18
#define LL long long int
#define k1 ans=max(ans,DP(pos+1,1)+geo[pos+1][0])    
#define k2 ans=max(ans,DP(pos+1,2)+geo[pos+1][1])    
#define k3 ans=max(ans,DP(pos+1,3)+geo[pos+1][2])    
//#define k4 ans=max(ans,DP(pos+1,4)+geo[pos+1][0]+geo[pos+1][1])    
//#define k5 ans=max(ans,DP(pos+1,5)+geo[pos+1][0]+geo[pos+1][2])    
//#define k6 ans=max(ans,DP(pos+1,6)+geo[pos+1][2]+geo[pos+1][1])    
#define k7 ans=max(ans,DP(pos+1,7)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k8 ans=max(ans,DP(pos+1,8)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k10 ans=max(ans,DP(pos+1,10)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k11 ans=max(ans,DP(pos+1,11)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k12 ans=max(ans,DP(pos+1,12)+geo[pos+1][0]+geo[pos+1][1])    
#define k13 ans=max(ans,DP(pos+1,13)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k14 ans=max(ans,DP(pos+1,14)+geo[pos+1][2]+geo[pos+1][1])    
#define k15 ans=max(ans,DP(pos+1,15)+geo[pos+1][0]+geo[pos+1][1])    
#define k16 ans=max(ans,DP(pos+1,16)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])    
#define k17 ans=max(ans,DP(pos+1,17)+geo[pos+1][2]+geo[pos+1][1])    
#define k18 ans=max(ans,DP(pos+1,18)+geo[pos+1][0]+geo[pos+1][1]+geo[pos+1][2])
using namespace std;
LL max(LL a,LL b){
	if(a>b)return a;
	return b;
}
/*
Stable......
	1      2      3      4      5      6      7      8    NULL    10     11     12     13     14     15     16     17     18            
-------------------------------------------------------------------------------------------------------------------------------
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
|******|      |      |******|******|      |******|****  |***   |******|   ***|****  |****  |      |   ***|   ***|      |******|
|      |      |      |      |      |      |      |   *  |  *   |      |   *  |   *  |   *  |      |   *  |   *  |      |      |
-----------------------------------------------------*-----*--------------*------*------*-------------*------*-----------------
|      |      |      |      |      |      |      |   *  |  *   |      |   *  |   *  |   *  |      |   *  |   *  |      |      |
|      |******|      |******|      |******|****  |****  |  *   |   ***|   ***|   ***|   *  |****  |****  |   *  |   ***|******|
|      |      |      |      |      |      |   *  |      |  *   |   *  |      |      |   *  |   *  |      |   *  |   *  |      |   
----------------------------------------------*------------*-------*--------------------*------*-------------*------*-----------
|      |      |      |      |      |      |   *  |      |  *   |   *  |      |      |   *  |   *  |      |   *  |   *  |      |  
|      |      |******|      |******|******|****  |******|***   |   ***|******|      |   ***|   ***|      |****  |****  |******|
|      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
-------------------------------------------------------------------------------------------------------------------------------------------
*/
LL INF;
LL dp[maxn][maxn2];
LL geo[maxn][3];
int n;
LL DP(int pos,int op){
	if(dp[pos][op])return dp[pos][op];
	LL& ans=dp[pos][op]=-INF;
	if(pos==n-1){
		if(op==3||op==8||op==13||op==14)return ans=0;
		return ans;
	}
	else{
		switch(op){
			case 1:{
				k1;k10;k12;k13;
				return ans;
				break;
			}
			case 2:{
				k2;k14;k15;
				return ans;
				break;
			}case 3:{
			    k3;k11;k16;k17;
				return ans;
				break;
			}case 7:{
				k1;k10;k12;k13;
				return ans;
				break;
			}case 8:{
				k3;k11;k16;k17;
				return ans;
				break;
			}case 10:{
				k18;k8;
				return ans;
				break;
			}case 11:{
				k18;k7;
				return ans;   
				break;
			}case 12:{
				k2;k14;k15;
				return ans;
				break;
			}case 13:{
				k3;k11;k16;k17;
				return ans;
				break;
			}case 14:{
				k3;k11;k16;k17;
				return ans;
				break;
			}case 15:{
				k1;k10;k12;k13;
				return ans;
				break;
			}case 16:{
				k1;k10;k12;k13;
				return ans;
				break;
			}case 17:{
				k2;k14;k15;
				return ans;
				break;
			}case 18:{
				k7;k8;k18;
				return ans;
				break;
			}
		}	
	return ans;
	}
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			scanf("%I64d",&geo[j][i]);
		}
	}
	INF=2;
	for(int i=0;i<17;i++)INF*=10;
	LL ans=-INF;
	int pos=-1;
	k1;k10;k12;k13;
	printf("%I64d",ans);
	return 0;
}