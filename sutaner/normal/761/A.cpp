#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==0&&b==0){printf("NO");return 0;}
	if(abs(a-b)<=1) printf("YES");
	else printf("NO");
	return 0;
}