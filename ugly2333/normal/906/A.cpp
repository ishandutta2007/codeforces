//CF 906A
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
int n,m,a[30],b[30];
char cc[2],ch[111111];
int main()
{
	int i,l,fl=0,s=0;
	scanf("%d",&n);
	m=26;
	for(i=1;i<=m;i=i+1)
		a[i]=1;
	while(n--){
		scanf("%s%s",cc,ch);
		l=strlen(ch);
		memset(b,0,sizeof(b));
		for(l--;l>=0;l--)
			b[ch[l]-'a'+1]++;
		if(cc[0]=='!'){
			for(i=1;i<=m;i=i+1)
				if(!b[i])
					a[i]=0;
			if(fl)
				s++;
		}
		if(cc[0]=='.'){
			for(i=1;i<=m;i=i+1)
				if(b[i])
					a[i]=0;
		}
		if(cc[0]=='?'){
			a[ch[0]-'a'+1]=0;
			if(fl&&n)
				s++;
		}
		if(fl)
			continue;
		for(i=1;i<=m;i=i+1)
			fl+=a[i];
		if(fl>1)
			fl=0;
	}
	cout<<s<<endl;
	return 0;
}