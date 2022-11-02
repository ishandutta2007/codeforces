#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int a,b,c;
int k[2000];
int main(){
	memset(k,0,sizeof(k));
	scanf("%d%d%d",&a,&b,&c);
	if(a==1||b==1||c==1){
		printf("YES\n");
		return 0;
	}
	k[a]++,k[b]++,k[c]++;
	if(k[2]>=2){
		printf("YES\n");
		return 0;
	}
	if(k[2]==1&&k[4]==2){
		printf("YES\n");
		return 0;
	}
	if(k[3]==3){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}