#include <bits/stdc++.h>
using namespace std;
int n,k,a[101];
struct answer{
	int ans;
	void add(){ans++;}
}Add;
void add(){
	vector<int> s;
	for(int i=n-1;i>=0;i--)
		if(a[i]!=k&&a[i]!=a[i+1])
			s.push_back(i);
	for(int i=0;i<s.size();i++)	a[s[i]]++;
//	for(int i=0;i<n;i++)	cout<<a[i]<<" ";
//	puts("");
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)	scanf("%d",a+i);
	sort(a,a+n);
	while(a[0]!=k){
		add();
		Add.add();
	}
	printf("%d\n",Add.ans);
}