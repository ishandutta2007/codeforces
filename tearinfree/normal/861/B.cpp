#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

int n,m;
ip arr[100];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&arr[i].first,&arr[i].second);
	
	int mx=0;
	for(int i=1;i<=100;i++) {
		int f=1;
		for(int j=1;j<=100;j++) {
			for(int k=0;k<m;k++) {
				if(arr[k].second==j) {
					if(arr[k].first<=(j-1)*i || arr[k].first>j*i) {
						f=0;
						break;
					}
				}
			}
			if(f==0)break;
		}
		if(f) {
			int fl=(n-1)/i+1;
			if(mx==0) mx=fl;
			else if(mx!=fl) mx=-1;
		}
	}
	if(mx<=0) mx=-1;
	printf("%d\n",mx);
	return 0;
}