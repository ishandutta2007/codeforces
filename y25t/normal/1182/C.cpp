#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100005

int n;

inline bool check(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

struct node{
	int a,b;
	string s;
}a[N];
inline bool cmp(node u,node v){
	if(u.a!=v.a)
		return u.a<v.a;
	return u.b<v.b;
}

bool vis[N];

struct nnode{
	int a,b;
};
queue<nnode> q[2];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		int m=a[i].s.length();
		for(int j=0;j<m;j++)
			if(check(a[i].s[j])){
				a[i].a++;
				a[i].b=a[i].s[j];
			}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(a[i].a==a[i+1].a&&a[i].b==a[i+1].b&&i!=n){
			vis[i]=vis[i+1]=1;
			q[0].push((nnode){i,i+1});
			i++;
		}
	int tmp=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			if(a[i].a==a[tmp].a){
				q[1].push((nnode){tmp,i});
				tmp=0;
			}
			else
				tmp=i;
		}
	int n0=q[0].size(),n1=q[1].size(),ans=0;
	if(n0<=n1)
		ans=n0;
	else
		ans=n1+(n0-n1)/2;
	printf("%d\n",ans);
	while(!q[0].empty()&&!q[1].empty()){
		nnode u=q[0].front(),v=q[1].front();
		q[0].pop();
		q[1].pop();
		cout<<a[v.a].s<<' '<<a[u.a].s<<'\n'<<a[v.b].s<<' '<<a[u.b].s<<'\n';
	}
	while(q[0].size()>1){
		nnode u=q[0].front();
		q[0].pop();
		nnode v=q[0].front();
		q[0].pop();
		cout<<a[v.a].s<<' '<<a[u.a].s<<'\n'<<a[v.b].s<<' '<<a[u.b].s<<'\n';
	}
}