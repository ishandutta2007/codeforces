//CF 913D
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
const int N = 222222;
int n,l,a[N],t[N];
vector<pair<int,int> > v[N];
priority_queue<pair<int,int> > Q;
int main()
{
	int i,j,s,ss,ans;
	scanf("%d%d",&n,&l);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,t+i);
		v[a[i]].push_back(make_pair(t[i],i));
	}
	s=0,ss=0;
	for(i=n;i>=0;i=i-1){
		j=v[i].size();
		while(j--){
			s++;
			ss+=v[i][j].first;
			Q.push(v[i][j]);
		}
		while(ss>l||s>i){
			s--;
			ss-=Q.top().first;
			Q.pop();
		}
		if(s==i){
			cout<<s<<endl;
			cout<<s<<endl;
			while(!Q.empty()){
				cout<<Q.top().second<<' ';
				Q.pop();
			}
			return 0;
		}
	}
	return 0;
}