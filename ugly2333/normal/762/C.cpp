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
char a[100005],b[100005];
int p[100005],s[100005];
int inf = 1<<30;
int print(int l,int r)
{
	if(l>r){
		cout<<'-'<<endl;
		return 1;
	}
	int i;
	for(i=l;i<=r;i=i+1)
		cout<<b[i];
	return 0;
}
int main()
{
	int la,lb,i,j,l,r,ll,rr,m,pp,ss;
	cin>>a>>b;
	la=strlen(a);
	lb=strlen(b);
	j=0;
	pp=inf;
	for(i=0;i<lb;i=i+1){
		while(a[j]!=b[i]&&j<la){
			j=j+1;
		}
		if(j<la){
			p[i]=j;
			j=j+1;
		}
		else{
			pp=i;
			break;
		}
		//cout<<p[i]<<endl;
	}
	if(pp==inf)
		pp=lb;
	j=la-1;
	ss=inf;
	for(i=lb-1;i>=0;i=i-1){
		while(a[j]!=b[i]&&j>=0){
			j=j-1;
		}
		if(j>=0){
			s[i]=j;
			j=j-1;
		}
		else{
			ss=i;
			break;
		}
		//cout<<s[i]<<endl;
	}
	if(ss==inf)
		ss=-1;
	if(pp==0){
		i=print(ss+1,lb-1);
		return 0;
	}
	if(ss==lb-1){
		i=print(0,pp-1);
		return 0;
	}
	l=0;
	r=ss;
	for(i=0;i<pp;i=i+1){
		ll=max(i+1,ss+1);
		rr=lb-1;
		while(rr-ll>5){
			m=(ll+rr)/2;
			if(s[m]>p[i])
				rr=m;
			else
				ll=m+1;
		}
		for(j=ll;j<=rr;j=j+1)
			if(s[j]>p[i])
				break;
		ll=i+1;
		rr=j-1;
		if(rr-ll<r-l){
			r=rr;
			l=ll;
		}
	}
	if(l==0){
		i=print(r+1,lb-1);
		return 0;
	}
	i=print(0,l-1);
	if(r==lb-1){
		return 0;
	}
	i=print(r+1,lb-1);
	return 0;
}
/*
qweaaaaa
aaaaaqwe
-----
abcdcba
abacaba
------
qqeqqq
rre
*/