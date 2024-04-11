#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

std::vector<int> ans;
inline void op(int x){
	a[x]=a[x+1]=a[x+2]=a[x]^a[x+1]^a[x+2];
	ans.push_back(x);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=0;
		ans.clear();
		bool flg=1;
		int l=0,r=0;
		for(int i=1;i<=n+1;i++){
			if(a[i]){
				if(!l)
					l=i;
				r=i;
				if(((r-l+1)&1)&&i+2<=n&&!a[i+1]&&!a[i+2])
					op(i);
			}
			else{
				if(l){
					if(!((r-l+1)&1)){
						if(i<=n)
							for(int j=r-1;j>=l;j-=2)
								op(j);
						else if(l>1)
							for(int j=l-1;j<r;j+=2)
								op(j);
						else
							flg=0;
					}
					else if(i<=n&&a[i+1])
						for(int j=r;j>=l;j-=2)
							op(j);
					else
						flg=0;
				}
				l=0;
			}
		}
		if(!flg)
			puts("NO");
		else{
			puts("YES");
			printf("%d\n",ans.size());
			for(auto x:ans)
				printf("%d ",x);
			puts("");
		}
	}
}