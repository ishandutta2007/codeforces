//CF 1005E
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
const int M = 444444;
int n,k,a[N];
vector<int> p[M],q[M];
int T[M];
void ad(int x){
	while(x<M){
		T[x]++;
		x+=x&-x;
	}
}
int qu(int x){
	int y=0;
	while(x){
		y+=T[x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,j,x,y;
	LL ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(a[i]==k)
			a[i]=0;
		else{
			if(a[i]>k)
				a[i]=1;
			else
				a[i]=-1;
		}
	}
	x=0,y=0;
	for(i=1;i<=n;i=i+1){
		p[x-y+N].push_back(x+y+N);
		q[x-y+N].push_back(x+y-1+N);
		if(a[i])
			y+=a[i];
		else
			x++;
		//cout<<x<<y<<endl;
		if(i==n){
			p[x-y+N].push_back(x+y+N);
			q[x-y+N].push_back(x+y-1+N);
		}
	}
	ans=0;
	for(i=0;i<M;i=i+1){
		for(j=p[i].size();j--;)
			ad(p[i][j]);
		for(j=q[i].size();j--;)
			ans+=qu(q[i][j]);
	}
	cout<<ans;
	return 0;
}