#include<bits/stdc++.h>
using namespace std;
const int D=1e5;
const int max_V=1e5+5;
int cnt[max_V<<1],mem[20][max_V<<1],ans_k=20;
vector<int> now,ans;
void dfs(int x,int V,int tot)
{
	if(tot>=ans_k)
		return;
	int V_new=0;
	bool odd_exist=false;
	for(int i=-V;i<=V;++i)
	{
		if(cnt[i+D])
		{
			V_new=max(V_new,max(i,-i));
			odd_exist|=i&1;
		}
	}
	V=V_new;
	if(!V)
	{
		ans=now;
		ans_k=tot;
		return;
	}
	if(x>=18)
		return;
	for(int i=-V+D;i<=V+D;++i)
		mem[x][i]=cnt[i];
	if(odd_exist)
	{
		now.push_back(1<<x);
		for(int i=-V;i<=V;++i)
		{
			int old=2*i+1;
			if(old>=-V&&old<=V)
				cnt[i+D]=mem[x][old+D]; 
			else
				cnt[i+D]=0;
			old=2*i;
			if(old>=-V&&old<=V)
				cnt[i+D]+=mem[x][old+D];
		}
		dfs(x+1,V,tot+1);
		now.pop_back();
		now.push_back(-(1<<x));
		for(int i=-V;i<=V;++i)
		{
			int old=2*i-1;
			if(old>=-V&&old<=V)
				cnt[i+D]=mem[x][old+D]; 
			else
				cnt[i+D]=0;
			old=2*i;
			if(old>=-V&&old<=V)
				cnt[i+D]+=mem[x][old+D];
		}
		dfs(x+1,V,tot+1);
		now.pop_back();
		for(int i=-V+D;i<=V+D;++i)
			cnt[i]=mem[x][i];
	}
	else
	{
		for(int i=1;i<=V/2;++i)
			cnt[i+D]=cnt[2*i+D],cnt[-i+D]=cnt[-2*i+D];
		dfs(x+1,V>>1,tot);
		for(int i=-(V/2)+D;i<=V/2+D;++i)
			cnt[i]=mem[x][i];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		++cnt[a+D];
	}
	dfs(0,1e5,0);
	assert((int)ans.size()==ans_k);
	printf("%d\n",ans_k);
	for(int i=0;i<ans_k;++i)
		printf("%d%c",ans[i]," \n"[i+1==ans_k]);
	return 0;
}