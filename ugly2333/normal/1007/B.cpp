//CF1007B
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
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
LL w[N],r[8];
int e[8][8][8];
int qa[4]={1,3,5,7};
int qb[4]={2,3,6,7};
int qc[4]={4,5,6,7};
LL solve(int i,int j,int k){
	if(i>j)
		swap(i,j);
	if(i>k)
		swap(i,k);
	if(j>k)
		swap(j,k);
	if(e[i][j][k])
		return 0;
	e[i][j][k]=1;
	if(i==k)
		return r[i]*(r[i]+1)*(r[i]+2)/6;
	if(i==j)
		return r[i]*(r[i]+1)*r[k]/2;
	if(j==k)
		return r[i]*r[j]*(r[j]+1)/2;
	return r[i]*r[j]*r[k];
}
int main()
{
	int T,a,b,c,i,j,k;
	LL s;
	for(i=1;i<N;i=i+1)
		for(j=i;j<N;j=j+i)
			w[j]++;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		for(i=0;i<8;i=i+1)
			r[i]=0;
		for(i=7;i;i=i-1){
			s=0;
			if(i&1)
				s=gcd(s,a);
			if(i&2)
				s=gcd(s,b);
			if(i&4)
				s=gcd(s,c);
			r[i]+=w[s];
			for(j=1;j<i;j=j+1)
				if((i|j)==i)
					r[j]-=r[i];
		}
		//for(i=1;i<8;i=i+1)
		//	cout<<r[i]<<' ';
		//cout<<endl;
		memset(e,0,sizeof(e));
		s=0;
		for(i=0;i<4;i=i+1)
			for(j=0;j<4;j=j+1)
				for(k=0;k<4;k=k+1)
					s+=solve(qa[i],qb[j],qc[k]);
		cout<<s<<endl;
	}
	return 0;
}