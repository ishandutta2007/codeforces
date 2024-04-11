#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1000005;
int n;
char s[N];
void sol0(){
	puts("0 0");
	exit(0);
}
void sol1(){
	int pos=-1;
	rep(i,1,n)if(s[i]=='D'){pos=i;break;}
	int cnt=0,fir=0;
	rep(i,1,pos-1){
		if(s[i]=='B'){
			++cnt;
			if(!fir)fir=i;
		}
	}
	int tot=0,lst=0;
	per(i,n,pos+1){
		if(s[i]=='B'){
			++tot;
			if(!lst)lst=i;
		}
	}
	if(cnt>tot){
		printf("%d %d\n",cnt,pos-fir);
	}else{
		if(tot==0){
			puts("0 0");
		}else if(cnt==tot){
			printf("%d %d\n",cnt,min(pos-fir,lst-pos));
		}else{
			printf("%d %d\n",tot,lst-pos);
		}
	}
	exit(0);
}
const int INF=0X3F3F3F3F;
int st[N],pos[N],nxt[N],pre[N],f[N],go[N];
void sol2(){
	printf("%d ",(int)count(s+1,s+1+n,'B'));
	int l=0,r=n,ans=INF;
	int top=0,len=0;
	rep(i,1,n){
		if(s[i]=='D')st[++top]=i,pre[i]=pos[len];
		else if(s[i]=='B')pos[++len]=i;
	}
	int tmp=n+1;
	per(i,n,1){
		if(s[i]=='D')nxt[i]=tmp;
		else if(s[i]=='B')tmp=i;
	}
	auto chk=[&](int mid)->bool{
		rep(i,0,top)f[i]=-INF;
		go[0]=1;
		rep(i,1,top){
			f[i]=max(f[i-1],f[i]);
			if(pre[st[i]]==0||pre[st[i]]<st[i-1]||f[i-1]+mid>=pre[st[i]]){
				f[i]=st[i];
			}else{
				int j=go[i-1];
				if(j<=len&&st[i]-pos[j]>mid)return 0;
				if(i>=2){
					j=go[i-2];
					if(j>len||st[i]-pos[j]<=mid){
						f[i]=st[i-1];
					}
				}
			}
			go[i]=go[i-1];
			while(go[i]<=len&&pos[go[i]]<=max(st[i],f[i]+mid))++go[i];
		}
		return max(st[top],f[top]+mid)>=pos[len];
	};
	while(l<=r){
		int mid=(l+r)>>1;
		//D("chk(%d)=%d\n",mid,chk(mid));
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	exit(0);
}
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n){
		if(s[i]=='*')s[i]='B';
		else if(s[i]=='P')s[i]='D';
	}
	int cntD=count(s+1,s+1+n,'D');
	if(cntD==0)sol0();
	else if(cntD==1)sol1();
	else sol2();
	return 0;
}