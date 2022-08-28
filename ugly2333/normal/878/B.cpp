//CF 878B
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
const int Q = 60;
int n,k,m;
int a[N];
LL ans[Q],len[Q];
int b[Q][N],bb[Q][N],e[Q][N],ee[Q][N];
int p[N*2],pp[N*2];
LL solve(int q,int x,int y){// q=x+y
	int i,j,t;
	LL res;
	memset(p,0,sizeof(p));
	memset(pp,0,sizeof(pp));
	//cout<<q<<x<<y<<endl;
	len[q]=len[x]+len[y];
	ans[q]=ans[x]+ans[y];
	//cout<<len[q]<<' '<<q<<endl;
	t=0;
	for(i=min((LL)n,len[x]);i>=1;i=i-1){
		t++;
		p[t]=e[x][i];
		pp[t]=ee[x][i];
	}
	for(i=1;i<=n&&i<=len[y];i=i+1){
		if(p[t]==b[y][i]){
			pp[t]+=bb[y][i];
			len[q]--;
			if(pp[t]>=k){
				res++;
				pp[t]-=k;
				ans[q]-=k;
				if(!pp[t]){
					t--;
					len[q]--;
				}
			}
		}
		else{
			t++;
			p[t]=b[y][i];
			pp[t]=bb[y][i];
		}
	}
	//for(i=1;i<=t;i=i+1)
	//	cout<<p[i]<<pp[i]<<endl;
	//cout<<len[q]<<' '<<ans[q]<<endl;
	i=1;
	while(i<=n&&i<=len[q]&&i<=len[x]-n){
		b[q][i]=b[x][i];
		bb[q][i]=bb[x][i];
		i++;
	}
	j=1;
	while(i<=n&&i<=len[q]&&j<=t){
		b[q][i]=p[j];
		bb[q][i]=pp[j];
		i++;
		j++;
	}
	j=len[y]-n;
	while(i<=n&&i<=len[q]&&j>=1){
		b[q][i]=e[y][j];
		bb[q][i]=ee[y][j];
		i++;
		j--;
	}
	
	i=1;
	while(i<=n&&i<=len[q]&&i<=len[y]-n){
		e[q][i]=e[y][i];
		ee[q][i]=ee[y][i];
		i++;
	}
	j=t;
	while(i<=n&&i<=len[q]&&j>=1){
		e[q][i]=p[j];
		ee[q][i]=pp[j];
		i++;
		j--;
	}
	j=len[q]-n;
	while(i<=n&&i<=len[x]&&j>=1){
		e[q][i]=b[x][j];
		ee[q][i]=bb[x][j];
		i++;
		j--;
	}
	
}
int main()
{
	int i,j,t,s,x;
	scanf("%d%d%d",&n,&k,&m);
	ans[0]=n;
	t=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(b[0][t]==a[i]){
			bb[0][t]++;
			if(bb[0][t]==k){
				t--;
				ans[0]-=k;
			}
		}
		else{
			t++;
			b[0][t]=a[i];
			bb[0][t]=1;
		}
	}
	len[0]=t;
	for(i=1;i<=t;i=i+1){
		e[0][t-i+1]=b[0][i];
		ee[0][t-i+1]=bb[0][i];
	}
	s=1;
	while(m>>s){
		solve(s,s-1,s-1);
		s++;
	}
	s--;
	x=s;
	t=0;
	while(t<x){
		if(m&1){
			s++;
			solve(s,s-1,t);
		}
		t++;
		m>>=1;
	}
	cout<<ans[s]<<endl;
	return 0;
}
/*
7 3 99
1 3 3 3 2 1 1

4 2 5
1 2 3 1

1 9 10
1
*/