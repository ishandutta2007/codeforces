#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		vector<int> a(n),b(n);
		for(int&i:a)scanf("%i",&i);
		for(int&i:b)scanf("%i",&i);
		vector<pair<int,int>> A,B;
		for(int i=0;i<n/2;i++)A.push_back({min(a[i],a[n-i-1]),max(a[i],a[n-i-1])});
		for(int i=0;i<n/2;i++)B.push_back({min(b[i],b[n-i-1]),max(b[i],b[n-i-1])});
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		if(A==B&&(n%2==0||a[n/2]==b[n/2]))printf("yes\n");
		else printf("no\n");
	}
	return 0;
}