#include<bits/stdc++.h>
using namespace std;
int n;
int a[310000];
int b[310000];
int pre[310000];
stack<int> st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int l1=n+1;
	int l=n-a[n];
	for(int i=l;i<=n;i++) pre[i]=n+1;
	for(;;){
		if(l==0){
			for(int j=l;j!=n+1;j=pre[j]) st.push(j);
			printf("%d\n",st.size());
			while(st.size()){
				printf("%d ",st.top());
				st.pop();
			}
			printf("\n");
			return 0;
		}
		if(l==l1){
			printf("-1\n");
			return 0;
		}
		int minn=l,j=l;
		for(int i=l;i<=l1-1;i++){
			int ii=i+b[i];
			ii-=a[ii];
			if(minn>ii){
				minn=ii;
				j=i;
			}
		}
		l1=l;
		l=minn;
		for(int i=l;i<=l1-1;i++)pre[i]=j;
	}
	return 0;
}