#include<cstdio>
#include<map>
#include<set>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<long long,int> P;

const int INIT=500500;

const long long mod=1000000007;

long long rows[1100100],cols[1100100];

int l=INIT,r=INIT,u=INIT,d=INIT;

int vi,vj;

int H,W;

char ch[500500];
int ln;

void mv(int &i,int &j,char ch){
	if(ch=='R') j++;
	else if(ch=='L') j--;
	else if(ch=='U') i--;
	else i++;
}

void cleanOnce(){
	for(int i=0;i<1100100;i++){
		rows[i]=-1;
		cols[i]=-1;
	}
	int ci=INIT,cj=INIT;
	rows[ci]=0,cols[cj]=0;
	for(int id=0;id<ln;id++){
		mv(ci,cj,ch[id]);
		l=min(l,cj);
		r=max(r,cj);
		u=min(u,ci);
		d=max(d,ci);
		if(rows[ci]==-1) rows[ci]=id+1;
		if(cols[cj]==-1) cols[cj]=id+1;
	}
	vi=ci-INIT,vj=cj-INIT;
}

void cleanRepeat(){
	if(vi<0){
		for(int i=u-1;i>=d-H-5;i--){
			rows[i]=rows[i-vi]+ln;
		}
	}else if(vi>0){
		for(int i=d+1;i<=u+H+5;i++){
			rows[i]=rows[i-vi]+ln;
		}
	}
	if(vj<0){
		for(int j=l-1;j>=r-W-5;j--){
			cols[j]=cols[j-vj]+ln;
		}
	}else if(vj>0){
		for(int j=r+1;j<=l+W+5;j++){
			cols[j]=cols[j-vj]+ln;
		}
	}
}

long long fin_row[500500],fin_col[500500];

long long get(long long a,long long b){
	if(a>b) swap(a,b);
	if(a==-1) return b;
	return a;
}

void calcFinTime(){
	for(int i=0;i<H;i++){
		long long val1=rows[INIT-i-1];
		long long val2=rows[INIT+H-i];
		fin_row[i]=get(val1,val2);
	}
	for(int j=0;j<W;j++){
		long long val1=cols[INIT-j-1];
		long long val2=cols[INIT+W-j];
		fin_col[j]=get(val1,val2);
	}
}

P ps[1100100];
int remain_rows,remain_cols;

long long getSum(){
	if(vi==0&&vj==0){
		if(r-l+1<=W&&d-u+1<=H){
			return -1;
		}
	}
	int c=0;
	for(int i=0;i<H;i++){
		if(fin_row[i]!=-1) ps[c++]=P(fin_row[i],i+1);
	}
	for(int j=0;j<W;j++){
		if(fin_col[j]!=-1) ps[c++]=P(fin_col[j],-j-1);
	}
	sort(ps,ps+c);
	remain_cols=W,remain_rows=H;
	long long res=0;
	for(int i=0;i<c;i++){
		P p=ps[i];
		if(p.second>0){
			long long coe=remain_cols;
			long long val=p.first%mod;
			res+=val*coe;
			res%=mod;
			remain_rows--;
		}else{
			long long coe=remain_rows;
			long long val=p.first%mod;
			res+=val*coe;
			res%=mod;
			remain_cols--;
		}
	}
	return res;
}

void input(){
	scanf("%d%d%d",&ln,&H,&W);
	scanf("%s",ch);
}

int main(){
	input();
	cleanOnce();
	cleanRepeat();
	calcFinTime();
	long long ans=getSum();
	printf("%d\n",(int)ans);
	return 0;
}