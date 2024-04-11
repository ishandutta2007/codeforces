#include <bits/stdc++.h>

typedef std::pair<int,int> ip;
struct iip:public ip{
	char ch;
};
int n,m,k=26,cnt=0;
char s[1100000],t[1100000];
iip a[26];

bool cmp(const iip &a,const iip &b) {
	if(a.second==b.second) {
		return a.first<b.first;
	}
	else if(a.second==0) return true;
	else if(b.second==0) return false;
	else return a.first/a.second<b.first/b.second;
}
int F(int idx,int ne,int num) {
	if(idx==k) return cnt/ne;
	int val=0,next=0,i;
	for(i=idx;i<k&&a[i].first/a[i].second<=a[idx].first/a[idx].second;i++) {
		val+=a[i].second-(a[i].first%a[i].second);
		next+=a[i].second;
	}
	int dif=(a[idx].first/a[idx].second+1)-num;
	if(ne*dif+val<=cnt) {
		cnt-=ne*dif+val;
		return dif+F(i,ne+next,dif+num);
	}
	else return (ne!=0)?cnt/ne:0;
}
int main() {
	scanf("%s%s",s,t);
	n=strlen(s);
	m=strlen(t);
	for(int i=0;i<n;i++){
		if(s[i]=='?') cnt++;
		else a[s[i]-'a'].first++;
	}
	for(int i=0;i<m;i++) {
		a[t[i]-'a'].second++;
	}
	for(int i=0;i<k;i++) a[i].ch=i+'a';
	std::sort(a,a+k,cmp);
	int st=0;
	while(st<k&&a[st].second==0) st++;
	int val=F(st,0,0),i=st;
	for(int j=0;j<n;j++) {
		while(i<k&&a[i].first/a[i].second>=val) i++;
		if(s[j]!='?') continue;
		if(i<k)s[j]=a[i].ch;
		else s[j]='a';
		a[i].first++;
	}
	printf("%s\n",s);

	return 0;
}