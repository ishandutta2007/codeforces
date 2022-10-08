#include "bits/stdc++.h"
using namespace std;
const int N=100005;
char s[N];int l,cnt[N],n;
void fi(char x,int t){n=min(n,cnt[x]/t);}
int main(){
	scanf("%s",s);l=strlen(s);n=l;
	for(int i=0;i<l;i++)cnt[s[i]]++;
	fi('B',1);fi('u',2);fi('a',2);
	fi('b',1);fi('s',1);fi('r',1);
	fi('l',1);cout<<n<<endl;
	return 0;
}