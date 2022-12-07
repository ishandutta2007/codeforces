#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,l,r,id,i,x,y;
ll nw;
ll p=1e9+7;
ll a[200005];
ll w[200005];
ll t1[200005];
ll t2[200005];
int lowbit(int x)
{
	return x&-x;
}
void ud_t1(int x,ll dt)
{
	int i;
	for(i = x;i <= n;i += lowbit(i))t1[i] += dt;
}
void ud_t2(int x,ll dt)
{
	int i;
	for(i = x;i <= n;i += lowbit(i))t2[i] += dt,t2[i] = (t2[i]%p + p)%p;
}
ll query_t1(int x)
{
	int i;
	ll ans=1ll*0;
	for(i = x;i;i -= lowbit(i))ans += t1[i];
	return ans;
}
ll query_t2(int x)
{
	int i;
	ll ans=1ll*0;
	for(i = x;i;i -= lowbit(i))ans += t2[i],ans = (ans%p + p)%p;
	return ans;
}
ll sum_t1(int l,int r)
{
	return query_t1(r)-query_t1(l-1);
}
ll sum_t2(int l,int r)
{
	return ((query_t2(r)-query_t2(l-1))%p + p)%p;
}
ll find(int L,int R)
{
	int l = L,r = R;
	int m;
	while(l < r)
	{
		m=(l + r) >> 1;
		if(sum_t1(L,m) >= sum_t1(m+1,R))r=m;
		else l=m+1;
	}
	return l;
}
int main()
{
//	freopen("1030F.in","r",stdin);
//  	freopen("1030F.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i = 1;i <= n;i++)scanf("%lld",&a[i]);
	for(i = 1;i <= n;i++)scanf("%lld",&w[i]);
	for(i = 1;i <= n;i++)ud_t1(i,w[i]),ud_t2(i,1ll*w[i]*(a[i]-i)%p);
	ll loc;
	ll ans;
//cout<<"t1 ";for(i=1;i<=n;i++)cout<<query_t1(i)<<" ";cout<<endl;
//cout<<"t2 ";for(i=1;i<=n;i++)cout<<query_t2(i)<<" ";cout<<endl;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x<0)
		{
			id = -x,nw = 1ll*y;
			ll dt1 = nw - w[id];
			w[id] = nw;
//cout<<"dt1 "<<dt1<<endl;
			ud_t1(id,dt1);
			ll dt2 = 1ll * dt1 * (a[id] - id) % p;
//cout<<"dt2 "<<dt2<<endl;
			ud_t2(id,dt2);
//cout<<"t1 ";for(i=1;i<=n;i++)cout<<query_t1(i)<<" ";cout<<endl;
//cout<<"t2 ";for(i=1;i<=n;i++)cout<<query_t2(i)<<" ";cout<<endl;
		}
		else
		{
			l = x,r = y;
			loc=find(l,r);
//cout<<"l:"<<l<<" r:"<<r<<" loc:"<<loc<<endl;
			ans = 1ll*(a[loc]-loc)%p*(sum_t1(l,loc-1)%p)%p; //cout<<ans<<endl;
			ans -= 1ll*((sum_t2(l,loc-1)%p + p)%p); ans%=p; //cout<<ans<<endl;
			ans += 1ll*((sum_t2(loc+1,r)%p + p)%p); ans%=p; //cout<<ans<<endl;
			ans -= 1ll*(a[loc]-loc)%p*(sum_t1(loc+1,r)%p)%p; //cout<<ans<<endl;
			ans = (ans%p + p)%p;
			printf("%lld\n",ans);
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}