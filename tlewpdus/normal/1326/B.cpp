#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[200100], xrr[200100];
int brr[200100];

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&brr[i]);
	for (int i=0;i<n;i++) {
		arr[i] = xrr[i]+brr[i];
		xrr[i+1] = max(arr[i],xrr[i]);
		printf("%d ",arr[i]);
	}puts("");

	return 0;
}