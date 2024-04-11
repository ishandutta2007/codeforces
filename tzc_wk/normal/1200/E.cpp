#include <bits/stdc++.h>
using namespace std;
int n,z[1000005];
string s[100005],ans,x;
inline void Z_algorithm(){
	int l=0,r=0;
	for(int i=1;i<x.size();i++){
		z[i]=0;
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<x.size()&&x[i+z[i]]==x[z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		x=s[i]+"_"+ans.substr(ans.size()-min(ans.size(),s[i].size()));
		Z_algorithm();
		int maxx=0;
		for(int j=s[i].size()+1;j<x.size();j++)
			if(z[j]==x.size()-j)
				maxx=max(maxx,z[j]);
		ans+=s[i].substr(maxx);
	}
	for(int i=0;i<ans.size();i++)	putchar(ans[i]);
}