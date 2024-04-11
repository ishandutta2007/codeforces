//CF 891B
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
const int N = 27;
int a[N],b[N],c[N];
pair<int,int> p[N];
int main()
{
	int n,i,j,m;
	LL x;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		p[i]=make_pair(a[i],i);
	}
	sort(p+1,p+n+1);
	for(i=1;i<n;i=i+1)
		if(p[i].first==p[i+1].first){
			cout<<-1<<endl;
			return 0;
		}
	for(i=1;i<=n;i=i+1){
		j=i+1;
		if(j>n)
			j=1;
		while(b[j]){//||p[j].first==p[i].first){
			j++;
			if(j>n)
				j=1;
			/*if(j==i){
				cout<<-1<<endl;
				return 0;
			}*/
		}
		//cout<<j<<endl;
		b[j]=p[i].second;
		c[p[j].second]=p[i].first;
	}
	//for(i=1;i<=n;i=i+1)
	//	cout<<c[i]<<' ';
	/*m=1<<n;
	for(i=1;i<m-1;i=i+1){
		x=0;
		for(j=0;j<n;j=j+1)
			if(i&(1<<j))
				x+=(LL)a[j+1]-c[j+1];
		if(!x){
			cout<<-1<<endl;
			return 0;
		}
	}*/
	for(i=1;i<=n;i=i+1)
		cout<<c[i]<<' ';
	return 0;
}