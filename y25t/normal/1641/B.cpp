#include<bits/stdc++.h>
#define N 505

int T;

int n,a[N];

bool b[N];

std::vector<std::pair<int,int>> op;
std::vector<int> seg;

int t=0;
inline void rev(int l,int r){
	for(int i=l;i<=r;i++)
		op.emplace_back(t+r+i-l,a[i]);
	seg.push_back((r-l+1)<<1);
	t+=(r-l+1)<<1;
	std::reverse(a+l,a+r+1),std::reverse(b+l,b+r+1);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n&1){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++)
			b[i]=0;
		op.clear(),seg.clear(),t=0;
		bool flg=1;
		int x=1;
		while(1){
			while(x<n&&b[x]&&b[x+1]){
				seg.push_back(2);
				x+=2;
			}
			if(x>n)
				break;
			int y=x+1;
			while(y<=n&&(b[y]||a[y]!=a[x]))
				y++;
			if(y>n){
				flg=0;
				break;
			}
			b[x]=b[y]=1;
			if(y>x+1)
				rev(x,y-1);
		}
		if(!flg){
			puts("-1");
			continue;
		}
		printf("%d\n",(int)op.size());
		for(auto [i,j]:op)
			printf("%d %d\n",i,j);
		printf("%d\n",(int)seg.size());
		for(auto i:seg)
			printf("%d ",i);
		puts("");
	}
}