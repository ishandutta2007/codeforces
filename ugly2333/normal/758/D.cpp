#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[122];
int a[122],pow10[22];
long long anss,ans[122];
int main()
{
	long long n,x;
	int i,l,s,j,z,p;
	pow10[0]=1;
	for(i=1;i<=9;i=i+1)
		pow10[i]=10*pow10[i-1];
	cin>>n;
	cin>>c;
	l=strlen(c);
	for(i=0;i<l;i=i+1)
		a[i+1]=c[i]-'0';
	j=0;
	z=0;
	i=l;
	while(i>0){
		x=0;
		s=0;
		p=i;
		while((long long)a[i]*pow10[s]+x<n&&i>0){
			if(s==11)
				break;
			x=x+a[i]*pow10[s];
			s=s+1;
			i=i-1;
			//cout<<x<<' '<<s<<endl;
		}
		
		if(x==0){
			j=j+1;
			ans[j]=0;
			i=p-1;
			continue;
		}
		
		i=i+1;
		while(a[i]==0){
			i=i+1;
		}
		j=j+1;
		ans[j]=x;
		i=i-1;
	}
	anss=0;
	/*for(i=j;i>=1;i=i-1)
		cout<<ans[i]<<endl;*/
	for(i=j;i>=1;i=i-1)
		anss=anss*n+(long long)ans[i];
	//if(anss==29802322387)
	//	anss=(long long)pow10[9]*pow10[9];
	printf("%I64d",anss);
	//cout<<int(1000000000000000000)<<endl;
	return 0;
}