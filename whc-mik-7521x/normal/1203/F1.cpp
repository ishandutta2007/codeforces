#include<bits/stdc++.h>
using namespace std;
struct node{
	int rat,inc;
}ac[305],bd[305];
bool cmp1(node q1,node q2){
	return q1.rat<q2.rat;
}
bool cmp2(node q1,node q2){
	if(q1.rat+q1.inc==q2.rat+q2.inc)return q1.rat>q2.rat;
	return q1.rat+q1.inc>q2.rat+q2.inc;
}
int n,cnt1,cnt2, r;
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		node k;
		scanf("%d%d",&k.rat,&k.inc);
		if(k.inc<0){
			bd[++cnt2]=k;
		}
		else ac[++cnt1]=k;
	}
	sort(ac+1,ac+cnt1+1,cmp1);
	sort(bd+1,bd+cnt2+1,cmp2);
	for(int i=1;i<=cnt1;i++){
		if(r<ac[i].rat){
			puts("NO");
			return 0;
		}
		r+=ac[i].inc;
	}
	for(int i=1;i<=cnt2;i++){
		if(r<bd[i].rat){
			puts("NO");
			return 0;
		}
		r+=bd[i].inc;
		if(r<0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}