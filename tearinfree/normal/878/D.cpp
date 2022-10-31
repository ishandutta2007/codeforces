#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ip;

bool bit_arr[100020][4096];
int arr[12][100000],n,k,q;

int main() {
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<k;i++) for(int j=0;j<n;j++) {
		scanf("%d",&arr[i][j]);
	}
	
	int c=k;
	for(int i=0;i<k;i++) for(int j=0;j<(1<<k);j++) {
		bit_arr[i][j]=( ((1<<i) & j) != 0 ) ? true : false;
	}

	int t,a,b;
	ip tmp[12];
	while(q--) {
		scanf("%d%d%d",&t,&a,&b);
		a--; b--;
		if(t==1) {
			for(int i=0;i<(1<<k);i++) bit_arr[c][i]=bit_arr[a][i]&bit_arr[b][i];
			c++;
		}
		else if(t==2) {
			for(int i=0;i<(1<<k);i++) bit_arr[c][i]=bit_arr[a][i]|bit_arr[b][i];
			c++;
		}
		else {
			for(int i=0;i<k;i++) tmp[i]=ip(arr[i][b],i);
			sort(tmp,tmp+k);
			
			int s=0;
			for(int i=0;i<k;i++) {
				s|=(1<<tmp[i].second);
				if(bit_arr[a][s]) {
					printf("%d\n",tmp[i].first);
					break;
				}
			}
		}
	}
	
	return 0;
}