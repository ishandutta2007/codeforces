#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N],v[N],m;
char s[N];
int now[N];
struct node{
	pair<int,int>p;
	int num;
	bool operator<(const node b)const{
		return p<b.p;
	}
};
int main(){
	scanf("%d\n%s",&n,s);
	for(int i=0;i<1<<n;i++)a[i]=i;
	stable_sort(a,a+(1<<n),[](int i,int o){return s[i]<s[o];});
	for(int o=1;o<1<<n;o++){
		v[a[o]]=v[a[o-1]]+(s[a[o]]!=s[a[o-1]]?1:0);
	}
	for(int i=0;i<n;i++){
		auto cmp=[&](int k,int j){return v[k]==v[j]?v[k^(1<<i)]<v[j^(1<<i)]:v[k]<v[j];};
		sort(a,a+(1<<n),cmp);
		for(int o=1;o<1<<n;o++){
			now[a[o]]=now[a[o-1]]+(cmp(a[o-1],a[o])?1:0);
		}
		copy(now,now+(1<<n),v);
	}
    for(int i=0;i<1<<n;i++)printf("%c",s[i^a[0]]);
	return 0;
}