#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
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
int T,k,n,ok,unn;
char A[1000010],B[1000010],C[1000010],dy[200],unu[200],ody[200];
int taken[200],otaken[200];
void fill_ans(){
	unn = 0;
	cout<<"YES\n";
	for(int i='a';i<'a'+k;i++){
		//cout<<(char)i<<' '<<taken[i]<<endl;
		if(!taken[i]){
			unu[unn] = i;
			unn+=1;
		}
	}
	for(int i='a';i<'a'+k;i++){
		if(dy[i])putchar(dy[i]);
		else{
			putchar(unu[unn-1]);
			unn-=1;
		}
	}
	putchar('\n');
}
void chk_small(int sp){
	if(ok)return;
	memcpy(ody,dy,sizeof(dy));memcpy(otaken,taken,sizeof(taken));
	for(int i=sp;i<n;i++){
		if(dy[A[i]]){
			if(dy[A[i]]<C[i]){
				ok = 1;
				return;
			}
			if(dy[A[i]]>C[i]){
				memcpy(dy,ody,sizeof(ody));memcpy(taken,otaken,sizeof(otaken));
				return;
			}
		}else{
			for(int j='a';j<k+'a';j++){
				if(!taken[j] && j<C[i]){
					dy[A[i]] = j;taken[j] = 1;
					ok = 1;
					return;
				}
				if(!taken[j] && j==C[i]){
					dy[A[i]] = j;taken[j] = 1;
				}
			}
			if(!dy[A[i]]){
				memcpy(dy,ody,sizeof(ody));memcpy(taken,otaken,sizeof(otaken));
				return;
			}
		}
	}
	ok = 1;
}
void chk_large(int sp){
	if(ok)return;
	memcpy(ody,dy,sizeof(dy));memcpy(otaken,taken,sizeof(taken));
	for(int i=sp;i<n;i++){
		if(dy[A[i]]){
			if(dy[A[i]]>B[i]){
				ok = 1;
				return;
			}
			if(dy[A[i]]<B[i]){
				memcpy(dy,ody,sizeof(ody));memcpy(taken,otaken,sizeof(otaken));
				return;
			}
		}else{
			for(int j='a'+k-1;j>='a';j--){
				if(!taken[j] && j>B[i]){
					dy[A[i]] = j;taken[j] = 1;
					ok = 1;
					return;
				}
				if(!taken[j] && j==B[i]){
					dy[A[i]] = j;taken[j] = 1;
				}
			}
			if(!dy[A[i]]){
				memcpy(dy,ody,sizeof(ody));memcpy(taken,otaken,sizeof(otaken));
				return;
			}
		}
	}
	ok = 1;
}
void solve(){
	for(int i=0;i<n;i++){
		//cout<<"GO "<<i<<endl;
		int keepgoing = 0;
		for(int j='a';j<k+'a';j++){
			if(taken[j] && dy[A[i]]!=j)continue;
			if(dy[A[i]] && j!=dy[A[i]])continue;
			if(j<B[i] || j>C[i])continue;
			if(j == B[i] && j == C[i]){
				dy[A[i]] = j;taken[j] = 1;
				keepgoing = 1;
			}
			if(j>B[i] && j<C[i]){
				dy[A[i]] = j;taken[j] = 1;
				ok = 1;
				//cout<<"HO"<<endl;
				return;
			}
			if(j>B[i] && j==C[i]){
				int o1 = dy[A[i]],o2 =taken[j];
				dy[A[i]] = j;taken[j] = 1;
				chk_small(i+1);
				if(ok)return;
				dy[A[i]] = o1;taken[j] = o2;
			}
			if(j<C[i]&& j==B[i]){
				int o1 = dy[A[i]],o2 =taken[j];
				dy[A[i]] = j;taken[j] = 1;
				chk_large(i+1);
				if(ok)return;
				dy[A[i]] = o1;taken[j] = o2;
			}
		}
		if(!keepgoing)return;
	}
	ok = 1;
}
int main() {
	read(T);
	while(T--){
		ok = 0;
		set0(dy);
		set0(taken);
		read(k);
		scanf("%s%s%s",A,B,C);
		n = strlen(A);
		solve();
		if(ok)fill_ans();
		else cout<<"NO\n";
	}
	return 0;
}