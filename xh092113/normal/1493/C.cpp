#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

int n,k;
int num[26],rt[26];
char s[N+5],t[N+5];

void Dec(int id){
	num[id]--;
}
In bool check(){
	int minlen = 0;
	for(rg int i = 0;i < 26;i++)minlen += (num[i]+k-1) / k * k;
	return minlen <= n;
}
In void fill(int p){
	for(rg int i = 0;i < 26;i++){
		for(rg int j = 1;j <= rt[i];j++)t[p++] = 'a' + i;
	}
}
In bool check2(int p){
//cout<<"p="<<p<<endl;
	if(s[p+1] == 'z')return 0;
	int minlen = 0;
	for(rg int i = 0;i < 26;i++){
		int cur = (num[i]+k-1) / k * k;
		rt[i] = cur - num[i];
		minlen += cur;
	}
	if(minlen > n)return 0;
//for(rg int i = 0;i < 26;i++)cout<<rt[i]<<" ";cout<<endl;
	if(minlen < n){
		int q = s[p+1] - 'a' + 1;
		if(rt[q]){while(minlen < n)minlen += k,rt[0] += k;}
		else{rt[q] = k,minlen += k;while(minlen < n)minlen += k,rt[0] += k;}
		for(rg int i = 1;i <= p;i++)t[i] = s[i];
		t[p+1] = 'a' + q,rt[q]--;
		fill(p + 2);
	}
	else{
		int q = 25;while(!rt[q])q--;
//cout<<"q="<<q<<endl;
		if(q <= (s[p+1]-'a'))return 0;
		else{
		    q = s[p+1] - 'a' + 1;
		    while(!rt[q])q++;
			for(rg int i = 1;i <= p;i++)t[i] = s[i];
			t[p+1] = 'a' + q,rt[q]--;
			fill(p + 2);
		}
	}
	return 1;
}
void solve(){
	memset(num,0,sizeof(num));
	for(rg int i = 1;i <= n;i++)num[s[i]-'a']++;
	if(check()){printf("%s\n",s + 1);return;}
	int i = n - 1;Dec(s[n] - 'a');
	while(!check2(i)){
		Dec(s[i] - 'a');
		i--;
	}
	for(rg int i = 1;i <= n;i++)putchar(t[i]);putchar('\n');
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
// MULTIPLE CASES
// TIME LIMIT
	int Tc = read();
	while(Tc--){
		n = read(),k = read();
		scanf("%s",s + 1);
		if(n % k != 0){
			puts("-1");
		}
		else solve();
	}	
	return 0;
}