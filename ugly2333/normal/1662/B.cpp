//CF1662B
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
const int N = 33333;
const int M = 33;
int n,m=26,b[5][M],f[5],r[5];
char c[N];
int ans[N][2],l,h[N][5];
vector<int> v[5],t[5],w[5];
void go(int i,int x,int y){
	int j;
	l++;
	ans[l][0]=x;
	ans[l][1]=y;
	for(j=1;j<=3;j++){
		if(j!=i)
			h[l][j]=x;
		else
			h[l][j]=y;
	}
}
void incf(int i,int x){
	if(f[i]<0){
		go(i,x,t[i].back());
		t[i].pop_back();
	}
	else
		v[i].push_back(x);
	f[i]++;
}
void decf(int i,int x){
	if(f[i]>0){
		go(i,v[i].back(),x);
		v[i].pop_back();
	}
	else
		t[i].push_back(x);
	f[i]--;
}
void chf(int i,int x,int o){//if(o)cout<<i<<x<<o<<endl;
	if(o>=0){
		while(o--){
			incf(i,x);
		}
	}
	else{
		while(o++){
			decf(i,x);
		}
	}
}
int main()
{
	int i,j,x,y,z,o;
	for(i=1;i<=3;i++){
		scanf("%s",c+1);
		n=strlen(c+1);
		r[i]=n;
		for(j=1;j<=n;j++)
			b[i][c[j]-'A'+1]++;
	}
	for(j=1;j<=m;j++){
		x=0,y=0;
		for(i=1;i<=3;i++){
			x+=b[i][j];
			y=max(y,b[i][j]);
		}
		if(y*2>=x){
			for(i=1;i<=3;i++)
				if(b[i][j]==y)
					o=i;
			chf(o,j,x-y*2);
			for(i=1;i<=3;i++)
				if(o!=i)
					chf(o^i,j,b[i][j]);
		}
		else{
			if(x&1)
				go(1,j,j);
			for(i=1;i<=3;i++)
				chf(i,j,x/2-b[i][j]);
		}
	}
	x=0;
	for(i=1;i<=3;i++)
		x=max(x,f[i]);//cout<<l<<endl;
	while(1){
		x=0;
		for(i=1;i<=3;i++)
			x=max(x,f[i]);
		if(x==0)
			break;
		for(i=1;i<=3;i++)
			if(x==f[i])
				o=i;
		x=v[o].back();
		for(i=1;i<=3;i++)
			if(o!=i)
				decf(i,x);
		v[o].pop_back();
		f[o]--;
	}
	//cout<<l<<endl;
	for(i=1;i<=l;i++)
		for(j=1;j<=3;j++)
			b[j][h[i][j]]--,r[j]--;
	for(i=1;i<=3;i++)
		for(j=1;j<=m;j++)
			for(x=1;x<=b[i][j];x++)
				w[i].push_back(j);
	while(1){
		x=0;
		y=N;
		for(i=1;i<=3;i++){
			x+=r[i];
			y=min(y,r[i]);
		}
		if(x==0)
			break;
		l++;
		ans[l][0]=0,ans[l][1]=0;
		for(i=1;i<=3;i++){
			if(r[i]==y||r[i]==0){
				y=-1;
				continue;
			}
			if(ans[l][0])
				ans[l][1]=w[i].back();
			else
				ans[l][0]=w[i].back();
			w[i].pop_back();
			r[i]--;
		}
		if(ans[l][1]==0)
			ans[l][1]=ans[l][0];
	}
	printf("%d\n",l);
	for(i=1;i<=l;i++)
		printf("%c%c\n",ans[i][0]+64,ans[i][1]+64);
	return 0;
}