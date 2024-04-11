//CF 825D
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
int a[33],b[33],s[33];
char c[1111111],d[1111111];
int main()
{
	int n,m,i,j,k;
	LL p;
	k=26;
	scanf("%s",&c);
	n=strlen(c);
	for(i=0;i<n;i=i+1){
		if(c[i]=='?')
			a[0]++;
		else
			a[c[i]-'a'+1]++;
	}
	scanf("%s",&d);
	m=strlen(d);
	for(i=0;i<m;i=i+1)
		b[d[i]-'a'+1]++;
	for(i=n;i>=0;i=i-1){
		if((LL)i*m>n)
			continue;
		p=0;
		for(j=1;j<=k;j=j+1)
			p+=(LL)max(a[j],i*b[j]);
		if(p<=n)
			break;
	}
	//cout<<i<<endl;
	for(j=1;j<=k;j=j+1)
		s[j]=max(a[j],i*b[j])-a[j];
	for(i=0;i<n;i=i+1){
		if(c[i]=='?'){
			j=1;
			while(!s[j]&&j<k){
				j++;
			}
			c[i]=j+'a'-1;
			s[j]--;
		}
		printf("%c",c[i]);
	}/**/
	printf("\n");
	return 0;
}