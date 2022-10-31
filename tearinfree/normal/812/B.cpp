#include <cstdio>
#include <algorithm>

int arr[15][111],chk[15];
int n,m;

int TTime(int state)
{
	int res=0;
	for(int i=n-1;i>=0;i--) {
		if(i==0||chk[i-1]==1) {
			if(state&(1<<i)) {
				for(int j=0;j<m;j++) {
					if(arr[i][j]) {
						res+=m-j-1;
						break;
					}
				}
			}
			else {
				for(int j=m-1;j>=0;j--) {
					if(arr[i][j]) {
						res+=j;
						break;
					}
				}
			}
			break;
		}
		if(((state&(1<<i))>>1)!=(state&(1<<(i-1)))) {
			res+=m-1;
		}
		else {
			if(state&(1<<i)) {
				for(int j=0;j<m;j++) {
					if(arr[i][j]) {
						res+=2*(m-j-1);
						break;
					}
				}
			}
			else {
				for(int j=m-1;j>=0;j--) {
					if(arr[i][j]) {
						res+=2*j;
						break;
					}
				}
			}
		}
		res++;
	}
	return res;
}
int main() {
	scanf("%d %d",&n,&m);
	m+=2;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%1d",&arr[i][j]);
	for(int i=0;i<n;i++) {
		bool flag=true;
		for(int j=0;j<m;j++) {
			if(arr[i][j]) {
				flag=false;
				break;
			}
		}
		if(!flag) break;
		chk[i]=1;
	}

	int res=987654321;
	for(int i=0;i<(1<<(n-1));i++) {
		res=std::min(res,TTime(i));
	}
	printf("%d\n",res);
	return 0;
}