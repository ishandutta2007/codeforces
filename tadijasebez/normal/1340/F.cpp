#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int S=400;
const int H=N/S+1;
const int mod=998244353;
const int base=1e6+7;
int mul(int x,int y){return (ll)x*y%mod;}
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
int pow(int x,int k){int ans=1;for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);return ans;}
int inv(int x){return pow(x,mod-2);}
int hsh[H][S],pw[N],ipw[N],n,a[N],clssz[H],clsh[H],ok[H],opnsz[H];
int gth(int b,int l,int r){
	if(l==0)return hsh[b][r];
	return mul(sub(hsh[b][r],hsh[b][l-1]),ipw[l]);
}
void Build(int b){
	int l=max(1,b*S),r=min(n,(b+1)*S-1);
	stack<int> stk;
	clsh[b]=clssz[b]=0;
	ok[b]=1;
	for(int i=l;i<=r;i++){
		if(a[i]>0){
			stk.push(a[i]);
		}else{
			if(stk.size()){
				if(stk.top()!=-a[i])ok[b]=0;
				stk.pop();
			}else{
				clssz[b]++;
				clsh[b]=add(mul(clsh[b],base),-a[i]);
			}
		}
	}
	opnsz[b]=stk.size();
	while(stk.size())hsh[b][(int)stk.size()-1]=stk.top(),stk.pop();
	for(int i=0;i<opnsz[b];i++)hsh[b][i]=mul(hsh[b][i],pw[i]);
	for(int i=1;i<opnsz[b];i++)hsh[b][i]=add(hsh[b][i],hsh[b][i-1]);
}
struct STK{
	struct node{int b,l,r;};
	stack<node> stk;
	int ssz;
	bool ok;
	STK(){ok=1;ssz=0;}
	void add(int b,int l,int r){
		if(!ok)return;
		if(b==-1)ssz++;
		else ssz+=r-l+1;
		stk.push((node){b,l,r});
	}
	void del(int x,int h1){
		if(ssz<x)ok=0;
		if(!ok)return;
		ssz-=x;
		int h2=0;
		while(x){
			node now=stk.top();
			stk.pop();
			if(now.b==-1){
				x--;
				h2=::add(mul(h2,base),now.l);
			}else{
				int mn=min(x,now.r-now.l+1);
				h2=::add(mul(h2,pw[mn]),gth(now.b,now.r-mn+1,now.r));
				if(mn!=now.r-now.l+1)stk.push((node){now.b,now.l,now.r-mn});
				x-=mn;
			}
		}
		if(h1!=h2)ok=0;
	}
	bool CBS(){return ok&&ssz==0;}
}stk;
void AddOne(int i){stk.add(-1,a[i],-1);}
void AddBlock(int b){stk.add(b,0,opnsz[b]-1);}
void DelOne(int i){stk.del(1,-a[i]);}
void DelBlock(int b){stk.del(clssz[b],clsh[b]);}
void One(int i){a[i]>0?AddOne(i):DelOne(i);}
void Block(int b){DelBlock(b);stk.ok&=ok[b];AddBlock(b);}
int main(){
	scanf("%i %*i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=mul(pw[i-1],base);
	ipw[0]=1;ipw[1]=inv(base);for(int i=2;i<=n;i++)ipw[i]=mul(ipw[i-1],ipw[1]);
	for(int i=0;i*S<=n;i++)Build(i);
	int q;scanf("%i",&q);
	while(q--){
		int t,l,r;
		scanf("%i %i %i",&t,&l,&r);
		if(t==1)a[l]=r,Build(l/S);
		else{
			stk=STK();
			int L=l/S,R=r/S;
			if(L==R)for(int i=l;i<=r;i++)One(i);
			else{
				for(int i=l;i<(L+1)*S;i++)One(i);
				for(int i=L+1;i<R;i++)Block(i);
				for(int i=R*S;i<=r;i++)One(i);
			}
			if(stk.CBS())printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}