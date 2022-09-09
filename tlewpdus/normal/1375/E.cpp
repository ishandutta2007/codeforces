#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
int arr[1100];
int ori[1100];
vector<int> inv[1100];

int main(){
	scanf("%d",&n);
//	srand(time(NULL));
//	iota(arr,arr+n,0);
//	random_shuffle(arr,arr+n);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
//		arr[i] = rand()%n;
//		printf("%d ",arr[i]);
	}
//	puts("");
	for (int i=0;i<n;i++) ori[i] = arr[i];
	int c = 0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (arr[i]>arr[j]) inv[i].push_back(j), c++;
		}
	}
	printf("%d\n",c);
	for (int i=0;i<n;i++) {
		sort(inv[i].begin(),inv[i].end(),[&i](int a, int b){
			if (arr[a]!=arr[b]) return arr[a]>arr[b];
			if (ori[a]!=ori[b]) return ori[a]>ori[b];
			return a>b;
		});
		for (int &j : inv[i]) {
			printf("%d %d\n",i+1,j+1);
			swap(arr[i],arr[j]);
		}
	}
//	for (int i=0;i<n;i++) {
//		printf("%d ",arr[i]);
//	}puts("");
//	for (int i=1;i<n;i++) {
//		if (arr[i-1]>arr[i]) {
//			printf("%d!!\n",i);
//		}
//	}

	return 0;
}