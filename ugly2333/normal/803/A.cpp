//CF 803A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[111][111];
int main()
{
	int n,k,i,j;
	cin>>n>>k;
	if(n*n<k){
		cout<<-1<<endl;
		return 0;
	}
	for(i=1;i<=n&&k>0;i=i+1)
		for(j=1;j<=n&&k>0;j=j+1){
			if(a[i][j])
				continue;
			if(i==j){
				a[i][j]=1;
				k--;
			}
			else{
				if(k==1)
					k=-1;
				else
				{
					a[i][j]=1;
					a[j][i]=1;
					k-=2;
				}
			}
			//cout<<k<<endl;
		}
	if(k==-1){
		for(i=1;i<=n;i=i+1)
			if(a[i][i]==0){
				a[i][i]=1;
				break;
			}
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}