#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
long long org[9][4];
bool ok=0; 
long long t[4],total=0,tt=0,pt[4]={},ps[4]={};
#define FX(i,j,k) else if(pt[j]==pt[i]*2&&pt[k]==pt[i]*3&&ps[i]==24&&ps[j]==24&&ps[k]==8)
inline long long jlpf(long long* a,long long* b)
{
	total=0;
	for(int i=1;i<=3;i++) t[i]=a[i]-b[i];
	for(int i=1;i<=3;i++) total+=t[i]*t[i];
	return total;
}
inline bool valid(long long (*blocks)[4])
{
	int pn=0;
	long long tmp;
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=8;j++)
		{
			if(i==j) continue;
			tmp=jlpf(blocks[i],blocks[j]);
			int find=-1;
			for(int i=1;i<=pn;i++) if(pt[i]==tmp) {find=i; break;}
			if(find!=-1) {ps[find]++; continue;}
			if(pn>=3) return false;
			pt[++pn]=tmp; ps[pn]=1;
		}
	}
	if(pn!=3) return false;
	FX(1,2,3) return true;
	FX(1,3,2) return true;
	FX(2,1,3) return true;
	FX(2,3,1) return true;
	FX(3,1,2) return true;
	FX(3,2,1) return true;
	else return false;
}
void tryy(int deep)
{
	if(deep>8)
	{
		if(valid(org))
		{
			cout<<"YES\n";
			for(int i=1;i<=8;i++)
			{
				for(int j=1;j<=2;j++) cout<<org[i][j]<<" ";
				cout<<org[i][3]<<"\n";
			}
			ok=1;
		}
		return;
	} 
	do
	{
		tryy(deep+1);
		if(ok) return;
	}while(next_permutation(org[deep]+1,org[deep]+4));
}
int main()
{
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=3;j++) cin>>org[i][j];
	}
	for(int i=1;i<=8;i++) sort(org[i]+1,org[i]+4);
	tryy(1);
	if(!ok) cout<<"NO\n";
	return 0;
}