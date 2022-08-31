//CF 251C
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
typedef double DB;
const int N = 444444;
LL a,b,c;
int A,B,k,n=360360;
int d[N],dd,he,ta,q[N];
void bfs(int s){
	int i,x,y;
	memset(d,0,sizeof(d));
	he=0,ta=0;
	d[s]=1,q[ta++]=s;
	while(he<ta){
		x=q[he++];
		for(i=1;i<=k;i=i+1){
			y=x-max(1,x%i);
			if(y<0)
				y+=n;
			if(!s&&!y&&!dd)
				dd=d[x];
			if(!d[y])
				d[y]=d[x]+1,q[ta++]=y;
		}
	}
}
int main()
{
	cin>>a>>b>>k;
	A=a%n,B=b%n;
	if(a/n==b/n){
		bfs(A);
		c=d[B]-1;
	}
	else{
		bfs(A);
		c=d[0]-1;
		a-=A;
		bfs(0);
		c+=d[B]-1;
		b-=B;
		c+=(a-b-1)/n*dd;
	}
	cout<<c;
	return 0;
}