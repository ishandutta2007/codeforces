//CF 578E
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
int n,a[N],b[N];
vector<int> v[N],q[2];
char ch[N];
void mrg(int x,int y){
	for(int i=0;i<v[y].size();i=i+1)
		v[x].push_back(v[y][i]);
	b[x]=*v[x].rbegin();
	b[y]=0;
}
int main()
{
	int i,j,x,y,s=0;
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=1;i<=n;i=i+1){
		a[i]=ch[i]=='R';
		v[i].push_back(i);
		b[i]=i;
		x=a[i]^1;
		if(q[x].size()){
			j=*q[x].rbegin();
			q[x].pop_back();
			mrg(j,i);
		}
		else{
			j=i;
			s++;
		}
		q[a[b[j]]].push_back(j);
	}
	printf("%d\n",s-1);
	q[0].clear(),q[1].clear();
	for(i=1;i<=n;i=i+1){
		if(!b[i])
			continue;
		x=a[i]^1;
		if(q[x].size()){
			j=*q[x].rbegin();
			q[x].pop_back();
			mrg(j,i);
		}
		else
			j=i;
		q[a[b[j]]].push_back(j);
	}
	q[0].clear(),q[1].clear();
	for(i=n;i;i=i-1){
		if(!b[i])
			continue;
		x=a[i]^1;
		if(q[x].size()){
			j=*q[x].rbegin();
			q[x].pop_back();
			mrg(j,i);
		}
		else
			j=i;
		q[a[b[j]]].push_back(j);
	}
	if(q[0].size()&&q[1].size()){
		i=q[0][0],j=q[1][0];
		x=*v[i].rbegin(),y=*v[j].rbegin();
		if(x>y)
			swap(i,j),swap(x,y);
		v[i].push_back(y);
		v[j].pop_back();
		mrg(i,j);
		s=i;
	}
	else{
		if(q[0].size())
			s=q[0][0];
		else
			s=q[1][0];
	}
	for(i=0;i<n;i=i+1)
		printf("%d ",v[s][i]);
	return 0;
}