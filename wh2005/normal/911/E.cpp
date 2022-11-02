#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int a[200009],s[200009],top;
bool vis[200009];
int main(){
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	int pos=1;
	for(int i=1;i<=m;i++){
		vis[a[i]]=1,s[++top]=a[i];
		if(a[i]<=pos){
			for(int j=pos+1;j<=n;j++){
				if(!vis[j]){
					pos=j;
					break;
				}
			}
		}
		if(top>1&&s[top-1]<s[top]){
			if(pos<s[top-1]){
				printf("-1\n");
				return 0;
			}
			for(int j=s[top]-1;j>=1;j--){
				if(vis[j]){
					if(j>pos){
						printf("-1\n");
						return 0;
					}
					break;
				}
			}
		}
	}
	for(int i=s[top]-1;i>=1;i--){
		if(vis[i]){
			if(i>pos){
				printf("-1\n");
				return 0;
			}
			break;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",a[i]);
	while(top>0){
		for(int i=s[top]-1;i>=1;i--){
			if(!vis[i]) printf("%d ",i);
			else break;
		}
		top--;
	}
	for(int i=n;i>=1;i--){
		if(!vis[i]) printf("%d ",i);
		else return 0;
	}
	return 0;
}