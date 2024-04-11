//CF1098C
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
const int N = 111111;
int n,f[N],b[N];
LL k,s,a[N];
int main()
{
	int i,j,o,x,y;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1)
		s+=i;
	if(k<n+n-1||s<k){
		cout<<"No";
		return 0;
	}
	for(i=2;i<=n;i=i+1){
		a[1]=1;
		x=n-1;
		j=1;
		while(x){
			a[j+1]=min((LL)x,(LL)a[j]*i);
			x-=a[++j];
		}
		s=0;
		for(o=1;o<=j;o=o+1)
			s+=a[o]*o;
		if(s<=k){
			while(s+n<=k){
				for(o=j;o;o=o-1){
					a[o+1]=a[o];
					s+=a[o]-1;
					if(a[o]==1&&a[o-1]==1)
						break;
				}
				j++;
				while(!a[j]){
					j--;
				}
				a[j]--;
				while(!a[j]){
					j--;
				}
				/*cout<<s<<endl;
				for(o=0;o<=j;o=o+1)	
					cout<<a[o];
				cout<<endl;*/
			}
			while(s<k){
				for(o=j;o;o=o-1)
					if((LL)(a[o]-1)*i>=a[o+1]+1){
						a[o]--,a[o+1]++,s++;
						break;
					}
				while(a[j+1]){
					j++;
				}
				/*cout<<s<<endl;
				for(o=0;o<=j;o=o+1)	
					cout<<a[o];
				cout<<endl;*/
			}
			x=i;
			break;
		}
		else{
			for(o=0;o<=j+1;o=o+1)
				a[o]=0;
		}
	}
	b[1]=1;
	for(i=2;i<=n;i=i+1)
		b[i]=b[i-1]+a[i-1];
	printf("Yes\n");
	for(i=2;i<=n;i=i+1)
		for(j=0;j<a[i];j=j+1)
			printf("%d ",b[i-1]+j/x);
	return 0;
}