#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define glc(u) (u << 1)
#define grc(u) ((u << 1) | 1)

const int N = 5e5;
const int TN = N << 2;
const int inf = 0x3f3f3f3f;

typedef pair<int,int> pii;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

int n,cnt;
int id[N+5],a[N+5];
pii p[N+5];

struct OrdSegTree{
	int minn[TN+5],num[TN+5],flag[TN+5];
	bool found;int i;
	In void pushup(int u){
		if(minn[glc(u)] < minn[grc(u)])minn[u] = minn[glc(u)],num[u] = num[glc(u)];
		else if(minn[glc(u)] > minn[grc(u)])minn[u] = minn[grc(u)],num[u] = num[grc(u)];
		else minn[u] = minn[glc(u)],num[u] = num[glc(u)] + num[grc(u)];
	}
	In void pushdown(int u){
		if(flag[u] == 0)return;
		flag[glc(u)] += flag[u]; minn[glc(u)] += flag[u];
		flag[grc(u)] += flag[u]; minn[grc(u)] += flag[u];
		flag[u] = 0;
	}
	void build(int u,int l,int r){
		if(l == r){
			minn[u] = inf; num[u] = 1;
			return;
		}
		int m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m + 1,r);
		pushup(u);
	}
	void assign(int u,int l,int r,int pos,int x){
		if(l == r){minn[u] = x,num[u] = 1;return;}
		pushdown(u);
		int m = (l + r) >> 1;
		if(pos <= m)assign(glc(u),l,m,pos,x);
		else assign(grc(u),m + 1,r,pos,x);
		pushup(u);
	}
	void ud(int u,int l,int r,int ql,int qr,int d){
		if(ql > qr)return;
		if(l == ql && r == qr){minn[u] += d;flag[u] += d;return;}
		pushdown(u);
		int m = (l + r) >> 1;
		if(qr <= m)ud(glc(u),l,m,ql,qr,d);
		else if(ql > m)ud(grc(u),m + 1,r,ql,qr,d);
		else ud(glc(u),l,m,ql,m,d),ud(grc(u),m + 1,r,m + 1,qr,d);
		pushup(u);
	}
	void search(int u,int l,int r){
		if(found || minn[u] > 1)return;
		if(l == r){found = 1;i = l;return;}
		pushdown(u);
		int m = (l + r) >> 1;
		if(minn[glc(u)] <= 1)search(glc(u),l,m);
		else search(grc(u),m + 1,r);
	}
	void find_first1(int u,int l,int r,int ql,int qr){
		if(ql > qr)return;
		if(ql == l && qr == r){search(u,l,r);return;}
		pushdown(u);
		int m = (l + r) >> 1;
		if(qr <= m)find_first1(glc(u),l,m,ql,qr);
		else if(ql > m)find_first1(grc(u),m + 1,r,ql,qr);
		else find_first1(glc(u),l,m,ql,m),find_first1(grc(u),m + 1,r,m + 1,qr);
	}
	int flip_first1_after(int pos){
		found = 0;i = 0;
		find_first1(1,1,n,pos + 1,n);
		if(!found){
			ud(1,1,n,pos + 1,n,-1);
			return 0;
		}
		ud(1,1,n,pos + 1,i - 1,-1);
		assign(1,1,n,i,inf);
		return i;
	}
In void print(int u,int l,int r){
	cout<<"u="<<u<<" l="<<l<<" r="<<r<<" minn="<<minn[u]<<" num="<<num[u]<<" flag="<<flag[u]<<endl;
	if(l == r)return;
	pushdown(u);
	int m = (l + r) >> 1;
	print(glc(u),l,m);
	print(grc(u),m + 1,r);
}
}Td;

struct SegTree{
	int type[TN+5],sum[TN+5][2];
	In void pushup(int u){
		sum[u][0] = sum[glc(u)][0] + sum[grc(u)][0];
		sum[u][1] = sum[glc(u)][1] + sum[grc(u)][1];
	}
	void build(int u,int l,int r){
		if(l == r){type[u] = 2;sum[u][0] = sum[u][1] = 0;return;}
		int m = (l + r) >> 1;
		build(glc(u),l,m);
		build(grc(u),m + 1,r);
		pushup(u);
	}
	void ud(int u,int l,int r,int pos,int x){
		if(l == r){
			type[u] = x;
			sum[u][0] = (type[u] == 0);
			sum[u][1] = (type[u] == 1);
			return;
		}
		int m = (l + r) >> 1;
		if(pos <= m)ud(glc(u),l,m,pos,x);
		else ud(grc(u),m + 1,r,pos,x);
		pushup(u);
	}
	void flip_first0(int u,int l,int r){ // change the first 0 to 1
		if(sum[u][0] < 1)return;
		if(l == r){
			Td.ud(1,1,n,1,l - 1,1);
			Td.assign(1,1,n,l,1);
			type[u] = 1;
			sum[u][0] = 0;
			sum[u][1] = 1;
			return;
		}
		int m = (l + r) >> 1;
		if(sum[glc(u)][0] >= 1)flip_first0(glc(u),l,m);
		else flip_first0(grc(u),m + 1,r);
		pushup(u);
	}
	void flip(int u,int l,int r){
		if(sum[u][0] < 1){
			Td.ud(1,1,n,1,n,1);
			return;
		}
		else flip_first0(u,l,r);
	}
	int getsum(int u,int l,int r,int ql,int qr){
		if(ql > qr)return 0;
		if(l == ql && r == qr)return sum[u][1];
		int m = (l + r) >> 1;
		if(qr <= m)return getsum(glc(u),l,m,ql,qr);
		else if(ql > m)return getsum(grc(u),m + 1,r,ql,qr);
		else return getsum(glc(u),l,m,ql,m) + getsum(grc(u),m + 1,r,m + 1,qr);
	}
	In int query(){
		return sum[1][1];
	}
In void print(int u,int l,int r){
cout<<"u="<<u<<" l="<<l<<" r="<<r<<" type="<<type[u]<<" sum0="<<sum[u][0]<<" sum1="<<sum[u][1]<<endl;
if(l == r)return;
int m = (l + r) >> 1;
print(glc(u),l,m);
print(grc(u),m + 1,r);
}
}T;

void solve(){
	int ans = cnt + T.query();
	write(ans),putchar('\n');
}

struct cmp{
	bool operator () (int x,int y){
		return id[x] < id[y];
	}
};

priority_queue<int,vector<int>,cmp> pq;

int main(){
//	freopen("CF773E.in","r",stdin);
//	freopen("CF773E.out","w",stdout);
	n = read();
	for(rg int i = 1;i <= n;i++){
		a[i] = read();
		p[i] = make_pair(a[i],i);
	}
	
	sort(p + 1,p + n + 1);
	for(rg int i = 1;i <= n;i++)id[p[i].second] = i;
	cnt = 0;
	T.build(1,1,n);	
	Td.build(1,1,n);
	
	for(rg int i = 1;i <= n;i++){
		if(a[i] < cnt){
			if(pq.empty()){
				pq.push(i);
				cnt--;
				T.flip(1,1,n);
			}
			else{
				int j = pq.top();
				if(cnt == a[j]){
					pq.pop();
					T.ud(1,1,n,id[j],0);		
				}
				else{
					cnt--;
					T.flip(1,1,n);
				}
				pq.push(i);
			}
		}
		else{
			int cur = cnt + T.getsum(1,1,n,1,id[i] - 1);
			if(cur == a[i]){
				T.ud(1,1,n,id[i],0);
			}
			else{
				T.ud(1,1,n,id[i],1);
				Td.assign(1,1,n,id[i],a[i] - cur);
				int pos = Td.flip_first1_after(id[i]);
				if(pos)T.ud(1,1,n,pos,0);
			}
		}
		solve();
	}
	
	return 0;
}