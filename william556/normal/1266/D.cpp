#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=3e5+5;
int n,m;
long long d[N]; 
int o,lx[N],ly[N];
long long lz[N];
inline void ae(int x,int y,long long z){
	lx[++o]=x,ly[o]=y,lz[o]=z;	
}
int main(){
	n=in(),m=in();
	while(m--){
		int x=in(),y=in(),z=in();
		d[x]+=z,d[y]-=z;	
	}
	vector<int> v1,v2;
	for(int i=1;i<=n;i++){
		if(d[i]>0)v1.push_back(i);
		if(d[i]<0)v2.push_back(i);	
	}
	for(int i=0,j=0;i<v1.size();i++){
		while(d[v1[i]]>0){
			if(d[v1[i]]+d[v2[j]]<0){
				ae(v1[i],v2[j],d[v1[i]]);
				d[v2[j]]+=d[v1[i]];
				break;
			}
			ae(v1[i],v2[j],-d[v2[j]]);
			d[v1[i]]+=d[v2[j]];
			j++;
		}
	}
	printf("%d\n",o);
	for(int i=1;i<=o;i++){
		printf("%d %d %lld\n",lx[i],ly[i],lz[i]);	
	}
	return 0;
}