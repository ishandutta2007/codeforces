#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
int arr[100005], N, i, x, y;
bool cmp(int i,int j){return arr[i]<arr[j];}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d%d",&y,&arr[i]);
		(y)?a.push_back(i):b.push_back(i);
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	while(a.size()&&b.size()){
		if(arr[a[0]]<arr[b[0]]||(arr[a[0]]==arr[b[0]]&&a.size()>b.size())){
			printf("%d %d %d\n",a[0],b[0],arr[a[0]]);
			arr[b[0]] -= arr[a[0]]; a.erase(a.begin());
		}
		else{
			printf("%d %d %d\n",b[0],a[0],arr[b[0]]);
			arr[a[0]] -= arr[b[0]]; b.erase(b.begin());
		}
	}
	return 0;
}