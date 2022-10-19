#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct bit
{
	vector<ll>s;int sz;
	void bud(int SZ){sz=SZ+5;s.resize(sz);}
	void add(int x,ll y){while(x<sz){s[x]+=y;x+=(x&-x);}}
	ll que(int x){ll g=0;while(x){g+=s[x];x-=(x&-x);}return g;}
}T,t[300005];
string s;
int n,q,nw,sz[300005],fa[300005],d[300005],o[300005],tot[300005];
int main()
{
	cin>>n>>q>>s;s=' '+s;
	int nw=1,cnt=1;
	for(int i=1;i<=n;i++) 
        if(s[i]=='(')
        {
            tot[nw]++;cnt++;d[cnt]=tot[nw];
            fa[cnt]=nw;o[i]=cnt;nw=cnt;
        }
        else if(nw!=1) o[i]=nw,nw=fa[nw];
	T.bud(cnt);
	for(int i=1;i<=cnt;i++)
    {
		T.add(i,1ll*tot[i]*(tot[i]+1)/2);
		t[i].bud(tot[i]);
	}
	for(int i=cnt;i>0;i--) sz[fa[i]]=sz[fa[i]]+(++sz[i]);
	for(int i=1;i<=q;i++)
    {
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if(tp==1)
        {
			int nw=o[l];t[fa[nw]].add(d[nw],1);
			T.add(fa[nw],-tot[fa[nw]]--);
		}
        else
        {
			l=o[l];r=o[r];
			ll an=T.que(r+sz[r]-1)-T.que(l-1);
			ll re=d[r]-d[l]+1-t[fa[l]].que(d[r])+t[fa[l]].que(d[l]-1);
			an+=re*(re+1)/2;
			printf("%lld\n",an);
		}
	}
}