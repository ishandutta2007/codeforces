#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
int a[3];
signed main()
{
	int d;
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	printf("%d\n",max(0,d-a[1]+a[0])+max(0,d-a[2]+a[1]));
	return 0;
}