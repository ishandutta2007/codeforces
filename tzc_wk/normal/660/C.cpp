#include <bits/stdc++.h>
using namespace std;
int n,k,a[300001];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)	scanf("%d",a+i);
	int l=0,r=0,res=0,t=0,ansl=0,ansr=-1;
	while(r<n){
		while(r<n){
			if(a[r]==0)	t++;
			if(t>k)	break;
			r++;
		} 
		t--;
		if(r-l>res){
			ansl=l,ansr=r-1;
			res=r-l;
		}
		if(a[l]==0)	t--;
		l++;
	}
	printf("%d\n",res);
	for(int i=0;i<ansl;i++)	printf("%d ",a[i]);
	for(int i=ansl;i<=ansr;i++)	printf("%d ",1);
	for(int i=ansr+1;i<n;i++)	printf("%d ",a[i]);
}