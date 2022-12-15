#include <bits/stdc++.h>
using namespace std;

long long S;
int N, i, x, s;
vector<int> v;

int main(){
	scanf("%d",&N);
	S = 1LL*N*(N+1)/2;
	printf("%d\n",S%2);
	for(i=N;i>=1;i--){
		if(s+i<=S/2){
			v.push_back(i);
			s += i;
		}
	}
	printf("%d ",v.size());
	for(i=0;i<v.size();i++)
		printf("%d ",v[i]);
	return 0;
}