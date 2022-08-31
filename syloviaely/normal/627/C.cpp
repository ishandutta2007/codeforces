#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct atom{
	int num,w;
};
int operator < (atom k1,atom k2){
	return k1.w<k2.w;
}
set<atom>S;
int n,m,d,x[210000],p[210000],a[210000];
int compare(int k1,int k2){
	return x[k1]<x[k2];
}
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i],&p[i]);
	m++; x[m]=d;
	for (int i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+m+1,compare);
	S.insert((atom){n,0}); long long ans=0;
	for (int i=1;i<=m;i++){
		int dis=x[a[i]]-x[a[i-1]];
		if (n<dis){
			printf("-1\n"); return 0;
		}
		int ad=dis;
		for (set<atom>::iterator k=S.begin();dis;){
			int num=(*k).num;// cout<<dis<<endl;
			if (num<=dis){
				ans+=1ll*(*k).w*num; dis-=num;
				set<atom>::iterator k1=k; k++;
				S.erase(k1);
			} else {
				ans+=1ll*(*k).w*dis; atom k2=(atom){(*k).num-dis,(*k).w};
				S.erase(k); S.insert(k2);
				break;
			}
		}
	//	cout<<"asd"<<endl;
		while (1){
			set<atom>::iterator k1=S.lower_bound((atom){0,p[a[i]]});
			if (k1==S.end()) break;
			ad+=(*k1).num; S.erase(k1);
		}
	//	cout<<"asdasd"<<endl;
		if (ad) S.insert((atom){ad,p[a[i]]});
	}
	cout<<ans<<endl;
	return 0;
}