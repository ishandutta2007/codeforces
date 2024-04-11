//CF 804B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
const int m=1000*1000*1000+7;
char s[1111111];
int main()
{
	int n,i,x,ans;
	scanf("%s",s);
	n=strlen(s);
	ans=0;
	x=0;
	for(i=n-1;i>=0;i=i-1){
		if(s[i]=='a'){
			ans+=x;
			x*=2;
			ans%=m;
			x%=m;
		}
		else{
			x++;
			x%=m;
		}
	}
	printf("%d",ans);
	return 0;
}