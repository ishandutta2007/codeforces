#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 100005
using namespace std;
string a,b;int len1,len2;
int pre[maxn];
int suf[maxn];
int ans1=0,ans2=0,ans3=0,p=0,s=0;
void init(){
	len1=a.length();
	len2=b.length();
	int pos=0;
	for(int i=0;i<len1;i++){
		if(a[i]==b[pos])
			pre[pos++]=i;
		if(pos==len2)break;
	}	
	ans1=pos;
	for(;pos<len2;pos++)pre[pos]=-1;
	pos=len2-1;
	for(int i=len1-1;i>=0;i--){
		if(a[i]==b[pos])
			suf[pos--]=i;
		if(pos==-1)break;
	}
	ans2=len2-1-pos;
	for(;pos>=0;pos--)suf[pos]=-1;
	return;
}
int binary_search(int l,int r,int x){
	if(l==r)return l;
	int m=(r-l)/2+l;
	if(x<=pre[m])return binary_search(l,m,x);
	else return binary_search(m+1,r,x);
}
void work(){
	if(ans1==len2||ans2==len2){
		for(int i=0;i<len2;i++)
			printf("%c",b[i]);
		return;
	}
	for(int i=len2-1;i>=0;i--){
		if(suf[i]==-1)break;
		int first=binary_search(0,ans1,suf[i]);
		if(first==0)continue;
		if(ans3<len2-i+first){
			ans3=len2-i+first;
			p=first;s=i;
		}
	}
	int ans=max(ans3,max(ans1,ans2));
	if(ans==0)
		printf("-");
	else if(ans==ans1)
		for(int i=0;i<ans1;i++)
			printf("%c",b[i]);
	else if(ans==ans2)
		for(int i=len2-ans2;i<len2;i++)
			printf("%c",b[i]);
	else{
		for(int i=0;i<p;i++)
			printf("%c",b[i]);
		for(int i=s;i<len2;i++)
			printf("%c",b[i]);
	}
	return;	
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>a>>b;
	init();
	work();
	return 0;
}