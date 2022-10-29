#include <iostream>
#define int long long
using namespace std;
int tree[300005],a[300005],t2[300005];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add2(int x,int y)
{
	if(x>300000) return ;
	t2[x]+=y,add2(x+lowbit(x),y);
}
inline int ask2(int x)
{
	if(!x) return 0;
	return t2[x]+ask2(x^lowbit(x));
}
inline void add(int x,int y)
{
	if(x>300000) return ;
	tree[x]+=y,add(x+lowbit(x),y);
}
inline int ask(int x)
{
	if(!x) return 0;
	return tree[x]+ask(x^lowbit(x));
}
signed main(int argc, char** argv) {
	int n,m;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		ans+=sum;
		for(int j=a[i];j<=300000;j+=a[i])
			ans-=(ask2(300000)-ask2(j-1))*a[i]; 
		ans+=(long long)a[i]*(i-1)+ask(a[i]);
		for(int j=a[i];j<=300000;j+=a[i])
			add(j,-a[i]);
		add2(a[i],1),sum+=a[i];
		cout << ans << " ";
	}
	return 0;
}