#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 100007;

struct st{
	char *p;
	int len,s,h;
	friend bool operator<(st x,st y){
		return((long long)x.s*y.h>(long long)x.h*y.s);
	} 
}s[maxn];

char tmps[maxn];
int n;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%s",&tmps);
		s[i].s=s[i].h=0;
		s[i].len=strlen(tmps);
		s[i].p=new char[s[i].len];
		for (int j=0;j<s[i].len;++j){
			s[i].p[j]=tmps[j];
		}
		for (int j=0;j<s[i].len;++j){
			if(tmps[j]=='s'){
				s[i].s++;
			}
			else{
				s[i].h++;
			}
		}
	}
	sort(s,s+n);
	long long ans=0,cnt=0;
	for (int i=0;i<n;++i){
		for (int j=0;j<s[i].len;++j){
			if (s[i].p[j]=='s'){
				cnt++;
			}
			else{
				ans+=cnt;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}