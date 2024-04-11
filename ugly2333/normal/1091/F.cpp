//CF1091F
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
const int N = 111111;
int n;
LL a[N],b[N];
char c[N],d[N];
set<int> G,W;
int main()
{
	int i,j,f;
	LL x,y=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i);
	scanf("%s",c+1);
	j=0;
	for(i=1;i<=n;i=i+1){
		if(!a[i])
			continue;
		if(c[i]!=d[j]){
			j++;
			d[j]=c[i];
			b[j]=a[i];
		}
		else
			b[j]+=a[i];
	}
	n=j;
	f=0;
	G.clear(),W.clear();
	for(i=1;i<=n;i=i+1){
		if(d[i]=='G'){
			G.insert(i);
			continue;
		}
		if(d[i]=='W'){
			W.insert(i);
			f=1;
			continue;
		}
		while(W.size()&&b[i]){
			j=*W.rbegin();
			x=min(b[i],b[j]);
			b[i]-=x,b[j]-=x;
			y+=x*4;
			if(!b[j])
				W.erase(j);
		}
		while(G.size()&&b[i]){
			j=*G.begin();
			x=min(b[i],b[j]);
			b[i]-=x,b[j]-=x;
			y+=x*6;
			if(!b[j])
				G.erase(j);
		}
		if(b[i]){
			if(f)
				y+=b[i]*4;
			else
				y+=b[i]*6;
			b[i]=0;
		}
	}
	for(i=1;i<=n;i=i+1)
		a[i]=b[i],c[i]=d[i];
	j=0;
	for(i=1;i<=n;i=i+1){
		if(!a[i])
			continue;
		if(c[i]!=d[j]){
			j++;
			d[j]=c[i];
			b[j]=a[i];
		}
		else
			b[j]+=a[i];
	}
	n=j;
	W.clear();
	for(i=1;i<=n;i=i+1){
		if(d[i]=='W'){
			W.insert(i);
			continue;
		}
		while(W.size()&&b[i]){
			j=*W.rbegin();
			x=min(b[i],b[j]);
			b[i]-=x,b[j]-=x;
			y+=x*4;
			if(!b[j])
				W.erase(j);
		}
		if(b[i])
			y+=b[i]*3,b[i]=0;
	}
	for(i=1;i<=n;i=i+1)
		y+=b[i]*2;
	cout<<y;
	return 0;
}