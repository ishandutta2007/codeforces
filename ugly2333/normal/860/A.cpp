//CF 860A
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
char s[3333],x,y,z;
int a[333];
int main()
{
	a['a']=1;
	a['e']=1;
	a['i']=1;
	a['o']=1;
	a['u']=1;
	int n,i,k;
	cin>>s;
	n=strlen(s);
	k=0;
	for(i=0;i<n;i=i+1){
		if(i<2){
			cout<<s[i];
			continue;
		}
		x=s[i-2];
		y=s[i-1];
		z=s[i];
		if(a[x]||a[y]||a[z]||(x==y)&&(y==z)||i-k<2)
			cout<<z;
		else{
			cout<<' '<<z;
			k=i;
		}
	}
	cout<<endl;
	return 0;
}