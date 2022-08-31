//CF 909D
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
const int N = 1111111;
char ch[N];
int n,a[N],pr[N],nx[N],inq[N];
void del(int k){
	nx[pr[k]]=nx[k];
	pr[nx[k]]=pr[k];
}
queue<int> Q;
vector<int> v;
bool chk(int k){
	if(pr[k]&&a[k]!=a[pr[k]])
		return 1;
	if(nx[k]<=n&&a[k]!=a[nx[k]])
		return 1;
	return 0;
}
int main()
{
	int i,j,ans=0;
	scanf("%s",ch+1);
	ch[0]='_';
	n=strlen(ch)-1;
	for(i=1;i<=n;i=i+1)
		a[i]=ch[i];
	for(i=0;i<=n;i=i+1)
		nx[i]=i+1;
	for(i=1;i<=n+1;i=i+1)
		pr[i]=i-1;
	for(i=1;i<=n;i=i+1)
		if(chk(i))
			Q.push(i),inq[i]=1;
	inq[0]=1,inq[n+1]=1;
	while(1){
		if(!Q.empty())
			ans++;
		else{
			cout<<ans<<endl;
			return 0;
		}
		v.clear();
		while(!Q.empty()){
			j=Q.front();
			Q.pop();
			if(!inq[pr[j]])
				v.push_back(pr[j]);
			if(!inq[nx[j]])
				v.push_back(nx[j]);
			del(j);
		}
		j=v.size();
		for(i=0;i<j;i=i+1)
			if(!inq[v[i]]&&chk(v[i]))
				Q.push(v[i]),inq[v[i]]=1;
	}
	return 0;
}