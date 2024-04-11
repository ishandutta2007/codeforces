#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct atom{
	int pd,where;
	void scan(){
		char ch[10]; scanf("%s",ch+1);
		if (ch[1]=='V') pd=1; else pd=2;
		scanf("%d",&where);
	}
}A[210000];
int n,m,q;
set<int>S1,S2;
long long ans[210000];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;i++) A[i].scan();
	S1.insert(0); S1.insert(n);
	S2.insert(0); S2.insert(m);
	for (int i=1;i<=q;i++)
		if (A[i].pd==1) S1.insert(A[i].where); else S2.insert(A[i].where);
	int num1=0,num2=0;
	for (set<int>::iterator k=S1.begin();k!=S1.end();){
		int k1=(*k); k++; if (k==S1.end()) break; int k2=(*k);
		num1=max(num1,k2-k1);
	}
	for (set<int>::iterator k=S2.begin();k!=S2.end();){
		int k1=(*k); k++; if (k==S2.end()) break; int k2=(*k);
		num2=max(num2,k2-k1);
	}
	for (int i=q;i;i--){
		ans[i]=1ll*num1*num2;
		if (A[i].pd==1){
			set<int>::iterator k=S1.lower_bound(A[i].where);
			k--;
			int k1=(*(k)); k++; k++; int k2=(*k);
			num1=max(num1,k2-k1); S1.erase(A[i].where);
		} else {
			set<int>::iterator k=S2.lower_bound(A[i].where);
			k--;
			int k1=(*(k)); k++; k++; int k2=(*k);
			num2=max(num2,k2-k1); S2.erase(A[i].where);
		}
	}
	for (int i=1;i<=q;i++) printf("%I64d\n",ans[i]);
}