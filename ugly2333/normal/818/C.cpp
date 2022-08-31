// CF 818C
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
int x[111111][3],y[111111][3];
int lx[111111],ly[111111],rx[111111],ry[111111],c[111111],f[111111];
int main()
{
	int d,n,m,i,j,s,p,l,r,t,b;
	scanf("%d%d%d",&d,&n,&m);
	for(i=1;i<=d;i=i+1){
		scanf("%d%d%d%d",lx+i,ly+i,rx+i,ry+i);
		if(lx[i]>rx[i])
			swap(lx[i],rx[i]);
		if(ly[i]>ry[i])
			swap(ly[i],ry[i]);
		if(lx[i]==rx[i]){
			x[lx[i]][0]++;
			y[ly[i]][1]++;
			y[ry[i]][2]++;
			c[i]=1;
		}
		else{
			x[lx[i]][1]++;
			x[rx[i]][2]++;
			y[ly[i]][0]++;
			c[i]=0;
		}
		f[i]=0;
	}
	
	scanf("%d%d%d%d",&l,&r,&t,&b);
	s=0;
	j=-1;
	for(i=1;i<=n;i=i+1){
		if(x[i][0]){
			if(s==l){
				j=1;
				break;
			}
		}
		if(x[i][2]){
			if(s-1==l){
				j=0;
				break;
			}
		}
		s+=x[i][0]+x[i][1];
	}
	p=i;
	if(j!=-1){
		for(i=1;i<=d;i=i+1)
			if(rx[i]==p&&c[i]==j)
				f[i]++;
	}
	
	s=0;
	j=-1;
	for(i=n;i>=1;i=i-1){
		if(x[i][0]){
			if(s==r){
				j=1;
				break;
			}
		}
		if(x[i][1]){
			if(s-1==r){
				j=0;
				break;
			}
		}
		s+=x[i][0]+x[i][2];
	}
	p=i;
	if(j!=-1){
		for(i=1;i<=d;i=i+1)
			if(lx[i]==p&&c[i]==j)
				f[i]++;
	}
	
	s=0;
	j=-1;
	for(i=1;i<=m;i=i+1){
		if(y[i][0]){
			if(s==t){
				j=0;
				break;
			}
		}
		if(y[i][2]){
			if(s-1==t){
				j=1;
				break;
			}
		}
		s+=y[i][0]+y[i][1];
	}
	p=i;
	if(j!=-1){
		for(i=1;i<=d;i=i+1)
			if(ry[i]==p&&c[i]==j)
				f[i]++;
	}
	
	s=0;
	j=-1;
	for(i=m;i>=1;i=i-1){
		if(y[i][0]){
			if(s==b){
				j=0;
				break;
			}
		}
		if(y[i][1]){
			if(s-1==b){
				j=1;
				break;
			}
		}
		s+=y[i][0]+y[i][2];
	}
	p=i;
	if(j!=-1){
		for(i=1;i<=d;i=i+1)
			if(ly[i]==p&&c[i]==j)
				f[i]++;
	}
	
	for(i=1;i<=d;i=i+1)
		if(f[i]==4){
			cout<<i<<endl;
			return 0;
		}
	cout<<-1<<endl;
	return 0;
}