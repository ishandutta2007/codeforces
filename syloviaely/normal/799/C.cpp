#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int whereA[110000],fA[110000],gA[110000];
int whereB[110000],fB[110000],gB[110000];
char ch[10];
int n,c,d;
void insert1(int k1,int k2,int k3){
//	cout<<"insert1 "<<k1<<" "<<k2<<" "<<k3<<endl;
	if (k1>fA[k2]){
		gA[k2]=fA[k2]; fA[k2]=k1; whereA[k2]=k3;
	} else gA[k2]=max(gA[k2],k1);
}
void insert2(int k1,int k2,int k3){
	if (k1>fB[k2]){
		gB[k2]=fB[k2]; fB[k2]=k1; whereB[k2]=k3;
	} else gB[k2]=max(gB[k2],k1);
}
int main(){
	scanf("%d%d%d",&n,&c,&d);
	for (int i=1;i<=n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); scanf("%s",ch+1);
		if (ch[1]=='C'){
			insert1(k1,k2,i);
		} else insert2(k1,k2,i);
	}
	for (int i=0;i<max(c,d);i++){
		insert1(fA[i],i+1,whereA[i]);
		insert1(gA[i],i+1,0);
		
		insert2(fB[i],i+1,whereB[i]);
		insert2(gB[i],i+1,0);
	}
	int ans=0;
	if (whereA[c]&&whereB[d]) ans=fA[c]+fB[d];
//	cout<<ans<<endl;
	for (int i=0;i<=c;i++){
		int num=fA[i];
		if (fA[i]==0) continue;
		if (whereA[c-i]==whereA[i]){
			num+=gA[c-i]; 
			if (gA[c-i]==0) num=0;
		} else if (fA[c-i]) num+=fA[c-i];
		else num=0;
		ans=max(ans,num);
	}
	for (int i=0;i<=d;i++){
		int num=fB[i];
		if (fB[i]==0) continue;
		if (whereB[d-i]==whereB[i]){
			num+=gB[d-i]; 
			if (gB[d-i]==0) num=0;
		} else if (fB[d-i]) num+=fB[d-i];
		else num=0;
		ans=max(ans,num);
	}
	cout<<ans<<endl;
}