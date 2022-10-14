#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int cho[1000010],clen = 0;
char s[1000010];
int main() {
	scanf("%s",s);
	int n = strlen(s);
	if(n%4 == 2)n-=1;
	int l = (n-1)/2,r = l+1;
	if(n%2 == 1){
		cho[0] = l;
		clen+=1;
		l-=1;
	}
	while(1){
		if(clen*2-n%2>=n/2)break;
		//cout<<l<<' '<<r<<endl;
		if(s[l] == s[r]){
			cho[clen] = r;
			clen+=1;
			l-=1;
			r+=1;
			continue;
		}
		if(s[l-1] == s[r]){
			cho[clen] = l-1;
			clen+=1;
			l-=2;
			r+=1;
			continue;
		}
		cho[clen] = r+1;
		clen+=1;
		l-=2;
		r+=2;
	}
	//cout<<clen<<' '<<n<<endl;
	for(int i=clen-1;i>=n%2;i--){
		cout<<s[cho[i]];
	}
	for(int i=0;i<clen;i++){
		cout<<s[cho[i]];
	}
	cout<<endl;
	return 0;
}