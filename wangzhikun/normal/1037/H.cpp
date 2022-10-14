#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
char st[N],qr[N],ans[N];
int n,la = 0,tot = 0,fa[2*N] = {-1},ch[2*N][26] = {0},mlen[2*N] = {0},sz[2*N];

vector<int> G[N*2];

#define mid ((l+r)/2)
int rt[N*2];
int lson[N*40] = {0},rson[N*40] = {0},trt = 0;
int mrg(int a,int b){
	if(!a || !b)return a+b;
	int cn = ++trt;
	lson[0] = rson[0] = 0;
	lson[cn] = mrg(lson[a],lson[b]);
	rson[cn] = mrg(rson[a],rson[b]);
	return cn;
}
int qry(int x,int l,int r,int cl,int cr){
	if(!x)return 0;
	if(cl<=l && r<=cr)return 1;
	if((cl<=mid && lson[x] && qry(lson[x],l,mid,cl,cr) == 1) ||
		(cr>mid && rson[x] && qry(rson[x],mid+1,r,cl,cr) == 1))
		return 1;
	return 0;
}
void opt(int x,int l,int r){
	cout<<x<<' '<<l<<' '<<r<<endl;
	if(l == r){
		cout<<"FND "<<l<<endl;
		return;
	}
	if(lson[x])opt(lson[x],l,mid);
	if(rson[x])opt(rson[x],mid+1,r);
}
void ins(int x,int l,int r,int p){
	if(l == r)return;
	if(p<=mid){
		if(!lson[x])lson[x] = ++trt;
		ins(lson[x],l,mid,p);
	}else{
		if(!rson[x])rson[x] = ++trt;
		ins(rson[x],mid+1,r,p);
	}
}
#undef mid


void inc(int x){
	int np = ++tot;mlen[np] = mlen[la]+1;sz[np] = 1;
	rt[np] = ++trt;ins(rt[np],1,n,mlen[np]);
	int cq;
	for(cq = la;cq!=-1 && !ch[cq][x];cq=fa[cq])ch[cq][x] = tot;
	if(cq == -1){
		fa[np] = 0;
	}else{
		int q = ch[cq][x];
		if(mlen[q] == mlen[cq]+1){
			fa[np] = q;
		}else{
			int nq = ++tot;mlen[nq] = mlen[cq]+1;fa[nq] = fa[q];memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[q] = nq;fa[np] = nq;
			for(int cpo = cq;cpo!=-1 && ch[cpo][x] == q;cpo = fa[cpo])ch[cpo][x] = nq;
		}
	}
	la = np;
}

void dfs(int x){
	//opt(rt[x],1,n);
	for(auto ct:G[x]){
		dfs(ct);
		rt[x] = mrg(rt[x],rt[ct]);
	}
	//opt(rt[x],1,n);
}
int m;
int l,r,ansl;

bool chk(int nod,int len){
	if(l+len-1>r)return 0;
	//cout<<"CHK "<<l+len-1<<' '<<r<<endl;
	return qry(rt[nod],1,n,l+len-1,r);
}

bool fndans(int po,int cl){
	//cout<<po<<' '<<cl<<endl;
	if(cl == m){
		for(int i=0;i<26;i++){
			if(ch[po][i] && chk(ch[po][i],cl+1)){
				ans[cl] = i+'a';
				ansl = cl+1;
				return 1;
			}
		}
		return 0;
	}
	if(ch[po][qr[cl]-'a'] && chk(ch[po][qr[cl]-'a'],cl+1) && fndans(ch[po][qr[cl]-'a'] ,cl+1)){
		ans[cl] = qr[cl];
		return 1;
	}
	//cout<<"CP"<<endl;
	for(int i = qr[cl]-'a'+1;i<26;i++){
		if(ch[po][i] && chk(ch[po][i],cl+1)){
			//opt(rt[ch[po][i]],1,n);
			//cout<<"OK"<<' '<<ch[po][i]<<' '<<i<<endl;
			ans[cl] = i+'a';
			ansl = cl+1;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%s",st);
	n = strlen(st);
	for(int i=0;i<n;i++) inc(st[i]-'a');
	for(int i=1;i<=tot;i++) G[fa[i]].push_back(i);
	dfs(0);
	int q = 0;
	cin>>q;
	while(q--){
		cin>>l>>r>>qr;
		m = strlen(qr);
		if(!fndans(0,0)){
			cout<<"-1\n";
		}else{
			for(int i=0;i<ansl;i++){
				putchar(ans[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}