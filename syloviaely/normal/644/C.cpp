#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<string,int>M;
vector<string>A[110000],ans[110000];
string fir[110000];
int a[110000],n,N;
char ch[60];
string s,t;
int compare(int k1,int k2){
	if (A[k1].size()<A[k2].size()) return 1;
	if (A[k1].size()>A[k2].size()) return 0;
	for (int i=0;i<A[k1].size();i++)
		if (A[k1][i]<A[k2][i]) return 1; else if (A[k1][i]>A[k2][i]) return 0;
	return 0;
}
void scan(){
	scanf("%s",ch+1);
	s=""; t=""; int len=strlen(ch+1);
	int num=0;
	for (int i=1;i<=len;i++){
		if (ch[i]=='/') num++;
		if (num<3) s=s+ch[i]; else t=t+ch[i];
	}
	int where=M[s];
	if (where==0) M[s]=++N,where=N;
	fir[where]=s; A[where].push_back(t);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scan();
	for (int i=1;i<=N;i++) sort(A[i].begin(),A[i].end());
	for (int i=1;i<=N;i++){
		int now=0;
		for (int j=1;j<A[i].size();j++) if (A[i][j]!=A[i][now]) now++,A[i][now]=A[i][j];
		now++;
		while (A[i].size()>now) A[i].pop_back();
	}
/*	for (int i=1;i<=N;i++){
		cout<<"fa "<<i<<" "<<fir[i]<<endl;
		for (int j=0;j<A[i].size();j++) cout<<A[i][j]<<endl;
	}*/
	for (int i=1;i<=N;i++) a[i]=i;
	sort(a+1,a+N+1,compare);
	int pre=1; int num=0;
	for (int i=2;i<=N+1;i++)
		if (i>N||compare(a[i-1],a[i])==1||compare(a[i],a[i-1])==1){
			if (i-pre>1){
				num++; for (int j=pre;j<i;j++) ans[num].push_back(fir[a[j]]);
			}
			pre=i;
		}
	printf("%d\n",num);
	for (int i=1;i<=num;i++){
		for (int j=0;j<ans[i].size();j++){
			for (int k=0;k<ans[i][j].length();k++) putchar(ans[i][j][k]);
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}