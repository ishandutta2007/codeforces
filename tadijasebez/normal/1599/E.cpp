#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod=1e9+7;
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
void ckadd(int&x,int y){x=add(x,y);}
int sub(int x,int y){x-=y;return x<0?x+mod:x;}
void cksub(int&x,int y){x=sub(x,y);}
int mul(int x,int y){return (ll)x*y%mod;}
void ckmul(int&x,int y){x=mul(x,y);}


struct mat2x2{
	int a00,a01,a10,a11;

	void init(){
		a00=a01=a10=a11=0;
	}

	mat2x2(){
		init();
	}

	mat2x2 operator + (mat2x2 other) const {
		mat2x2 ret;
		ret.a00=add(a00,other.a00);
		ret.a01=add(a01,other.a01);
		ret.a10=add(a10,other.a10);
		ret.a11=add(a11,other.a11);
		return ret;
	}

	mat2x2 operator * (mat2x2 other) const {
		mat2x2 ret;
		ret.a00=((ll)a00*other.a00+(ll)a01*other.a10)%mod;
		ret.a01=((ll)a00*other.a01+(ll)a01*other.a11)%mod;
		ret.a10=((ll)a10*other.a00+(ll)a11*other.a10)%mod;
		ret.a11=((ll)a10*other.a01+(ll)a11*other.a11)%mod;
		return ret;
	}
};

void operator += (mat2x2&a,mat2x2 b){
	a=a+b;
}

void operator *= (mat2x2&a,mat2x2 b){
	a=a*b;
}


mat2x2 get_id_mat(){
	mat2x2 ret=mat2x2();
	ret.a00=ret.a11=1;
	return ret;
}

mat2x2 get_f_mat(){
	mat2x2 ret;
	ret.a00=1;
	ret.a01=1;
	ret.a10=1;
	ret.a11=0;
	return ret;
}

mat2x2 get_i_f_mat(){
	mat2x2 ret;
	ret.a00=0;
	ret.a01=1;
	ret.a10=1;
	ret.a11=mod-1;
	return ret;
}


const int H=1000000;
const int STEP=1000000;

mat2x2 fib[H],rmd[STEP];
mat2x2 ifb[H],irm[STEP];

void init_fibonacci(){
	mat2x2 f=get_f_mat();
	mat2x2 i_f=get_i_f_mat();

	rmd[0]=get_id_mat();
	irm[0]=get_id_mat();

	for(int i=1;i<STEP;++i){
		rmd[i]=rmd[i-1]*f;
		irm[i]=irm[i-1]*i_f;
	}

	mat2x2 step=rmd[STEP-1]*f;
	mat2x2 istp=irm[STEP-1]*i_f;

	fib[0]=get_id_mat();
	ifb[0]=get_id_mat();

	for(int i=1;i<H;++i){
		fib[i]=fib[i-1]*step;
		ifb[i]=ifb[i-1]*istp;
	}
}

mat2x2 get_fibonacci_mat(ll k){
	if(k>=0){
		assert(k/STEP < H);
		return fib[k/STEP]*rmd[k%STEP];
	}else{
		k=-k;
		assert(k/STEP < H);
		return ifb[k/STEP]*irm[k%STEP];
	}
}


const ll inf=1e18;

const int N=100050;
const int M=2*N;


struct LazyTag{
	ll bot,top,add;

	LazyTag(){
		bot=-inf;
		top=inf;
		add=0;
	}

	LazyTag(ll a,ll b){
		bot=a;
		top=b;
		add=0;
	}

	LazyTag(ll x){
		bot=-inf;
		top=inf;
		add=x;
	}

	bool should_apply(){
		return bot!=-inf||top!=inf||add!=0;
	}

	LazyTag operator + (LazyTag other) const {
		if(other.top==other.bot){
			return other;
		}

		LazyTag ret;

		ret.add=add+other.add;
		other.top-=add;
		other.bot-=add;

		if(top==bot){
			ret.top=ret.bot=max(min(top,other.top),other.bot);
		}else{
			if(other.top<=bot){
				ret.top=ret.bot=other.top;
			}else if(other.bot>=top){
				ret.top=ret.bot=other.bot;
			}else{
				ret.top=min(top,other.top);
				ret.bot=max(bot,other.bot);
			}
		}

		return ret;
	}
};


struct LazyInfo{
	LazyTag tag[2];

	LazyInfo(){
		tag[0]=LazyTag();
		tag[1]=LazyTag();
	}

	LazyInfo(int k,ll a,ll b){
		tag[k]=LazyTag(a,b);
		tag[k^1]=LazyTag();
	}

	LazyInfo(int k,ll x){
		tag[k]=LazyTag(x);
		tag[k^1]=LazyTag();
	}

	bool should_apply(){
		return tag[0].should_apply()||tag[1].should_apply();
	}

	LazyInfo operator + (LazyInfo other) const {
		LazyInfo ret;
		ret.tag[0]=tag[0]+other.tag[0];
		ret.tag[1]=tag[1]+other.tag[1];
		return ret;
	}
};

void operator += (LazyInfo&a,LazyInfo b){
	a=a+b;
}


struct SegMaxMinInfo{
	ll mx,smx;
	ll mn,smn;

	SegMaxMinInfo(){}

	SegMaxMinInfo(ll x){
		mx=x;smx=-inf;
		mn=x;smn= inf;
	}

	int get_idx(ll x){
		if(x==mx)return 2;
		else if(x==mn)return 0;
		else return 1;
	}

	bool cut(LazyTag tag){
		if(tag.add!=0)return false;
		return mx<tag.top&&mn>tag.bot;
	}

	bool check(LazyTag tag){
		if(tag.add!=0)return true;
		if(smn==mx&&tag.top==tag.bot)return false;
		return tag.top>smx&&tag.bot<smn;
	}

	SegMaxMinInfo operator + (SegMaxMinInfo other) const {
		SegMaxMinInfo ret;

		if(mx>other.mx){
			ret.mx=mx;
			ret.smx=max(smx,other.mx);
		}else if(mx<other.mx){
			ret.mx=other.mx;
			ret.smx=max(mx,other.smx);
		}else{
			ret.mx=mx;
			ret.smx=max(smx,other.smx);
		}

		if(mn<other.mn){
			ret.mn=mn;
			ret.smn=min(smn,other.mn);
		}else if(mn>other.mn){
			ret.mn=other.mn;
			ret.smn=min(mn,other.smn);
		}else{
			ret.mn=mn;
			ret.smn=min(smn,other.smn);
		}

		return ret;
	}

	SegMaxMinInfo operator + (LazyTag tag) const {
		SegMaxMinInfo ret;
		bool two_vals=smx==mn;
		ret.smx=smx+tag.add;
		ret.smn=smn+tag.add;
		if(mx==mn){
			ret.mx=ret.mn=max(min(mx,tag.top),tag.bot)+tag.add;
		}else{
			ret.mx=min(mx,tag.top)+tag.add;
			ret.mn=max(mn,tag.bot)+tag.add;
		}
		if(two_vals){
			ret.smx=ret.mn;
			ret.smn=ret.mx;
		}
		return ret;
	}
};

void operator += (SegMaxMinInfo&info,LazyTag tag){
	info=info+tag;
}


struct SegInfo{
	SegMaxMinInfo mx_mn_info[2];
	mat2x2 sum[3][3];

	SegInfo(){}

	SegInfo(ll x,ll y){
		mx_mn_info[0]=SegMaxMinInfo(x);
		mx_mn_info[1]=SegMaxMinInfo(y);

		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				sum[i][j].init();
			}
		}

		sum[2][2]=get_fibonacci_mat(x+y);
	}

	bool cut(LazyInfo lazy){
		return mx_mn_info[0].cut(lazy.tag[0])&&mx_mn_info[1].cut(lazy.tag[1]);
	}

	bool check(LazyInfo lazy){
		return mx_mn_info[0].check(lazy.tag[0])&&mx_mn_info[1].check(lazy.tag[1]);
	}

	int get_ans(){
		int ans=0;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				ckadd(ans,sum[i][j].a10);
			}
		}
		return ans;
	}

	SegInfo operator + (SegInfo other) const {
		SegInfo ret;

		ret.mx_mn_info[0]=mx_mn_info[0]+other.mx_mn_info[0];
		ret.mx_mn_info[1]=mx_mn_info[1]+other.mx_mn_info[1];

		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				ret.sum[i][j].init();
			}
		}

		for(int i=0;i<3;++i){
			int new_i=i==1?1:ret.mx_mn_info[0].get_idx(i==0?mx_mn_info[0].mn:mx_mn_info[0].mx);
			for(int j=0;j<3;++j){
				int new_j=j==1?1:ret.mx_mn_info[1].get_idx(j==0?mx_mn_info[1].mn:mx_mn_info[1].mx);
				ret.sum[new_i][new_j]+=sum[i][j];
			}
		}

		for(int i=0;i<3;++i){
			int new_i=i==1?1:ret.mx_mn_info[0].get_idx(i==0?other.mx_mn_info[0].mn:other.mx_mn_info[0].mx);
			for(int j=0;j<3;++j){
				int new_j=j==1?1:ret.mx_mn_info[1].get_idx(j==0?other.mx_mn_info[1].mn:other.mx_mn_info[1].mx);
				ret.sum[new_i][new_j]+=other.sum[i][j];
			}
		}

		return ret;
	}

	SegInfo operator + (LazyInfo lazy) const {
		SegInfo ret;

		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				ret.sum[i][j]=sum[i][j];
			}
		}

		for(int t=0;t<2;++t){
			LazyTag tag=lazy.tag[t];

			ret.mx_mn_info[t]=mx_mn_info[t]+tag;

			ll diff_mn=ret.mx_mn_info[t].mn-mx_mn_info[t].mn;
			ll diff_mx=ret.mx_mn_info[t].mx-mx_mn_info[t].mx;

			mat2x2 mat_dmn,mat_add,mat_dmx;
			if(diff_mn!=0)mat_dmn=get_fibonacci_mat(diff_mn);
			if(tag.add!=0)mat_add=get_fibonacci_mat(tag.add);
			if(diff_mx!=0)mat_dmx=get_fibonacci_mat(diff_mx);

			for(int i=0;i<3;++i){
				if(t==0){
					if(diff_mn!=0)ret.sum[0][i]*=mat_dmn;
					if(tag.add!=0)ret.sum[1][i]*=mat_add;
					if(diff_mx!=0)ret.sum[2][i]*=mat_dmx;
				}else{
					if(diff_mn!=0)ret.sum[i][0]*=mat_dmn;
					if(tag.add!=0)ret.sum[i][1]*=mat_add;
					if(diff_mx!=0)ret.sum[i][2]*=mat_dmx;
				}
			}
		}

		return ret;
	}
};

void operator += (SegInfo&info,LazyInfo lazy){
	info=info+lazy;
}


int ls[M],rs[M],root,tsz;
SegInfo info[M];
LazyInfo lazy[M];

ll A[2][N];

void Build(int&c,int ss,int se){
	c=++tsz;
	lazy[c]=LazyInfo();
	if(ss==se){
		info[c]=SegInfo(A[0][ss],A[1][ss]);
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	info[c]=info[ls[c]]+info[rs[c]];
}

void upd(int c,LazyInfo lazy_info){
	info[c]+=lazy_info;
	lazy[c]+=lazy_info;
}

void push(int c){
	if(lazy[c].should_apply()){
		upd(ls[c],lazy[c]);
		upd(rs[c],lazy[c]);
		lazy[c]=LazyInfo();
	}
}

void Update(int c,int ss,int se,int qs,int qe,LazyInfo upd_info){
	if(qs>qe||qs>se||ss>qe||info[c].cut(upd_info))return;
	if(qs<=ss&&qe>=se&&info[c].check(upd_info)){
		upd(c,upd_info);
		return;
	}
	int mid=ss+se>>1;
	push(c);
	Update(ls[c],ss,mid,qs,qe,upd_info);
	Update(rs[c],mid+1,se,qs,qe,upd_info);
	info[c]=info[ls[c]]+info[rs[c]];
}

int Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return info[c].get_ans();
	int mid=ss+se>>1;
	push(c);
	return add(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}

int main(){
	int n,q;
	scanf("%i %i",&n,&q);

	for(int k=0;k<2;k++){
		for(int i=1;i<=n;i++){
			scanf("%lld",&A[k][i]);
		}
	}

	init_fibonacci();
	Build(root,1,n);

	for(int j=1;j<=q;j++){
		int t;
		scanf("%i",&t);
		if(t<4){
			int k,l,r,x;
			scanf("%i %i %i %i",&k,&l,&r,&x);

			k--;

			if(t<3){
				ll a,b;

				if(t==1){
					a=-inf;b=x;
				}else if(t==2){
					a=x;b=inf;
				}

				Update(root,1,n,l,r,LazyInfo(k,a,b));
			}else{
				Update(root,1,n,l,r,LazyInfo(k,x));
			}
		}else{
			int l,r;
			scanf("%i %i",&l,&r);
			printf("%i\n",Get(root,1,n,l,r));
		}
	}
	return 0;
}