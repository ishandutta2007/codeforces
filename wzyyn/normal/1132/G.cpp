#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void read(T &x) {
	x=0;T f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=f;
}
const int maxn=1000006;
int n,k,a[maxn],pre[maxn];
stack<int>s;
namespace Tnode {
	int tr[maxn<<2],tag[maxn<<2];
	inline void Pushdown(int o) {
		if(tag[o])
			tr[o<<1]+=tag[o],tag[o<<1]+=tag[o],tr[o<<1|1]+=tag[o],tag[o<<1|1]+=tag[o],tag[o]=0;
	}
	inline void Modify(int o,int l,int r,int ql,int qr) {
		if(ql<=l&&r<=qr) {
			++tr[o],++tag[o];
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid)
			Modify(o<<1,l,mid,ql,qr);
		if(qr>mid)
			Modify(o<<1|1,mid+1,r,ql,qr);
		tr[o]=max(tr[o<<1],tr[o<<1|1]);
	}
	inline int Query(int o,int l,int r,int ql,int qr) {
		if(ql<=l&&r<=qr)
			return tr[o];
		Pushdown(o);
		int mid=(l+r)>>1,ans=0;
		if(ql<=mid)
			ans=max(ans,Query(o<<1,l,mid,ql,qr));
		if(qr>mid)
			ans=max(ans,Query(o<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}
int main() {
	read(n),read(k);
	for(int i=1;i<=n;++i)
		read(a[i]);
	for(int i=n;i;--i) {
		while(s.size()&&a[s.top()]<=a[i])
			pre[s.top()]=i,s.pop();
		s.push(i);
	}
	for(int i=1;i<=n;++i) {
		Tnode::Modify(1,1,n,pre[i]+1,i);
		if(i>=k)
			printf("%d ",Tnode::Query(1,1,n,i-k+1,i));
	}
	puts("");
}