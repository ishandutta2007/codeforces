#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define max_n 500000
int p1[max_n+1],p2[max_n+1];
int pos1[max_n+1],pos2[max_n+1],arr1[max_n+1],arr2[max_n+1],cnt1,cnt2;
int find1(const int&u){
	return p1[u]?p1[u]=find1(p1[u]):u;
}
int find2(const int&u){
	return p2[u]?p2[u]=find2(p2[u]):u;
}
void merge1(int u,int v){
	u=find1(u);
	v=find1(v);
	if(u>v)
		swap(u,v);
	p1[v]=u;
	int l=pos1[v];
	if(l<cnt1){
		pos1[arr1[cnt1]]=l;
		pos1[v]=cnt1;
		swap(arr1[l],arr1[cnt1]);
	}
	--cnt1;
}
void merge2(int u,int v){
	u=find2(u);
	v=find2(v);
	if(u>v)
		swap(u,v);
	p2[v]=u;
	int l=pos2[v];
	if(l<cnt2){
		pos2[arr2[cnt2]]=l;
		pos2[v]=cnt2;
		swap(arr2[l],arr2[cnt2]);
	}
	--cnt2;
}
void merge(int u,int v){
	if(u>v)
		swap(u,v);
	printf("%d %d\n",u,v);
	merge1(u,v);
	merge2(u,v);
}
int main(){
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	memset(p1+1,0,n<<2);
	memset(p2+1,0,n<<2);
	cnt1=cnt2=n;
	for(int i=1; i<=n; ++i)
		pos1[i]=pos2[i]=arr1[i]=arr2[i]=i;
	for(int i=m1,u,v; i; --i){
		scanf("%d%d",&u,&v);
		merge1(u,v);
	}
	for(int i=m2,u,v; i; --i){
		scanf("%d%d",&u,&v);
		merge2(u,v);
	}
	int t=n-1-max(m1,m2);
	printf("%d\n",t);
	for(; t; --t){
		int u=1,v=arr2[2];
		if(u==find1(v)){
			int w=arr1[2];
			if(u==find2(w))
				merge(v,w);
			else
				merge(u,w);
		}
		else
			merge(u,v);
	}
	return 0;
}