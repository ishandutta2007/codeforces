#include <bits/stdc++.h> 
using namespace std;
int n;
int a[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p1,p2,p3;
	p1=a[1];p2=a[2];p3=a[3];
	int i=4;
	int s=0;
	while(i<=n&&a[i]==p3){
		s++;
		i++;
	}
	long long ans=0;
	if (p1==p2&&p2==p3)
		ans=(long long)(s+3)*(long long)(s+2)*(long long)(s+1)/6;
	if (p1==p2&&p2!=p3)
		ans=s+1;
	if (p1!=p2&&p2==p3)
		ans=(long long)(s+2)*(long long)(s+1)/2;
	if (p1!=p2&&p2!=p3)
		ans=s+1;
	cout<<ans<<endl;
	return 0;
}