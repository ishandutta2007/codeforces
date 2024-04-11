//CF1553C
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
const int N = 22;
int n=10;
char s[N];
bool ed(int x,int a,int b){
	x=10-x;
	return x==0||a+x/2<b||a>b+(x+1)/2;
}
int cal(int x){
	int i,a=0,b=0;
	for(i=1;i<=10;i++){
		if(s[i]=='?'){
			if(i&1){
				if(x)
					a++;
			}
			else{
				if(!x)
					b++;
			}
		}
		else{
			if(s[i]=='1'){
				if(i&1)
					a++;
				else
					b++;
			}
		}
		if(ed(i,a,b))
			return i;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		printf("%d\n",min(cal(1),cal(0)));
	}
	return 0;
}