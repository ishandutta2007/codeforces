#include<bits/stdc++.h>
using namespace std;

int ans;
long long n;
long long f[110];

int main()
{int i,j;

 f[0]=1;
 f[1]=2;
 for(i=2;i<=100;i++)
 	f[i]=f[i-1]+f[i-2];
 //for(i=2;i<=100;i++) cout<<f[i]<<endl;	
 cin>>n;
 if(n==2)
 {	printf("%d\n",1);
 	return 0;
 }
 n--;
 n--;
 ans=1;
 i=0;
 while(n>=f[i])
 {	n-=f[i];
 	ans++;
 	i++;
 }
 printf("%d\n",ans);
 return 0;
}