//CF1662H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int B = 1e5;
set<int> S;
set<int>::iterator it;
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		S.clear();
		S.insert(1);
		S.insert(2);
		for(i=1;i<=B;i++){
			y-=2;
			if(x%i==0){
				if(y%i==0)
					S.insert(i);
				if(y%(x/i)==0)
					S.insert(x/i);
			}
			x--;
			y++;
			if(x%i==0){
				if(y%i==0)
					S.insert(i);
				if(y%(x/i)==0)
					S.insert(x/i);
			}
			x--;
			y++;
			if(x%i==0){
				if(y%i==0)
					S.insert(i);
				if(y%(x/i)==0)
					S.insert(x/i);
			}
			x+=2;
		}
		printf("%d",S.size());
		for(it=S.begin();it!=S.end();it++)
			printf(" %d",*it);
		printf("\n");
	}
	return 0;
}