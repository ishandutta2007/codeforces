//CF 794C
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
int s1[33],s2[33];
char c[333333];
int s[333333];
int main()
{
	int n,i,j,k,x,p;
	cin>>c;
	n=strlen(c);
	for(i=0;i<n;i=i+1)
		s1[c[i]-'a'+1]++;
	cin>>c;
	for(i=0;i<n;i=i+1)
		s2[c[i]-'a'+1]++;
	p=0;
	x=0;
	for(i=0;i<n;i=i+1)
	{
		j=1;
		while(s1[j]==0){
			j++;
		}
		k=26;
		while(s2[k]==0){
			k--;
		}
		if(j>=k&&x==0){
			//cout<<endl;
			p=(n-i-1)%2;
			x=1;
		}
		//if(j>k)
		//	break;
		if(i%2==p){
			cout<<char(j+'a'-1);
			s1[j]--;
		}
		else{
			cout<<char(k+'a'-1);
			s2[k]--;
		}
		//cout<<p<<endl;
	}
	/*if(i<n){
		x=i;
		p=1-p;
		cout<<p<<endl;
		for(i=n-1;i>=x;i=i-1)
		{
			k=26;
			while(s2[k]==0){
				k--;
			}
			if((n-i)%2==p){
				s[i]=k;
				s2[k]--;
			}
		}
		for(i=x;i<n;i=i+1)
		{
			j=1;
			while(s1[j]==0){
				j++;
			}
			if(s[i]==0){
				s[i]=j;
				s1[j]--;
			}
		}
		for(i=x;i<n;i=i+1)
			cout<<char(s[i]+'a'-1);
	}
	cout<<endl;*/
	return 0;
}
/*
pppppppp
abcdefgh

*/