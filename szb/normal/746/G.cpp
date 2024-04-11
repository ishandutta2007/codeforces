#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
int a[200005],head[200005],s[200005],vis;
int n,m,t,ll;
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	a[0]=1;s[0]=1;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),s[i]=a[i]+s[i-1];
	int tt=a[m];
	for(int i=m-1;i>=1;i--)tt+=max(0,a[i]-a[i+1]);
	if(tt>t){
		cout<<-1;return 0;
	}
	tt=n-m;
	if(tt<t){
		cout<<-1;return 0;
	}
	tt=tt-t;
	printf("%d\n",n);
	for(int i=m-1;i>=1;i--){
		if(!tt){
			for(int j=s[i]+1;j<=s[i+1];j++)printf("%d %d\n",s[i-1]+1,j);
			continue;
		}
		int l=s[i-1]+1,r=s[i]+1;
		printf("%d %d\n",l,r);
		while(true){
			l++;r++;
			if(r>s[i+1])break;
			if(l>s[i]){
				l--;
				for(int j=r;j<=s[i+1];j++)printf("%d %d\n",l,j);
				break;
			}
			printf("%d %d\n",l,r);
			tt--;
			if(!tt)break;
		}
		r++;
		if(!tt)for(int j=r;j<=s[i+1];j++)printf("%d %d\n",l,j);
	}
	for(int i=2;i<=s[1];i++)printf("%d %d\n",1,i);	
}