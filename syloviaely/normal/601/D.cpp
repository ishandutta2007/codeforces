#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
	int go[26],w,size,pd;
}t[4000000];
struct bian{
	int next,point;
}b[610000];
int root[310000],c[310000],w[310000],n,len,p[310000];
char ch[310000];
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	t[k1].size=1; t[k1].pd=t[k1].pd|t[k2].pd; t[k1].w=t[k1].pd;
	for (int i=0;i<26;i++){
		int k3=t[k1].go[i],k4=t[k2].go[i];
		if (k3==0) t[k1].go[i]=k4;
		else if (k4) dfs(k3,k4);
		t[k1].size+=t[t[k1].go[i]].size;
		t[k1].w+=t[t[k1].go[i]].w;
	}
}
void getans(int k1,int k2){
	root[k1]=++len; t[len].size=2; t[len].w=1; t[len].go[ch[k1]-'a']=len+1; 
	len++; t[len].w=1; t[len].pd=1; t[len].size=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			getans(j,k1); len++; t[len].go[ch[k1]-'a']=root[j]; 
			t[len].size=t[root[j]].size+1; t[len].w=t[root[j]].w; t[len].pd=0;
			root[j]=len;  
			if (t[root[k1]].size<t[root[j]].size) swap(root[k1],root[j]);
			dfs(root[k1],root[j]);
		}
	}
	w[k1]=t[root[k1]].w;
//	cout<<"fa "<<k1<<" "<<w[k1]<<endl;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%s",ch+1);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
	}
	len=0; getans(1,0); 
	int ans=0,num=0;
	for (int i=1;i<=n;i++)
		if (c[i]+w[i]>ans){
			ans=c[i]+w[i]; num=1;
		} else if (c[i]+w[i]==ans) num++;
	printf("%d\n%d\n",ans,num);
	return 0;
}