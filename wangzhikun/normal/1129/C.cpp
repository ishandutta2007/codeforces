#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 1000000007;
int n,all[3030],hsh1[3030],hsh2[3030],jie1 = 998244353,jie2 = 19260817,mod1 = 1e9+9,mod2 = 1e9+7;
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int sub1(int a,int b){return a<b?a-b+mod1:a-b;}
inline int add1(int a,int b){return a+b>=mod1?a+b-mod1:a+b;}
inline int mul1(int a,int b){return 1ll*a*b%mod1;}
inline int sub2(int a,int b){return a<b?a-b+mod2:a-b;}
inline int add2(int a,int b){return a+b>=mod2?a+b-mod2:a+b;}
inline int mul2(int a,int b){return 1ll*a*b%mod2;}
struct dp{
	int fr[4];
	void trans(int can[]){
		int cc = add(add(fr[0]*can[4],fr[1]*can[3]),add(fr[2]*can[2],fr[3]*can[1]));
		fr[0] = fr[1];fr[1] = fr[2];fr[2] = fr[3];fr[3] = cc;
	}
}states[3030];
const int hashmod=4000007;
struct HAsh{
    int head[9000000],next[9000000];
    ll S[9000000];
    int tot;
    int added[9000000];
    int adtot;
    void insert(ll s){
        int tmp=abs(s)%hashmod;
        if(head[tmp]==0)added[++adtot]=tmp;
        ++tot;
        S[tot]=s;
        next[tot]=head[tmp];head[tmp]=tot;
    }
    int count(ll s){
        for (int i=head[abs(s)%hashmod];i;i=next[i])if(S[i]==s)return 1;
        return 0;
    }
}Se;

int jp1[5050],jp2[5050];
bool isnstr(int l,int r){
	int chsh1 = sub1(hsh1[r],mul1(hsh1[l-1],jp1[r-l+1]));
	int chsh2 = sub2(hsh2[r],mul2(hsh2[l-1],jp2[r-l+1]));
	if(Se.count(1ll*chsh1*mod2+chsh2)){
		return false;
	}else{
		Se.insert(1ll*chsh1*mod2+chsh2);
		return true;
	}
}
int main() {
	read(n);
	states[0].fr[3] = 1;
	jp1[0] = jp2[0] = 1;
	int ans = 0;
	for(int i=1;i<5050;i++)jp1[i] = 1ll*jp1[i-1]*jie1%mod1,jp2[i] = 1ll*jp2[i-1]*jie2%mod2;
	for(int i=1;i<=n;i++){
		cin>>all[i];
		hsh1[i] = (1ll*hsh1[i-1]*jie1+all[i]+1)%mod1;
		hsh2[i] = (1ll*hsh2[i-1]*jie2+all[i]+1)%mod2;
		//cout<<i<<' '<<hsh1[i]<<' '<<hsh2[i]<<endl;
		int can[5] = {0};
		can[1] = 1;can[2] = i>=1;can[3] = i>=2;
		if(i>=3){
			int cstate = all[i-3]*8+all[i-2]*4+all[i-1]*2+all[i];
			can[4] = cstate!=3 && cstate!=5 && cstate!=14 && cstate!= 15;
		}
		//cout<<"HERE"<<endl;
		for(int j=0;j<i;j++){
			if(i-j<4){
				//cout<<"HERE"<<endl;
				for(int k=i-j+1;k<=4;k++)can[k] = 0;
				//cout<<"HERE"<<endl;
			}
			states[j].trans(can);
		}
		states[i].fr[3] = 1;
		
		for(int j=1;j<=i;j++){
			//cout<<j<<endl;
			if(isnstr(j,i)){
				//cout<<j<<' '<<i<<' '<<endl;
				ans = add(ans,states[j-1].fr[3]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}