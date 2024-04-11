//??CF 846E
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
const int N = 111111;
const LL inf = (LL)2e17;
LL a[N],b[N],k[N],x;
int f[N];
vector<int> v[N];
LL sa,sb;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",b+i),sb+=b[i];
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i),sa+=a[i];
	if(sb<sa){
		cout<<"NO\n";
		return 0;
	}
	f[1]=0;
	for(i=2;i<=n;i=i+1){
		scanf("%d%d",f+i,k+i);
		v[f[i]].push_back(i);
	}
	for(i=n;i>=2;i=i-1){
		if(a[i]<=b[i]){
			b[f[i]]+=(LL)b[i]-a[i];
			b[i]=a[i];
		}
		else{
			x=inf/k[i];
			if(a[i]-b[i]>x+1){
				cout<<"NO\n";
				return 0;
			}
			b[f[i]]-=(LL)k[i]*(a[i]-b[i]);
			if(b[f[i]]<-inf){
				cout<<"NO\n";
				return 0;
			}
		}
	}
	if(a[1]>b[1])
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}