#include<bits/stdc++.h>
#define ll long long
#define N 50005

int T;

int n,a[N],x;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&x);
		int f=0;
		ll g=0;
		bool h=0;
		for(int i=1;i<=n;i++){
			a[i]-=x;
			if(!h||g+a[i]>=0)
				f++,g=std::min(g+a[i],(ll)a[i]),h=1;
			else
				g=0,h=0;
		}
		printf("%d\n",f);
	}
}