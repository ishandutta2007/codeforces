#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],s,t;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d%d",&s,&t);
	int k=s;
	s=t-s;
	int ans=0,num=0,p=1;
	for (int i=1;i<=s;i++)ans+=a[i],num+=a[i];
	for (int i=s+1;i<n+s;i++)
	 {
	 	num+=a[(i-1)%n+1];
	 	num-=a[i-s];
	 	if (ans<num)
	 	 {
	 	 	ans=num;
	 	 	p=i;
	 	 }
	 	if (ans==num&&(1-(p-s)+n+k-1)%n+1>(1-(i-s)+n+k-1)%n+1)p=i;
	 }
	printf("%d",(1-(p-s)+n+k-2)%n+1); 
}