#include<bits/stdc++.h>
using namespace std;
//int n;
//char s[1<<19];
//const int p=998244353;
int a[210000];
int b[210000],c[210000];
int cc[210000],ccc[210000];
int main(){
//	cin>>n;
//	scanf("%s",s+1);
	int _;
	cin>>_;
	while(_--){
		int n,x,maxx=0;
		cin>>n>>x;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		if(maxx>=x){
			long long ans=0;int minn=min(a[1]-1,a[n]-1);
			for(int i=1;i<n;i++)ans+=abs(a[i]-a[i+1]);
			for(int i=1;i<n;i++)minn=min(minn,2*min(a[i],a[i+1])-2);
			cout<<ans+minn<<endl;
			continue;
		}
		long long ans=0;int minn=x-1+min(min(a[1]-1,x-a[1]),min(a[n]-1,x-a[n]));
		for(int i=1;i<n;i++)ans+=abs(a[i]-a[i+1]);
		b[0]=a[1]-1;
		b[n]=a[n]-1;
		for(int i=1;i<n;i++)b[i]=2*min(a[i],a[i+1])-2;
		c[0]=x-a[1];
		c[n]=x-a[n];
		for(int i=1;i<n;i++)c[i]=2*(x-max(a[i],a[i+1]));
		cc[0]=10000000;
		for(int i=0;i<=n;i++)cc[i+1]=min(cc[i],c[i]);
		ccc[n]=10000000;
		for(int i=n-1;i>=0;i--)ccc[i]=min(ccc[i+1],c[i+1]);
		for(int i=0;i<=n;i++)minn=min(minn,b[i]+min(cc[i],ccc[i]));
		cout<<ans+minn<<endl;
	}
	return 0;
}