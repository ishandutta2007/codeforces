//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int m,n,cnt[30],ccnt[30];
char s[100010];

bool ok(int mid){
	int tk = 0,l = -1,lav = 0;
	for(int i=0;i<n;i++){
		if(cnt[s[i]-'a']<=mid){
			tk+=1;l = i;
		}
		if(cnt[s[i]-'a']-ccnt[s[i]-'a']<mid && cnt[s[i]-'a']>mid)lav = i;
		if(i-l>=m){
			if(i-lav<m){
				tk+=1;
				l = lav;
			}else{
				//cout<<"NO!"<<endl;
				return 0;
			}
		}
	}
	return tk<=mid;
}

int main(){
	cin>>m>>s;
	n = strlen(s);
	for(int i=0;i<n;i++)cnt[s[i]-'a']++,ccnt[s[i]-'a']++;
	for(int i=1;i<26;i++)cnt[i]+=cnt[i-1];
	int l = 0,r = n;
	while(l+1!=r){
		int mid = (l+r)/2,cok = ok(mid);
		//cout<<mid<<' '<<cok<<endl;
		if(cok){
			r = mid;
		}else{
			l = mid;
		}
	}
	for(int i=0;i<26;i++){
		while(ccnt[i] && r){
			cout<<(char)('a'+i);
			ccnt[i]--;
			r--;
		}
	}
	cout<<endl;
	return 0;
}