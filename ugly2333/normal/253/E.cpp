//CF 253E
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
const int N = 55555;
struct node{
	LL t;
	LL s;
	int p;
	int id;
}a[N];
bool cmp(node x1,node x2){
	return x1.t<x2.t;
}
set<int> S;
priority_queue<pair<int,pair<LL,int> > > Q;
pair<int,pair<LL,int> > l;
LL h[N],ans[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,x,f;
	LL tt,rt,et;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%lld%lld%d",&a[i].t,&a[i].s,&a[i].p);
		a[i].id=i;
		S.insert(a[i].p);
	}
	scanf("%lld",&rt);
	sort(a+1,a+n+1,cmp);
	
	j=1;
	tt=0;
	f=0;
	while(j<=n||!Q.empty()){
		if(Q.empty()||tt==a[j].t){
			tt=a[j].t;
			Q.push(make_pair(a[j].p,make_pair(a[j].s,j)));
			if(a[j].p==-1)
				f=1,x=j;
			j++;
		}
		else{
			l=Q.top();
			Q.pop();
			if(j>n||tt+l.second.first<=a[j].t){
				h[l.second.second]+=l.second.first*f;
				tt+=l.second.first;
				if(l.first==-1)
					f=0,et=tt;
			}
			else{
				l.second.first-=a[j].t-tt;
				h[l.second.second]+=(a[j].t-tt)*f;
				Q.push(l);
				tt=a[j].t;
			}
		}
	}
	//cout<<tt<<endl;
	for(i=1;i<=n;i=i+1)
		if(h[i]&&a[i].p!=-1)
			Q.push(make_pair(-a[i].p,make_pair(h[i],i)));
	while(et>rt){
		l=Q.top();
		Q.pop();
		et-=l.second.first;
		f=2;
		//cout<<et<<rt<<endl;
	}
	if(f!=2)
		a[x].p=1;
	else
		a[x].p=-l.first+1;
	//cout<<l.first<<endl;
	while(S.find(a[x].p)!=S.end()){
		a[x].p++;
	}
	cout<<a[x].p<<endl;
	
	while(!Q.empty()){
		Q.pop();
	}
	j=1;
	tt=0;
	while(j<=n||!Q.empty()){
		if(Q.empty()||tt==a[j].t){
			tt=a[j].t;
			Q.push(make_pair(a[j].p,make_pair(a[j].s,a[j].id)));
			j++;
		}
		else{
			l=Q.top();
			Q.pop();
			if(j>n||tt+l.second.first<=a[j].t){
				tt+=l.second.first;
				ans[l.second.second]=tt;
			}
			else{
				l.second.first-=a[j].t-tt;
				tt=a[j].t;
				Q.push(l);
			}
		}
	}
	
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';/**/
	return 0;
}
/*
3
4 3 -1
0 2 2
1 3 3
7
*/