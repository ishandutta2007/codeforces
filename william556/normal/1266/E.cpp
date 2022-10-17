#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,q;
int a[N],b[N];
map<int,int> mp[N];
int to[N]; 
long long ans,sum;
void upd(int x,int v){
//	cout<<"upd "<<x<<' '<<v<<endl;
	if(to[x]){
		int y=to[x];
		ans+=v*min(a[x],b[x])+v*min(a[y],b[y]);
		if(b[x]<a[x]||b[y]<a[y])ans+=v;	
	}else ans+=v*min(a[x],b[x]);
//	cout<<ans<<endl; 
}
void del(int x,int z){
	int y=mp[x][z];mp[x][z]=0;
	upd(y,-1);
	if(z==a[x]&&to[x]==y)to[x]=0,to[y]=0;
	else b[y]--;
	upd(y,1);
}
void ins(int x,int y,int z){
	mp[x][z]=y;
	upd(y,-1);
	if(z==a[x]){
		if(mp[y][a[y]]==x)to[x]=y,to[y]=x;
		b[x]--;
	}else b[y]++;
	upd(y,1);
}
int main(){
	n=in();
	for(int i=1;i<=n;i++)a[i]=in(),sum+=a[i]; 
	q=in();
	while(q--){
		int x=in(),z=in(),y=in();
		if(mp[x][z])del(x,z);
		if(z>0&&z<a[x])ins(x,y,z);
		printf("%lld\n",sum-ans);
	}
	return 0;
}