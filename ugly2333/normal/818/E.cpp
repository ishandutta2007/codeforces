// CF 818E
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
int a[111111],f[111111],c[1111],h[1111];
int main()
{
	int n,k,i,j,s,x,p,t;
	LL ans;
	scanf("%d%d",&n,&k);
	s=0;
	x=k;
	for(i=2;i*i<=x;i=i+1){
		if(x%i==0){
			s++;
			c[s]=i;
		}
		while(x%i==0){
			h[s]++;
			x/=i;
		}
	}
	if(x>1){
		s++;
		c[s]=x;
		h[s]=1;
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		f[i]=i;
	}
	for(i=1;i<=s;i=i+1)
	{
		x=0;
		p=1;
		j=0;
		while(j<=n&&f[p]!=-1){
			if(h[i]>x||j<p){
				j++;
				t=a[j];
				while(t%c[i]==0&&t>1){
					x++;
					t/=c[i];
				}
			}
			else{
				if(f[p]==-1)
					break;
				f[p]=max(f[p],j);
				t=a[p];
				while(t%c[i]==0&&t>1){
					x--;
					t/=c[i];
				}
				p++;
			}
		}
		while(p<=n){
			f[p]=-1;
			p++;
		}
	}
	ans=0;
	for(i=1;i<=n;i=i+1){
		if(f[i]!=-1)
			ans+=(LL)n-f[i]+1;
	}
	cout<<ans<<endl;
	return 0;
}