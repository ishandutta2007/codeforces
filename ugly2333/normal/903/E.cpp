//CF 900E
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
const int N = 5005;
int n,k,s[N],ss[N],se;
char ch[N][N];
vector<int> v[N];
bool chk(int p,int v1,int v2){
	int i,a[11],sz,r;
	sz=0;
	for(i=0;i<v[p].size();i=i+1)
		a[sz++]=v[p][i];
	a[sz++]=v1,a[sz++]=v2;
	sort(a,a+sz);
	sz=unique(a,a+sz)-a;
	r=0;
	for(i=0;i<sz&&r<=2;i=i+1)
		if(ch[0][a[i]]!=ch[p][a[i]])
			r++;
	if(r==2)
		return 1;
	if(se&&!r)
		return 1;
	return 0;
}
int main()
{
	int i,j,o,fl;
	cin>>k>>n;
	for(i=0;i<k;i=i+1)
		cin>>ch[i];
	for(i=0;i<n;i=i+1)
		s[ch[0][i]]++;
	for(i=1;i<k;i=i+1){
		memset(ss,0,sizeof(ss));
		for(j=0;j<n;j=j+1)
			ss[ch[i][j]]++;
		for(j='a';j<='z';j=j+1)
			if(s[j]!=ss[j]){
				cout<<-1<<endl;
				return 0;
			}
		for(j=0;j<n;j=j+1)
			if(ch[0][j]!=ch[i][j])
				v[i].push_back(j);
		if(v[i].size()>4){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(i='a';i<='z';i=i+1)
		if(s[i]>1)
			se=1;
	for(i=0;i<n;i=i+1){
		for(j=i+1;j<n;j=j+1){
			swap(ch[0][i],ch[0][j]);
			fl=1;
			for(o=1;o<k;o=o+1)
				if(!chk(o,i,j)){
					fl=0;
					break;
				}
			if(fl){
				for(i=0;i<n;i=i+1)
					cout<<ch[0][i];
				return 0;
			}
			swap(ch[0][i],ch[0][j]);
		}
	}
	cout<<-1<<endl;
	return 0;
}