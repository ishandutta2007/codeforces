#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,T,ans;
vector<int>a[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int L=-1,R=-1,flg=0;
		for(int i=1;i<=n;i++){
			a[i].resize(m);
			int l=-1,r=-1,mx=0;
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]),mx=max(mx,a[i][j]);
				if(a[i][j]<mx)
					r=j;
			}
			int mn=1000000001;
			for(int j=m-1;j>=0;j--){
				mn=min(mn,a[i][j]);
				if(a[i][j]>mn)
					l=j;
			}
			if(l!=-1){
				if(L==-1){
					L=l,R=r;
					continue;
				}
				else if(L!=l||R!=r)
					flg=1;
			}
		}
		if(flg==1)
			puts("-1");
		else{
			if(L==-1&&R==-1)
				puts("1 1");
			else{
				flg=1;
				for(int i=1;i<=n;i++){
					if(L!=R)
						swap(a[i][L],a[i][R]);
					for(int j=1;j<m;j++)
						flg&=(a[i][j-1]<=a[i][j]);
				}
				if(flg==1)
					printf("%d %d\n",L+1,R+1);
				else puts("-1");
			}
		}
		for(int i=1;i<=n;i++)
			a[i].clear();
	}
	return 0;
}