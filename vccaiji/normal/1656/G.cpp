#include<bits/stdc++.h>
using namespace std;
int n;
int a[210000];
int b[210000];
int bb[210000];
int fa[210000];
int cnt;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i!=j){
		cnt--;
		fa[i]=j;
	}
}
pair<int,int> o[210000];
int now[210000];
int ii[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)o[i]=make_pair(a[i],i);
		sort(o+1,o+n+1);
		int l=1;
		bool r=0;
		int u=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			if((i==n)||(o[i].first!=o[i+1].first)){
				if((i==l)&&(n&1)&&(o[l].second==(n+1)/2)){
					r=1;
					break;
				}
				if((i-l+1)&1){
					u++;
					if(o[l].second==(n+1)/2){
						b[(n+1)/2]=o[i].second;
						for(int j=1;j<=(i-l)/2;j++){
							b[++tot]=o[l+2*j-1].second;
							b[n+1-tot]=o[l+2*j-2].second;
						}
					}
					else{
						b[(n+1)/2]=o[l].second;
						for(int j=1;j<=(i-l)/2;j++){
							b[++tot]=o[l+2*j].second;
							b[n+1-tot]=o[l+2*j-1].second; 
						}
					}
				}
				else{
					for(int j=1;j<=(i-l+1)/2;j++){
						b[++tot]=o[l+2*j-1].second;
						b[n+1-tot]=o[l+2*j-2].second; 
					}
				}
				l=i+1;
			}
		}
		if(r||(u>1)){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=n;i++) fa[i]=i;
		cnt=n;
		for(int i=1;i<=n;i++) merge(i,b[i]);
		for(int i=1;i<=n/2;i++){
			int oo=find(i),ooo=find(n+1-i);
			if(oo!=ooo){
			    cnt--;
				swap(b[i],b[n+1-i]);
				fa[oo]=ooo;
			}
		}
		if(cnt>1){
			for(int i=1;i<=n/2;i++)now[find(i)]=i;
			int cntt=0;
			for(int i=1;i<=n;i++)if(fa[i]==i)ii[++cntt]=now[i];
			for(int i=1;i<=n;i++) bb[i]=b[i];
			for(int i=1;i<cnt;i++){
				b[ii[i]]=bb[n+1-ii[i+1]];
				b[n+1-ii[i]]=bb[ii[i+1]];
			}
			b[ii[cnt]]=bb[ii[1]];
			b[n+1-ii[cnt]]=bb[n+1-ii[1]];
		}
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}