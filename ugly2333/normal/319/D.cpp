//CF 319D
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
typedef long long LL;
typedef double DB;
const int N = 55555;
char ch[N];
int n,a[N],b[N];
int main()
{
	int i,j,k;
	cin>>ch;
	n=strlen(ch);
	for(i=0;i<n;i=i+1)
		a[i]=ch[i]-'a';
	for(i=1;i+i<=n;i=i+1){
		k=-1;
		for(j=0;j+i<n;j=j+1){
			if(a[j]==a[j+i]){
				if(k<0)
					k=j+i-1;
				if(k==j){
					while(k>j-i){
						a[k]=-1;
						k--;
					}
					k=-1;
				}
			}
			else
				k=-1;
		}
		for(j=0,k=0;j<n;j=j+1){
			if(a[j]>=0){
				a[k]=a[j];
				k++;
			}
		}
		n=k;
	}
	for(i=0;i<n;i=i+1)
		cout<<(char)(a[i]+'a');
	return 0;
}