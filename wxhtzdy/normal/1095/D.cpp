#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200005;
int n,a[N],b[N],ma[N],mb[N];
bool was[N];
void cl(){for(int i=0;i<N;i++)was[i]=false;}
void DFS(int u){
    printf("%i ",u);
	was[u]=true;
	if(ma[u]!=-1){
		if(!was[ma[u]])DFS(ma[u]);
	}
	if(mb[u]!=-1){
		if(!was[mb[u]])DFS(mb[u]);
	}
}
int main(){
	scanf("%i",&n);
	for(int i=0;i<n;i++)scanf("%i %i",&a[i],&b[i]),ma[i]=-1,mb[i]=-1;
	ma[n]=-1,mb[n]=-1;
	for(int i=0;i<n;i++){
		if(a[a[i]-1]==b[i]||b[a[i]-1]==b[i]){
			ma[i+1]=a[i];
		}
		if(a[b[i]-1]==a[i]||b[b[i]-1]==a[i]){
			if(ma[i+1]==-1)ma[i+1]=b[i];
            else mb[i+1]=b[i];
		}
	}
	cl();DFS(1);
	//for(int i=0;i<(int)ans.size()-1;i++)printf("%i ",ans[i]);
}