#include"bits/stdc++.h"
using namespace std;
#define gc getchar()
template<class Tp>
void gi(Tp&x){
	x=0;int f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=gc;x*=f;
}
const int N=1000005,M=10000005;
typedef long long ll;
struct node{int t,id;} c[N];
bool operator<(const node&a,const node&b){return a.t>b.t;}
int n,m,k,f[N],p[M],ans;
bool flag[N];
ll remain[M],mn;
int main(){
	
	gi(n),gi(m),gi(k);
	for(int i=1;i<=n;i++)gi(f[i]),p[f[i]]++;
	for(int i=1;i<=m;i++)gi(c[i].t),c[i].id=i;
	sort(c+1,c+m+1);
	
	for(int i=0;i<=10000000;i++){
		remain[i]=remain[i-1]+k-p[i];
		if(remain[i]<0){puts("-1");return 0;}
	}
	int l=1;mn=100000000;
	for(int i=10000000;i>=0;i--){
		mn=min(mn,remain[i]);
		if(mn==0)break;
		while(mn>0&&c[l].t==i&&l<=m){
			mn--;ans++;flag[c[l].id]=true;l++;
		}
	}
	
	cout<<ans<<endl;
	for(int i=1;i<=m;i++)if(flag[i])printf("%d ",i);
	
	return 0;
}