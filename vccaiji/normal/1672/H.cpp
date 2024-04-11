#include<bits/stdc++.h>//luogu
using namespace std;
int n,q;
char a[210000];
int s1[210000],s2[210000];
int main(){
	cin>>n>>q;
	scanf("%s",a+1);
	s1[1]=s2[1]=0;
	for(int i=2;i<=n;i++){
		s1[i]=s1[i-1];
		s2[i]=s2[i-1];
		if(a[i-1]=='0'&&a[i]=='0')s1[i]++;
		if(a[i-1]=='1'&&a[i]=='1')s2[i]++;
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",max(s1[r]-s1[l],s2[r]-s2[l])+1);
	}
	return 0;
}