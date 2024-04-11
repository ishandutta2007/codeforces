//CF1608E
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
const int inf = 2e9;
int n,m,ans,x[N],y[N],z[N];
vector<int> v[4];
int p[4];
void solve1(){
	int i,j,k,o;
	for(i=1;i<=3;i++)
		v[i].clear();
	for(i=1;i<=n;i++)
		v[z[i]].push_back(x[i]);
	for(i=1;i<=3;i++)
		v[i].push_back(inf),sort(v[i].begin(),v[i].end());
	for(i=1;i<=n;i++){
		o=-inf;
		for(j=1;j<=3;j++){
			k=upper_bound(v[p[j]].begin(),v[p[j]].end(),o)-v[p[j]].begin();
			k+=i-1;
			if(k>=m)
				return;
			o=v[p[j]][k];
		}
		ans=max(ans,i);
	}
}
set<pair<int,int> > s2,s3,q2,q3;
pair<int,int> f[N];
void del2(pair<int,int> a){
	if(q2.find(a)!=q2.end()){
		q2.erase(a);
		return;
	}
	if(s2.find(a)!=s2.end()){
		s2.erase(a);
		a=*q2.begin();
		s2.insert(a);
		q2.erase(a);
	}
}
void del3(pair<int,int> a){
	if(q3.find(a)!=q3.end()){
		q3.erase(a);
		return;
	}
	if(s3.find(a)!=s3.end()){
		s3.erase(a);
		a=*q3.rbegin();
		s3.insert(a);
		q3.erase(a);
	}
}
void inck(){
	pair<int,int> a;
	a=*q2.begin();
	s2.insert(a);
	q2.erase(a);
	a=*q3.rbegin();
	s3.insert(a);
	q3.erase(a);
}
void solve2(){
	int i,j,k,o;
	q2.clear(),q3.clear(),s2.clear(),s3.clear();
	for(i=1;i<=n;i++){
		f[i]=make_pair(x[i],i);
		if(z[i]==p[2])
			q2.insert(make_pair(y[i],i));
		if(z[i]==p[3])
			q3.insert(make_pair(y[i],i));
	}
	q2.insert(make_pair(inf,0));
	q3.insert(make_pair(-inf,0));
	s2.insert(make_pair(-inf,0));
	s3.insert(make_pair(inf,0));
	sort(f+1,f+n+1);
	k=0;
	for(i=1;i<=n;i++){
		j=f[i].second;
		if(z[j]==p[1])
			k++,inck();
		else{
			if(z[j]==p[2])
				del2(make_pair(y[j],j));
			else
				del3(make_pair(y[j],j));
		}
		if((*s2.rbegin()).first>=(*s3.begin()).first)
			return;
		if(f[i].first<f[i+1].first)
			ans=max(ans,k);
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	m=n/3;
	for(i=1;i<=n;i++)
		scanf("%d%d%d",x+i,y+i,z+i);
	ans=0;
	for(i=1;i<=3;i++)
		p[i]=i;
	do{
		solve1();
		for(i=1;i<=n;i++)
			swap(x[i],y[i]);
		solve1();
		for(i=1;i<=n;i++)
			swap(x[i],y[i]);
		solve2();
		for(i=1;i<=n;i++)
			x[i]=-x[i];
		solve2();
		for(i=1;i<=n;i++)
			x[i]=-x[i];
		for(i=1;i<=n;i++)
			swap(x[i],y[i]);
		solve2();
		for(i=1;i<=n;i++)
			x[i]=-x[i];
		solve2();
		for(i=1;i<=n;i++)
			x[i]=-x[i];
		for(i=1;i<=n;i++)
			swap(x[i],y[i]);
	}while(next_permutation(p+1,p+4));
	printf("%d\n",ans*3);
	return 0;
}