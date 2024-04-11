//CF1081F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333;
int n,k,a[N];
//int b[N];
int f(int x){
	cout<<"? "<<x<<' '<<n<<endl;
	cin>>x;
	/*if(rand()&1)
		for(int i=1;i<=n;i=i+1)b[i]^=1;
	else
		for(int i=x;i<=n;i=i+1)b[i]^=1;
	x=0;
	for(int i=1;i<=n;i=i+1)
		x+=b[i];*/
	if(x==-1)
		exit(0);
	return x;
}
int main()
{
	int i,j,x,o,t,e;
	scanf("%d%d",&n,&k);
	//b[1]=0,b[2]=0,b[3]=0,b[4]=0;
	x=0;
	t=k;
	for(i=1;i<n;i=i+1){
		for(j=1;j<=20;j=j+1){
			f(i+1);
			o=f(i+1);
			if(o!=t){
				e=t-o;
				e=(i+e)/2;
				a[i]=e-x;
				x=i-e;
				//cout<<t<<o<<e<<x<<endl;
				t=o;
				break;
			}
		}
		if(j>20){
			a[i]=i/2-x;
			x=i/2;
		}
	}
	for(i=1;i<n;i=i+1)
		k-=a[i];
	a[n]=k;
	cout<<"! ";
	for(i=1;i<=n;i=i+1)
		cout<<a[i];
	cout<<endl;
	return 0;
}