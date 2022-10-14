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
char s[500050],t[500050],ans[500050];
int f[500050];
int main() {
	cin>>s>>t;
	int j,n = strlen(s),m = strlen(t);
	int cnt[2] = {0};
	for(int i=0;i<n;i++){
		cnt[s[i]-'0']+=1;
	}
    for(int i=1;i<m;i++){
        j = f[i];
        while(j && t[i]!=t[j]) j = f[j];
        f[i+1] = (t[i] == t[j]) ? j+1 : 0;
    }
    int cp = 0;
    //cout<<n<<endl;
   // cout<<f[m]<<endl;
    for(int i=0;i<n;i++){
		if(cnt[t[cp]-'0']){
			s[i] = t[cp];
			cnt[t[cp]-'0']-=1;
			cp+=1;
			if(cp == m)cp = f[m];
		}else{
			if(cnt[0]){
				s[i] ='0';cnt[0]--;
			}
			if(cnt[1]){
				s[i] ='1';cnt[1]--;
			}
		}
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}