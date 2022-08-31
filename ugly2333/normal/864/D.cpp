//CF 864D
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
const int N = 222222;
int a[N],s[N],f[N];
int main()
{
	int n,i,j,ss;
	scanf("%d",&n);
	ss=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		if(!s[a[i]])
			ss++;
		s[a[i]]++;
	}
	cout<<n-ss<<endl;
	j=1;
	for(i=1;i<=n;i=i+1){
		if(s[a[i]]>1){
			while(s[j]||f[j]){
				j++;
			}
			if(j>a[i]&&!f[a[i]])
				j=a[i];
			s[a[i]]--;
			s[j]++;
			a[i]=j;
		}
		f[a[i]]=1;
		cout<<a[i]<<' ';
	}
	return 0;
}