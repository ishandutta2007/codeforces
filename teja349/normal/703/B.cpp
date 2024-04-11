#include<iostream>
using namespace std;
//int add(long long int*,long long int);
int main(){
	long long int n,k,a[100002],b[100002],sum=0,t,s=0,f;
	cin>>n>>k;
	cin>>a[0];
	sum+=a[0];
	for (int i = 1; i < n; ++i)
	{
		cin>>a[i];
		s+=a[i-1]*a[i];	
		sum+=a[i];
	}
	s+=a[n-1]*a[0];
	for (int i = 0; i < n; ++i)
	{
		b[i]=1;
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>t;
		t=t-1;
	 	b[t]=0;
	// 	for (int i = 0; i < n; ++i)
	// 	{
	// 		if(t==n-1){
	// 			if(i!=0&&i!=n-2&&b[i]!=1)
	// 				s+=a[i]*a[t];
	// 		}
	// 		else if(t==0){
	// 			if(i!=1&&i!=n-1&&b[i]!=1)
	// 				s+=a[i]*a[t];
	// 		}
	// 		else{
	// 			if(i!=t+1&&i!=t-1&&b[i]!=1)
	// 				s+=a[i]*a[t];
	// 		}
	// 	}
	// }
		sum-=a[t];
		if(t==n-1){
			if(t==n-1)
			s+=(sum-a[n-2]*b[n-2]-a[0]*b[0])*a[t];
		}
		else if(t==0){
			s+=(sum-a[n-1]*b[n-1]-a[1]*b[1])*a[t];
		}
		else{
			s+=(sum-a[t-1]*b[t-1]-a[t+1]*b[t+1])*a[t];
		}


	}
	
		cout<<s;
}
// int add(long long int *s,long long int n){
// 	int i=0,j;
// 	s[i]+=n%10;
// 	j=i;
// 	while(s[j]>9)
// 	{
// 		s[j]%=10;
// 		s[j+1]++;
// 		j++;
// 	}
// 	n/=10;
// 	i++;
// 	while(n>0){
// 		s[i]+=n%10;
// 		j=i;
// 		while(s[j]>9)
// 		{
// 			s[j]%=10;
// 			s[j+1]++;
// 			j++;
// 		}
// 		n/=10;
// 		i++;
// 	}
// 	return i;
// }