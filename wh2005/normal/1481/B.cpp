#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
int T,n,m,a[N],top;
struct Stac{int h,w;}s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		top=0;int sum=0;
		for(int i=1;i<=n;i++){
			Stac x;x.h=a[i],x.w=1;
			if(!top||s[top].h>x.h) s[++top]=x;
			else{
				while(top&&s[top].h<=x.h){
					sum+=(x.h-s[top].h)*s[top].w;
					x.w+=s[top].w;s[top].h=0,s[top].w=0;top--;
				}
				s[++top]=x;
			}
		}
		while(top){s[top].h=0,s[top].w=0;top--;}
		if(m>sum){printf("-1\n");continue;}
		int ps=0;
		while(m--){
			for(int i=1;i<=n;i++)
				if(a[i]<a[i+1]){ps=i,a[i]++;break;}
		}
		printf("%d\n",ps);
	}
	return 0;
}