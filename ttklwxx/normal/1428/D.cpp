#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],ans,nw;
stack<pair<ll,ll> >c1,c2,qaq,c3;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main(){
	n=read();nw=n;
	for(ll i=1;i<=n;i++)a[i]=read();
	for(ll i=n;i>0;i--){
		if(a[i]==0) continue;
		if(a[i]==1)
		{
			c1.push(make_pair(nw,i));
			qaq.push(make_pair(nw,i));
			ans++;nw--;
		}
		if(a[i]==2){
			if(c1.empty())
			{
				puts("-1");
				return 0;
			}
			pair<ll,ll>x=c1.top();
			c1.pop();
			c2.push(make_pair(x.first,i));
			qaq.push(make_pair(x.first,i));
			ans++;
		}
		if(a[i]==3)
		{
			if(c1.empty()&&c2.empty()&&c3.empty())
			{
				puts("-1");
				return 0;
			}
			if(!c3.empty()){
				pair<ll,ll>x=c3.top();
				c3.pop();
				ans+=2;
				c3.push(make_pair(nw,i));
				qaq.push(make_pair(nw,i));
				qaq.push(make_pair(nw,x.second));
				nw--;
				continue;
			}
			if(!c2.empty())
			{
				pair<ll,ll> x=c2.top();
				c2.pop();
				ans+=2;
				c3.push(make_pair(nw,i));
				qaq.push(make_pair(nw,i));
				qaq.push(make_pair(nw,x.second));
				nw--;
				continue;
			}
			pair<ll,ll> x=c1.top();
			c1.pop();
			ans+=2;
			c3.push(make_pair(nw,i));
			qaq.push(make_pair(nw,i));
			qaq.push(make_pair(nw,x.second));
			nw--;
			continue;
		}
	}
	printf("%lld\n",ans);
	while(!qaq.empty())
	{
		pair<ll,ll> x=qaq.top();
		qaq.pop();
		printf("%lld %lld\n",x.first,x.second);
	}
	return 0;
}