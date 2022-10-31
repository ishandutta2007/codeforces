#include <cstdio>
#include <algorithm>
#include <cstring>

char str[5555];
int cache[5000][5000];
int kth[5000][5000];
int sum[5001],n;

int DP(int l,int r) {
	if(cache[l][r]!=-1) return cache[l][r];
	if(l>=r) return cache[l][r]=1;
	else if(str[l]!=str[r]) return cache[l][r]=0;
	else return cache[l][r]=DP(l+1,r-1);
}
int main() {
	scanf("%s",str);
	n=strlen(str);
	memset(cache,-1,sizeof(cache));
	for(int k=0;k<n;k++) {
		for(int i=0;i+k<n;i++) {
			int j=i+k;
			if(j>=n) break;
			DP(i,j);
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=0;i<n;i++) {
			int j=i+k-1;
			if(j>=n) break;
			if(!cache[i][j]) continue;
			if(k&1) {
				if(k==1) {
					kth[i][j]=1;
					sum[1]+=1;
					sum[2]-=1;
				}
				else {
					int md=(i+j)>>1;
					if(cache[i][md-1]&&cache[md+1][j]) {
						kth[i][j]=kth[i][md-1]+1;
						sum[1]+=1;
						sum[kth[i][j]+1]-=1;
					}
					else {
						kth[i][j]=1;
						sum[1]+=1;
						sum[2]-=1;
					}
				}
			}
			else {
				int md=(i+j)>>1;
				if(cache[i][md]&&cache[md+1][j]) {
					kth[i][j]=kth[i][md]+1;
					sum[1]+=1;
					sum[kth[i][j]+1]-=1;
				}
				else {
					kth[i][j]=1;
					sum[1]+=1;
					sum[2]-=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		sum[i]+=sum[i-1];
		printf("%d ",sum[i]);
	}
	return 0;
}