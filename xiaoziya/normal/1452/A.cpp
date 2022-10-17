#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(abs(x-y)<=1)
			printf("%d\n",x+y);
		else{
			if(x>y)
				swap(x,y);
			printf("%d\n",x+x+1+2*(y-x-1));
		}
	}
	return 0;
}