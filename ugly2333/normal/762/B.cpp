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
int u[500005],p[500005];
long long su[500005],sp[500005],ss[500005];
int main()
{
	char ch[10];
	int a,b,c,m,i,j,k,x,lu,lp,ls,ans;
	long long s;
	s=0;
	ans=0;
	lu=0;
	lp=0;
	cin>>a>>b>>c>>m;
	for(i=1;i<=m;i=i+1){
		cin>>x;
		cin>>ch;
		if(ch[0]=='U'){
			lu=lu+1;
			u[lu]=x;
		}
		else{
			lp=lp+1;
			p[lp]=x;
		}
	}
	sort(u+1,u+lu+1);
	sort(p+1,p+lp+1);
	for(i=1;i<=lu;i=i+1)
		su[i]=(long long)u[i]+su[i-1];
	for(i=1;i<=lp;i=i+1)
		sp[i]=(long long)p[i]+sp[i-1];
	ls=0;
	if(a>=lu){
		s=s+su[lu];
		ans=ans+lu;
		a=0;
	}
	else{
		s=s+su[a];
		ans=ans+a;
		for(i=a+1;i<=lu;i=i+1){
			ls++;
			ss[ls]=u[i];
		}
	}
	
	if(b>=lp){
		s=s+sp[lp];
		ans=ans+lp;
		b=0;
	}
	else{
		s=s+sp[b];
		ans=ans+b;
		for(i=b+1;i<=lp;i=i+1){
			ls++;
			ss[ls]=p[i];
		}
	}
	//cout<<ans<<endl;
	sort(ss+1,ss+ls+1);
	for(i=1;i<=min(ls,c);i=i+1){
		ans++;
		s+=(long long)ss[i];
	}
	printf("%d %I64d",ans,s);
	return 0;
}