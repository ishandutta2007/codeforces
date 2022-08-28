//CF1662I
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
const int N = 222222;
const int M = 2e7+27;
const int inf = 2e9;
int n,m,a[M],p[N];
LL s[N];
LL solve(int l,int r){
	int tl=l/100+1,tr=min(n,(r-1)/100),i,j;
	LL t,x=0;
	if(tl>tr)
		return 0;
	if(tl==tr)
		return a[tl];//cout<<tl<<tr<<endl;
	j=tl;
	t=a[tl];
	for(i=tl;i<=tr&&i<=n;i++){
		while(j<tr&&(j+1-i)*100<r-(j+1)*100+i*100-l){
			j++;
			t+=a[j];
		}//cout<<i<<' '<<j<<' '<<t<<endl;
		x=max(x,t);
		t-=a[i];
	}//cout<<x<<endl;
	return x;
}
int main()
{
	int i;
	LL x;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",a+i),s[i]=s[i-1]+a[i];
	for(i=1;i<=m;i++)
		scanf("%d",p+i);
	sort(p+1,p+m+1);
	p[m+1]=inf;
	if(p[1]!=0)
	    x=s[min(n-1,(p[1]-1)/100)];
	else
	    x=0;
	for(i=2;i<=m+1;i++)
		x=max(x,solve(p[i-1],p[i]));
	printf("%lld\n",x);
	return 0;
}