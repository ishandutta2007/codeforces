#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int f[MAXN];
int ancester(int x){
	return (f[x]==x)?f[x]:f[x]=ancester(f[x]);
}
void unite(int x,int y){
	f[ancester(x)]=ancester(y);
}
int n;
int a[MAXN];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(i+x<=n)	unite(i,i+x);
		if(i-x>=1)	unite(i,i-x);
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(ancester(i)==i){
			int c[105]={};
			for(int j=1;j<=n;j++)
				if(ancester(j)==i)
					c[j]++,c[a[j]]--;
			for(int j=1;j<=n;j++)
				if(c[j])
					flag=false;
		}
	}
	puts(flag?"YES":"NO");
}