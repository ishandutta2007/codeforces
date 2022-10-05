#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[200001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n+1);
	bool flag=1;
	for(int i=3;i<=n;i++)	if(a[i].first-a[i-1].first!=a[3].first-a[2].first)	flag=0;
	if(flag)	printf("%d\n",a[1].second),exit(0);
	flag=1;
	for(int i=2;i<n;i++)	if(a[i].first-a[i-1].first!=a[2].first-a[1].first)	flag=0;
	if(flag)	printf("%d\n",a[n].second),exit(0);
	if((a[n].first-a[1].first)%(n-2)!=0)	puts("-1"),exit(0);
	int dif=(a[n].first-a[1].first)/(n-2);
	int ind=0;
	for(int i=2;i<=n-1;i++){
		if(a[i].first==a[i-1].first){
			if(ind!=0)	puts("-1"),exit(0);
			ind=i;
		}
		else if(a[i].first-a[i-1].first!=dif&&a[i+1].first-a[i].first!=dif){
			if(ind!=0)	puts("-1"),exit(0);
			ind=i;
		}
	}
	cout<<a[ind].second<<endl;
}