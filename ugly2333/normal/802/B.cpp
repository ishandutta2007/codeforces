//CF 802 A,B
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
int a[888888],f[888888],t[888888];
vector<int> v[888888];
struct Tree{
	int x;
	int pos;
	int num;
}T[888888];
void modify(int k,int l,int r,int po,int m,int g)
{
	//cout<<k<<l<<r<<po<<m<<g<<endl;
	//return;
	if(l>r||po>r||l>po)
		return;
	if(l==r){
		T[k].x=m;
		T[k].pos=po;
		T[k].num=g;
		return;
	}
	int md;
	md=(l+r)/2;
	if(po<=md)
		modify(k*2,l,md,po,m,g);
	else
		modify(k*2+1,md+1,r,po,m,g);
	if(T[k*2].x>T[k*2+1].x)
		T[k]=T[k*2];
	else
		T[k]=T[k*2+1];
}
int main()
{
	int n,k,i,j,h,b,s,ans;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&a[i]);
		v[a[i]].push_back(i);
	}
	for(i=0;i<=2*n;i=i+1)
		v[i].push_back(1<<30);
	s=0;
	ans=0;
	memset(t,0,sizeof(t));
	if(n<=k){
		ans=0;
		for(i=1;i<=n;i=i+1){
			if(!f[a[i]]){
				f[a[i]]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
	{
		j=a[i];
		if(!f[j]){
			ans++;
			if(s<k){
				s++;
				t[j]++;
				f[j]=s;
				modify(1,1,k,s,v[j][t[j]],j);
			}
			else{
				h=T[1].num;
				b=T[1].pos;
				f[h]=0;
				t[j]++;
				f[j]=b;
				modify(1,1,k,b,v[j][t[j]],j);
			}
		}
		else{
			t[j]++;
			modify(1,1,k,f[j],v[j][t[j]],j);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
80 4
9 9 2 6 3 10 2 5 4 9 6 7 5 5 3 8 5 3 2 10 7 8 5 3 4 9 4 3 9 5 2 10 8 4 7 3 8 3 5 2
3 7 8 4 2 4 4 7 2 2 5 7 5 8 10 10 5 1 1 3 5 2 10 8 7 9 7 4 8 3 2 8 7 9 10 9 7 1 5 5
*/