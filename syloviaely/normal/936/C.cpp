#include <bits/stdc++.h>
using namespace std;
char s[6000],t[6000],bo[6000];
int n,A[30],flag,l,r;
vector<int>way;
void get(int L){
	if (L==0) return; way.push_back(L); int len=0;
	for (int i=1;i<=L;i++) bo[++len]=s[n-i+1];
	for (int i=1;i<=n-L;i++) bo[++len]=s[i];
	for (int i=1;i<=n;i++) s[i]=bo[i];
}
int main(){
	scanf("%d",&n); scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n;i++) A[s[i]-'a']++;
	for (int i=1;i<=n;i++){
		A[t[i]-'a']--;
		if (A[t[i]-'a']<0){
			printf("-1\n"); return 0;
		}
	}
	for (int i=1;i<=n;i++) t[i+n]=t[i];
	flag=0; l=n+1; r=n;
	for (int tt=1;tt<=n;tt++){
		int ne;
		if (flag==0){
			l--; ne=t[l];
		} else if (flag==1){
			r++; ne=t[r];
		}
		flag^=1;
		int where=0;
		for (int i=tt;i<=n;i++) if (s[i]==ne) where=i;
	//	cout<<ne<<" "<<where<<endl;
		get(n-where+1);
		//cout<<s+1<<endl;
		get(where-tt);
	//	cout<<s+1<<endl;
		get(tt);
	//	cout<<l<<" "<<r<<" "<<flag<<endl;
		//cout<<s+1<<endl;
	}
	if (flag) get(n);
	get(r-n); get(n-l+1); get(n);
	printf("%d\n",(int)(way.size()));
	for (int i=0;i<way.size();i++) printf("%d ",way[i]);
	//cout<<s+1<<" "<<t+1<<endl; 
}