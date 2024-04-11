//CF 900C
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
typedef long long LL;
const int N = 111111;
int a[N],s[N];
int main()
{
	int n,i,mx,y,mx2,y2;
	scanf("%d",&n);
	mx=0,y=0,mx2=0,y2=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(mx<a[i]){
			mx2=mx,y2=y;
			mx=a[i],y=i;
			s[i]--;
		}
		else{
			if(mx2<a[i])
				mx2=a[i],y2=i,s[y]++;
		}
	}
	mx=-N,y=N;
	for(i=1;i<=n;i=i+1)
		if((mx==s[i]&&y>a[i])||mx<s[i])
			mx=s[i],y=a[i];
	cout<<y<<endl;
	return 0;
}