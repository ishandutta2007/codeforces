#include <cstdio>

int n,m,res[101],use[101];

int main() {
	int idx,prev;
	scanf("%d %d",&n,&m);
	scanf("%d",&idx);
	idx--;
	for(int it=1;it<m;it++) {
		prev=idx;
		scanf("%d",&idx);
		idx--;
		
		int inter=(idx-prev+n)%n;
		if(inter==0) inter=n;
		if(res[prev]==0) {
			if(use[inter]) {
				puts("-1");
				return 0;
			}
			res[prev]=inter, use[inter]=1;
		}
		else if(res[prev]!=inter) {
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<n;i++) {
		if(res[i]==0) {
			for(int j=1;j<=n;j++) {
				if(!use[j]) {
					use[j]=1;
					printf("%d ",j);break;
				}
			}
		}
		else printf("%d ",res[i]);
	}
	return 0;
}